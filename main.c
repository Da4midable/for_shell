#include "main.h"

int main()
{
	

	char *command = NULL;
	char *command_cpy;
	char *command_path;
	char **argv = NULL;
	char *tokenized;
	char *delim = " \n";
	size_t buff_size = 0;
	ssize_t n_read = 0;
	int i = 0, argc = 0, l = 0;


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

		tokenized = strtok(command_cpy, delim);

		argc = 0;

		while(tokenized)
		{
			tokenized = strtok(NULL, delim);
			argc++;
		}

		command_cpy = _strdup(command);

		tokenized = strtok(command_cpy, delim);

		argv = malloc(sizeof(char *) * (argc + 1));

			i = 0;
			while (tokenized)
			{
				argv[i] = tokenized;
				tokenized = strtok(NULL, delim);
				i++;
			}
			argv[i] = '\0';

		command_path = locate(argv[0]);
		if (command_path)
		{
			
			argv[0] = command_path;

			if (fork() == 0)
			{
				execve (argv[0], argv, NULL);
			}

			else
			{
				wait(NULL);
				free(command_path);
				command_path = NULL;
			}
		}

		else 
		{
					dprintf(STDERR_FILENO, "./program: %d: %s: not found\n", argc, argv[0]);
		}
	
	}
	return (0);
}
