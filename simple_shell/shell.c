#include "shell.h"

int main(int ac, char *av[], char *envp[])
{
	char *line_buff = NULL;
	size_t buff_size = 0;
	size_t buff_out_len;
	char *prompt = "Shell$ ";
	
	while (true)
	{
		if(isatty(STDIN_FILENO))
		{
			printf("%s", prompt);
			fflush(stdout);
		}
		line_buff = malloc(BUFFER);
        if (line_buff == NULL)
		{
			perror("malloc");
			exit(1);
		}
		/*Gets the number of byte if input string*/
		buff_out_len = _getline(&line_buff);
		/*Checks if the getline function fails*/
		if (buff_out_len == EOF)
		{
    		free(line_buff);
    		break;
		}
		if (buff_out_len == -1)
		{
			perror("getline");
			free(line_buff);
			exit(1);
		}
		/*Ensures process is stopped when exit or quit is encountered*/
		if (strcmp(line_buff, "exit") == 0)
			break;
		else if (strcmp(line_buff, "env") == 0)
			env(envp);

		exe_comd(line_buff, av);
	}
	return (0);
}

char *location(char *path, char *arg)
{
	char *path_cpy;
	char *path_token;
	char *filepath;
	char *delim = ":";

	path_cpy = strdup(path);

	path_token = strtok(path_cpy, delim);

	filepath = malloc(strlen(arg) + strlen(path_token) + 2);

	while (path_token != NULL)
	{
		strcpy(filepath, path_token);
		strcat(filepath, "/");
		strcat(filepath, arg);
		strcat(filepath, "\0");

		if(access(filepath, X_OK) == 0)
		{
			free(path_cpy);
			return(filepath);
		}
		path_token = strtok(NULL, delim);
	}
	free(filepath);
	free(path_cpy);
	return (NULL);
}
	
char *get_loc(char *arg)
{
	char *path;
	if (arg[0] == '/')
    {
		path = strdup(arg);
    	if (access(path, X_OK) == 0)
			return path;
		else
		{
			free(path);
			return NULL;
		}
    }
	path = _getenv("PATH");

	if (path)
	{
		path = location(path, arg);
		return (path);
	}
	return (NULL);

}

int exe_comd(char *input, char *av[]) {
    pid_t c_pid;
    int status, i = 0;
    char **commands = parse_commands(input);

    while (commands[i] != NULL) {
        char *command = commands[i];
        char *argv[100];
        int j = 0;

        char *tok_str = strtok(command, " ");
        while (tok_str != NULL) {
            argv[j++] = tok_str;
            tok_str = strtok(NULL, " ");
        }
        argv[j] = NULL;

        if (strcmp(argv[0], "exit") == 0 && argv[1] != NULL) {
            int exit_s = atoi(argv[1]);
            exit(exit_s);
        } else if (exec_env(argv) == 0) {
            i++;
            continue;
        } else if (strcmp(argv[0], "cd") == 0) {
            change_d(argv[1]);
            i++;
            continue;
        }

        char *path = get_loc(argv[0]);

        if (path != NULL) {
            c_pid = fork();
            if (c_pid == -1) {
                perror("fork");
                free(input);
                exit(1);
            }

            if (c_pid == 0) {
                // Child process
                if (execve(path, argv, NULL) == -1) {
                    perror(av[0]);
                    exit(1);
                }
            } else {
                // Parent process
                wait(&status);
                free(path);
            }
        } else {
            perror(av[0]);
        }

        i++;
    }
	free(commands);
	return (0);
}

int env(char *envp[])
{
	unsigned int i;
	i = 0;

	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}

ssize_t _getline(char **line_buff)
{
	static ssize_t buff_size = 0;
	static char buff[BUFFER];
	ssize_t line_len = 0;
	size_t i;

	if (buff_size <= 0 || buff[buff_size - 1] == '\0')
	{
		buff_size = read(STDIN_FILENO, buff, BUFFER);
		if (buff_size < 0)
			return (buff_size);
		else if (buff_size == 0)
			return (EOF);
	}
	while (buff_size > 0 && buff[line_len] != '\n')
		line_len++;

	*line_buff = malloc(line_len + 1);
	if (*line_buff == NULL)
    {
        perror("malloc");
        exit(1);
    }
	for (i = 0; i < line_len; i++)
		(*line_buff)[i] = buff[i];
	(*line_buff)[line_len] = '\0';

	buff_size -= (line_len + 1);
    for (i = 0; i < buff_size; i++)
    {
        buff[i] = buff[line_len + i];
    }
	return (line_len);
}

