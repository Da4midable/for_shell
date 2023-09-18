#ifndef _HEADER_
#define _HEADER_

#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>

char *_getenv(const char *name);
char *locate(const char *name);
char *join_paths(const char sep, const char *path1, const char *path2);
int file_exists(const char *filepath);
char *_strdup(const char *str);
int _strcmp(const char *str1, const char *str2);
int _atoi(const char *str);
char *_strtok(char *str, const char *delim);
char *_strstr(char *haystack, char *needle);
size_t _strlen(const char *str);
int _atoi(const char *str);
char *_findenv(const char *name);
int _isdigit(char *str);
int _append(const char *filename, char *text_content);

extern char **environ;

#endif
