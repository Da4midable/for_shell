#include "main.h"

/**
* _strtok - tokenizes a string into other strings
* @str: the main string to be tokenized
* @delim: the delimiter to indicate the location of tokenization
* Return: token
*/

char *_strtok(char *str, const char *delim)
{
	static char *cpy_str;
	char *token, *receive_str;
	char *cpy_del;

	cpy_del = _strdup(delim);

	if (str != NULL)
	{
		cpy_str = str;
	}

	receive_str = _strstr(cpy_str, cpy_del);

	if (receive_str)
	{
		*receive_str = '\0';
		token = cpy_str;
		cpy_str = receive_str + _strlen(delim);
	}
	else
	{

		if (*cpy_str)
		{
			token = cpy_str;
			cpy_str += _strlen(cpy_str);
		}

		else
		{
			token = NULL;
		}
	}

	free(cpy_del);

	return (token);
}


