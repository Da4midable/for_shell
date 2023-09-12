#include "main.h"


int file_exists(const char *filepath)
{
	struct stat buffer;
	if(stat(filepath, &buffer) == 0)
	return (1);

	return(0);
}