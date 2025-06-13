/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autan <autan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:53:54 by autan             #+#    #+#             */
/*   Updated: 2025/06/14 00:57:04 by autan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 100

char    *give_line(int fd)
{
    int     chars_read;
    static char buffer[BUFFER_SIZE];
    char        *line;
    char    *str;

    chars_read = 1;

    while (chars_read != 0)
    {
        chars_read = read(fd, buffer, BUFFER_SIZE);
        int i = 0;
        int j = 0;
        line = malloc(BUFFER_SIZE + 1);
        if (!line)
            return (NULL);
        while (i < chars_read && buffer[i] != '\n')
        {
            line[i] = buffer[i];
            i++;
        }
        line[i] = '\0';
        i++;
        while ((buffer[i] != '\n' && buffer[i]))
        {
            buffer[j] = buffer[i];
            i++;
            j++;
        }
        while (buffer[j] != '\0')
        {
            buffer[j] = '\0';
            j++;
        }
        return(line);
    }
    if (chars_read == -1)
        return (NULL);
    return (NULL);
    
}

char    *get_next_line(int fd)
{
    if (fd < 0)
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
    str = get_next_line(fd);
    printf("%s", str);
    return(0);
}