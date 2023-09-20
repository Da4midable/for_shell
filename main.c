#include "main.h"

/**
* main - main function to be used to compile program
* Return: zero
*/

int main(void)
{
	char *command, *command_cpy, *command_path, **argv, *tokenized, *env_tok;
	char *delim = " ", buffer[BUFF_SIZE], *new_dir, *goback_dir, *env_tok2, *holdit;
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
		if (command_path)
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
		{
			if (!(argv[1]))
				exit(0);
			if (_isdigit(argv[1]))
				exit(_atoi(argv[1]));
		}

		else if (_strcmp(argv[0], "export") == 0)
		{
			env_tok = _strtok(argv[1], "=");
			argv[1] = env_tok;
			argv[2] = _strtok(NULL, "=");

			setenv(argv[1], argv[2], 1);
		}

		else if (_strcmp(argv[0], "unset") == 0)
		{
			unsetenv(argv[1]);
		}

		else if (_strcmp(argv[0], "cd") == 0)
		{
			if (!(argv[1]))
			{
				new_dir = _getenv("HOME");
				env_tok = _strtok(new_dir, "=");
				argv[1] = env_tok;
				argv[2] = _strtok(NULL, "=");
				getcwd(buffer, BUFF_SIZE);
				setenv("OLDPWD", buffer, 1);
				chdir(argv[2]);	
			}
			
			else if (_strcmp(argv[1], "-") == 0)
			{
				goback_dir = _getenv("OLDPWD");
				env_tok = _strtok(goback_dir, "=");
				argv[1] = env_tok2;
				argv[2] = _strtok(NULL, "=");
				getcwd(buffer, BUFF_SIZE);
				setenv("OLDPWD", buffer, 1);
				chdir(argv[2]);
			}

			else
			{
				
				getcwd(buffer, BUFF_SIZE);
				setenv("OLDPWD", buffer, 1);
				chdir(argv[1]);
			
			}
				
		}
		
		else 
		{
			dprintf(STDERR_FILENO, "./program: %d: %s: not found\n", argc, argv[0]);	
		}
	}
	return (0);
}
