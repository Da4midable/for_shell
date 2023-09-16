#include "main.h"

char *locate(const char *name)
{
	char *path = _getenv("PATH");
	char *dir_path = NULL;
	char *file_path = NULL;

	if (access(name, F_OK) == 0)
	{
		return(_strdup(name));
	}

	_strtok(path, "=");
	dir_path = _strtok(NULL,":");

	while (dir_path)
	{
		file_path = join_paths('/', dir_path, name);
		if (file_exists(file_path))
		{
			break;
		}
		free(file_path);
		file_path = NULL;
		dir_path = _strtok(NULL, ":");
	}

	free(path);
	return (file_path);
}
