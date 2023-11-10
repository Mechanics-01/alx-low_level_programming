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
		if (strcmp(line_buff, "env") == 0)
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

	path_token = my_strtoken(path_cpy, delim);

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
		path_token = my_strtoken(NULL, delim);
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
	path = getenv("PATH");

	if (path)
	{
		path = location(path, arg);
		return (path);
	}
	return (NULL);

}

void exe_comd(char *input, char *av[])
{
	pid_t c_pid;
	int status, i = 0, exit_s;
	char *argv[100];
	char *tok_str;
	char *path;

	tok_str = my_strtoken(input, " ");
	while (tok_str != NULL)
	{
		argv[i++] = tok_str;
		tok_str = my_strtoken(NULL, " ");
	}
	argv[i] = NULL;
	if (strcmp(argv[0], "exit") == 0 && argv[1] != NULL)
    {
        exit_s = atoi(argv[1]);
        free(input);
        free(tok_str);
        exit(exit_s);
    }

	path = get_loc(argv[0]);

	if (path != NULL)
	{
		c_pid = fork();
		if (c_pid == -1)
		{
			perror("fork");
			free(input);
			exit(1);
		}
		/*If fork is successful tokenise the string input*/
		if (c_pid == 0)
		{
			if (execve(path, argv, NULL) == -1)
			{
				perror(av[0]);
				exit(1);
			}
		}
		else
		{
			wait(&status);
			free(path);
			free(input);
		}
	}
	else
		perror(av[0]);
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