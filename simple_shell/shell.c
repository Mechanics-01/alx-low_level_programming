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
			printf("%s", prompt);
		/*Gets the number of byte if input string*/
		buff_out_len = getline(&line_buff, &buff_size, stdin);
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
		/*Checks for newline character and removes it*/
		line_buff[buff_out_len - 1] = '\0';
		/*Ensures process is stopped when exit or quit is encountered*/
		if (strcmp(line_buff, "quit") == 0 || strcmp(line_buff, "exit") == 0)
    	{
            free (line_buff);
            break;
    	}
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