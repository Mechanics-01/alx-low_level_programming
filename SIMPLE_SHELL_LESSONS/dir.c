#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int main(void)
{
	char *path_env = getenv("PATH");
	if (path_env == NULL)
	{
		printf("Error: PATH envorpnment variable not found\n");
		return (1);
	}

	char *path_copy = strdup(path_env);
	char *path = strtok(path_copy, ":");
	 while (path != NULL)
	 {
		 DIR *dir = opendir(path);
		 if (dir != NULL)
		 {
			 struct dirent *entry;
			 while((entry = readdir(dir)) != NULL)
			 {
				 if (entry->d_type == DT_REG)
				 {
					 printf("%s/%s\n", path, entry->d_name);
				 }
			 }
			 closedir(dir);
		 }
		 else
			 printf("Error: Unable to open directory %s\n", path);

		 path = strtok(NULL, ":");
	 }
	 free(path_copy);
	 return (0);
}
