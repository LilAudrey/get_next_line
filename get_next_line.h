/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autan <autan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:53:57 by autan             #+#    #+#             */
/*   Updated: 2025/06/19 19:23:42 by autan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // malloc & free
# include <unistd.h> // read
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 50

char	*get_next_line(int fd);
char	*fill_line_buffer(int fd, char *leftover, char *buffer);
char	*set_line(char *full_line);
char	*extract_after_nl(char *full_line);
char	*ft_strjoin_free(char *s1, const char *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlen_nl(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif