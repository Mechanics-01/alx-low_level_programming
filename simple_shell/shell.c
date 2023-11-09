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
		if (buff_out_len == -1)
		{
			if (buff_out_len == EOF)
				printf("\n");
			else
				perror("getline");
			free(line_buff);
			exit(1);
		}
		printf("%s\n", line_buff);
		/*Ensures process is stopped when exit or quit is encountered*/
		if (strcmp(line_buff, "quit") == 0 || strcmp(line_buff, "exit") == 0)
    	{
            break;
    	}

		else if (strcmp(line_buff, "env") == 0)
			env(envp);

		exe_comd(line_buff, av);
	}
	free(line_buff);
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
	int status, i = 0;
	char *argv[100];
	char *tok_str;
	char *path;

	tok_str = strtok(input, " ");
	while (tok_str != NULL)
	{
		argv[i++] = tok_str;
		tok_str = strtok(NULL, " ");
	}
	argv[i] = NULL;

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
				free(input);
				exit(1);
			}
			free(path);
		}
		else
			wait(&status);
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

size_t _getline(char **line_buff)
{
	static size_t buff_size = 0;
	static char buff[BUFFER];
	size_t line_len = 0;
	size_t i;

	if (buff_size == 0 || buff[buff_size - 1] == '\0')
	{
		buff_size = read(STDIN_FILENO, buff, BUFFER);
		if (buff_size <= 0)
			return (buff_size);
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
        buff[i] = buff[line_len + 1 + i];
    }

	return (line_len);
}
