/*
** EPITECH PROJECT, 2021
** readfile
** File description:
** readfile
*/

#include "my.h"
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

static char *get_buff(int const fd, struct stat info)
{
    int size = info.st_size;
    char *buff = malloc(sizeof(char) * size + 1);
    int len = 0;
    int offset = 0;

    if (buff == NULL) {
        my_puterror("ERROR: malloc failed\n");
        return (NULL);
    }

    while ((len = read(fd , buff + offset ,  size - offset)) > 0) {
        offset = offset + len;
    }
    if (offset == 0) {
        my_puterror("ERROR: empty file\n");
        return (NULL);
    }
    buff[offset] = '\0';
    return (buff);
}

char *read_file(char const *filename)
{
    int fd = open(filename, O_RDONLY);
    struct stat info;
    char *buff;

    if (fd == -1) {
        my_puterror("ERROR: file does not exist.\n");
        return (NULL);
    }
    if (stat(filename, &info) == -1) {
        my_puterror("ERROR: stat failed\n");
        return (NULL);
    }
    buff = get_buff(fd, info);
    if (buff == NULL)
        return NULL;
    close(fd);
    return buff;
}