char *my_strtoken(char *string, const char *target)
{
	static char *n_token;
	size_t i;
	size_t target_len;
	char *token;
	char *targ_pos;

	if (string != NULL)
		n_token = string;

	if (n_token == NULL || *n_token == '\0')
		return (NULL);

	target_len = strlen(target);
	token = n_token;
	targ_pos = NULL;

	while (*n_token != '\0')
	{
		for (i = 0; i < target_len; i++)
		{
			if (*n_token == target[i])
			{
				targ_pos = n_token;
				break;
			}
		}
		if (targ_pos != NULL)
		{
			*targ_pos = '\0';
			n_token = targ_pos + 1;
			return (token);
		}
		n_token++;
	}
	n_token	= NULL;
	return token;
}

int exec_env(char *argv[])
{
	char *b_msg;
	if (strcmp(argv[0], "setenv") == 0)
	{
        if (argv[1] != NULL && argv[2] != NULL)
		{
            if (_setenv(argv[1], argv[2], 1) == -1)
			{
                b_msg = "setenv: Error establishing environment variable\n";
                write(2, b_msg, strlen(b_msg));
            }
			return (0);
        }
		else 
		{
            b_msg = "Usage: setenv VARIABLE VALUE\n";
            write(2, b_msg, strlen(b_msg));
			return (0);
        }
    }
	else if (strcmp(argv[0], "unsetenv") == 0)
	{
        if (argv[1] != NULL)
		{
            if (_unsetenv(argv[1]) == -1)
			{
                b_msg = "unsetenv: Error establisng environment variable\n";
                write(2, b_msg, strlen(b_msg));
            }
			return (0);
        }
		else
		{
            b_msg = "unsetenv: Usage: unsetenv VARIABLE\n";
            write(2, b_msg, strlen(b_msg));
			return (0);
        }
	}
}

char *_getenv(const char *name)
{
	int i;
	char *env;

	if (name == NULL || environ == NULL)
		return NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		env = environ[i];
		if (strncmp(env, name, strlen(name)) == 0 && env[strlen(name)] == '=')
			return (env + strlen(name) + 1);
	}
	return (NULL);
}

void change_d(char *d)
{
	char *directory;
	char cdd[BUFFER];	

	if (d == NULL)
	{
		directory = _getenv("HOME");
	}
	else if (strcmp (d, "-") == 0)
	{
		directory = _getenv("OLDPWD");
	}
	else
		directory = d;
	
	if (chdir(directory) != 0)
	{
		perror("chdir");
		exit(1);
	}
	else
	{
		if (getcwd(cdd, sizeof(cdd)) == NULL)
        {
            perror("getcwd");
			exit(1);
        }
		_setenv("PWD", cdd, 1);
		_setenv("OLDPWD", _getenv("OLDPWD"), 1);
	}

}
int _setenv(const char *name, const char *value, int overwrite)
{
	size_t name_len, value_len, env_len, i;
	char *new_env;
	int env_index;

	if (name == NULL || name[0] == '\0')
		return (-1);

	name_len = strlen(name);
	value_len = (value != NULL) ? strlen(value) : 0;
	env_len = name_len + value_len + 2;

	new_env = malloc(env_len);
	if (new_env == NULL)
		return (-1);

	for (i = 0; i < name_len; i++)
		new_env[i] = name[i];

	new_env[name_len] = '=';
	for (i = 0; i < value_len; i++)
		new_env[name_len + 1 + i] = value[i];

	new_env[env_len - 1] = '\0';
	
	env_index = 0;
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0)
		{
			env_index = i;
			break;
		}
	}

	if (env_index != 0)
	{
		if (overwrite)
		{
			environ[env_index] = new_env;
		}
		else
			free(new_env);
	}
	else
	{
		for (i = 0; ; i++)
		{
			if (environ[i] == NULL)
			{
				environ[i] = new_env;
				environ[i + 1] = NULL;
				break;
			}
		}
	}
	return (0);
}
int _unsetenv(const char *name)
{
	int env_index;
	size_t name_len;
	int i;

	if (name == NULL || name[0] == '\0')
		return (-1);
	
	env_index = 0;
	name_len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0)
		{
			env_index = i;
			break;
		}
	}
	if (env_index != 0)
	{	
		for (i = env_index; environ[i] != NULL; i++)
			environ[i] = environ[i + 1];
		return (0);
	}
	return (-1);
}

char **parse_commands(char *input) {
    int i = 0;
    char *tok_str;
    char **commands = malloc(sizeof(char *) * 100);

    if (commands == NULL) {
        perror("malloc");
        exit(1);
    }

    tok_str = strtok(input, ";");
    while (tok_str != NULL) {
        commands[i++] = strdup(tok_str);
        tok_str = strtok(NULL, ";");
    }

    commands[i] = NULL;

    return commands;
}

void free_commands(char **commands) {
    int i = 0;
    
    while (commands[i] != NULL) {
        free(commands[i]);
        i++;
    }

    free(commands);
}

