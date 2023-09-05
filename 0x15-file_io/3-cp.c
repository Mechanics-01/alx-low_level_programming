#include "main.h"

/**
 * error_file - checks for error in file during
 * open operation.
 * @file_from: original file
 * @file_to: destination file
 * @argv: argument vector
 * Return: Void
 */

void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - check the code if correct
 * @argc: number of arguments
 * @argv: argument vecctors
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int file_from, file_to, err_close;
	int write_bytes;
	ssize_t n_bytes;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_from, file_to, argv);

	n_bytes = 1024;
	while (n_bytes == 1024)
	{
		n_bytes = read(file_from, buffer, 1024);
		if (n_bytes == -1)
			error_file(-1, 0, argv);
		write_bytes = write(file_to, buffer, n_bytes);
		if (write_bytes == -1)
			error_file(0, -1, argv);
	}
	err_close = close(file_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	err_close = close(file_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
	return (0);
}
