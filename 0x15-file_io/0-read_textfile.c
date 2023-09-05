#include "main.h"

/**
 * read_texfile - reads a text file and prints
 * @filename: filename
 * @letters: numbers of letters printed
 * Return: number of printed letters
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, read_byte, write_byte;
	char buffer[letters];

	fd = open(filename, O_RDONLY);

	if (filename == NULL)
		return (0);
	if (fd == -1)
		return (0);
	read_byte = read(fd, buffer, letters);

	if (read_byte == -1)
		return (0);
	write_byte = write(STDOUT_FILENO, buffer, read_byte);

	if (write_byte == -1)
		return (0);
	close(fd);
	return (write_byte);
}
