/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autan <autan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:53:54 by autan             #+#    #+#             */
/*   Updated: 2025/06/13 22:12:07 by autan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define SIZE 100

char    *give_line(int fd)
{
    int     checkfile;
    static char buffer[SIZE];
    char        *line;
    char    *str;

    checkfile = read(fd, &buffer, SIZE);
    if (checkfile == -1)
        return (NULL);
    // if (checkfile == 0) ??
    int i = 0;
    line = malloc(SIZE);
    if (!line)
        return (NULL);
    while (i < checkfile && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] = '\0';
    return(line);
}

char    *get_next_line(int fd)
{
    if (fd == -1)
        return (NULL);
    char *final_line = give_line(fd);
    return(final_line);
}

int main(void)
{
    int fd = open("file.txt", O_RDWR);
    if (fd == -1)
        return(1);
    char *str = get_next_line(fd);
    printf("%s", str);
    return(0);
}