#include "main.h"

/**
 * create_file - creates a file
 * @filename: filename
 * @text_content: content in the file
 * Return: 1 if success and -1 if fails
 */

int create_file(const char *filename, char *text_content)
{
	int fd, write_byte, read_byte;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (0);
	write_byte = write(fd, text_content, sizeof(text_content));

	if (write_byte == -1)
		return (0);

	if (filename == NULL)
		return (-1);
	close(fd);
	return (1);
}
