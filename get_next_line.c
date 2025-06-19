/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autan <autan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:53:51 by autan             #+#    #+#             */
/*   Updated: 2025/06/19 19:21:49 by autan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*full_line;
	static char	*leftover;
	char		*final_line;
	char		*new_leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	full_line = fill_line_buffer (fd, leftover, buffer);
	free (buffer);
	final_line = set_line (full_line);
	new_leftover = extract_after_nl (full_line);
	free (leftover);
	leftover = new_leftover;
	free (full_line);
	if (!final_line || final_line[0] == '\0')
	{
		free (leftover);
		leftover = NULL;
		free (final_line);
		final_line = NULL;
	}
	return (final_line);
}

char	*fill_line_buffer(int fd, char *leftover, char *buffer)
{
	int		checkfile;
	char	*full_line;

	if (!leftover)
		full_line = ft_strdup ("");
	else
		full_line = ft_strdup (leftover);
	if (!full_line)
		return (NULL);
	while (!ft_strchr (full_line, '\n'))
	{
		checkfile = read (fd, buffer, BUFFER_SIZE);
		if (checkfile <= -1)
		{
			free (full_line);
			return (NULL);
		}
		if (checkfile == 0)
			return (full_line);
		buffer[checkfile] = '\0';
		full_line = ft_strjoin_free (full_line, buffer);
	}
	return (full_line);
}

char	*set_line(char *full_line)
{
	size_t	line_length_till_nl;
	char	*final_line;

	if (!full_line)
		return (NULL);
	line_length_till_nl = ft_strlen_nl (full_line);
	final_line = ft_substr (full_line, 0, line_length_till_nl);
	return (final_line);
}

char	*extract_after_nl(char *full_line)
{
	char	*leftover;
	int		nl_index;
	int		full_line_length;

	if (!full_line)
		return (NULL);
	full_line_length = ft_strlen (full_line);
	nl_index = ft_strlen_nl (full_line);
	leftover = ft_substr (full_line, nl_index, full_line_length - nl_index);
	return (leftover);
}

size_t	ft_strlen_nl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	return (i);
}
