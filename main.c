#include "main.h"

int main()
{
	char *command, *command_cpy, *command_path, **argv, *tokenized;
	char *delim = " ";
	size_t buff_size = 0;
	ssize_t n_read = 0;
	int i = 0, argc = 0;

	while (1) 
	{
		printf("$ ");
		n_read = getline(&command, &buff_size, stdin);
		command[n_read - 1] = '\0';

		if (n_read == -1)
		{
			return (-1);
		}

		command_cpy = _strdup(command);
		tokenized = _strtok(command_cpy, delim);
		argc = 0;

		while(tokenized)
		{
			tokenized = _strtok(NULL, delim);
			argc++;
		}

		command_cpy = _strdup(command);
		tokenized = _strtok(command_cpy, delim);
		argv = malloc(sizeof(char *) * (argc + 1));

		i = 0;
		while (tokenized)
		{
			argv[i] = tokenized;
			tokenized = _strtok(NULL, delim);
			i++;
		}
			argv[i] = '\0';

		command_path = locate(argv[0]);
		if (command_path != NULL)
		{
			
			argv[0] = command_path;

			if (fork() == 0)
			{	
				
				execve (argv[0], argv, environ);
			}

			{
				wait(NULL);
				free(command_path);
				command_path = NULL;
			}
		}

		else if (_strcmp(argv[0], "exit") == 0)
            exit(_atoi(argv[1])); 
		else 
		{
			dprintf(STDERR_FILENO, "./program: %d: %s: not found\n", argc, argv[0]);	
		}
	}
	return (0);
}
