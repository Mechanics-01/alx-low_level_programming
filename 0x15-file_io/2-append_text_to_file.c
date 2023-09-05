#include "main.h"

/**
 * append_text_to_file - appends text at the end of
 * a file
 * @filename: filename
 * @text_content: added content.
 * Return: 1 if file exists, if files does not
 * exists or if it fails.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, n_bytes, write_byte;

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);
	if (filename == NULL)
		return (-1);

	if (text_content)
	{
		for (n_bytes = 0; text_content[n_bytes]; n_bytes++)
		{
			;
		}
		write_byte = write(fd, text_content, n_bytes);

		if (write_byte == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
