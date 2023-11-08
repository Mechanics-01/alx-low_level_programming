#include "shell.h"

int main(int ac, char *av[], char *envp[])
{
	char *line_buff = NULL;
	size_t buff_size = 0;
	size_t buff_out_len;
	char *prompt = "Shell$ ";
	
	while (true)
	{
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
	return (0);
}

void exe_comd(char *input, char *av[])
{
	pid_t c_pid;
	int status, i = 0;
	char *argv[100];
	char *tok_str;
	
	/*Create a child process*/
	c_pid = fork();

	/*Checks if the formation of the process fails*/
	if (c_pid == -1)
	{
		perror("fork");
		free(input);
		exit(1);
	}
	/*If fork is successful tokenise the string input*/
	if (c_pid == 0)
	{
		tok_str = strtok(input, " ");
		while (tok_str != NULL)
		{
			argv[i++] = tok_str;
			tok_str = strtok(NULL, " ");
		}
		argv[i] = NULL;

		/*Execute the token*/
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(av[0]);
			free(input);
			exit(1);
		}
	}
	else
		wait(&status);
}

