/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autan <autan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:08:00 by autan             #+#    #+#             */
/*   Updated: 2025/06/13 21:08:17 by autan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int size = 100;
    char buffer[size];
    char line[size];
    int fd = open("file.txt", O_RDWR);
    if (fd == -1)
        return(1);
    read(fd, &buffer, size);
    int i = 0;
    int j = 0;
    while (buffer[i] != '\n' && buffer[i])
    {
        line[i] = buffer[i];
        i++;
    }
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
    printf("%s\n", line);
    printf("%s", buffer);
    return(0);

}