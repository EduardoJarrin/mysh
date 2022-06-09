/*
** EPITECH PROJECT, 2021
** my_read
** File description:
** reads and checks files
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libmy.h"

char *read_file(char *str)
{
    struct stat buf;
    char *file = NULL;
    int fd = 0;

    buf.st_size = 0;
    stat(str, &buf);
    file = my_strmalloc(buf.st_size);
    if (file == NULL)
        return NULL;
    fd = open(str, O_RDONLY);
    if (fd == -1 || read(fd, file, buf.st_size) == -1) {
        my_perror("Could not open/read file\n");
        free(file);
        return NULL;
    }
    return file;
}

char *read_line(FILE *stream)
{
    size_t size = (size_t)0;
    char *ptr = (char *)0;

    if (getline(&ptr, &size, stream) == -1)
        return NULL;
    my_strreplace(ptr, '\n', '\0');
    return ptr;
}
