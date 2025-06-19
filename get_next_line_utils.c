/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autan <autan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:53:54 by autan             #+#    #+#             */
/*   Updated: 2025/06/19 19:19:10 by autan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*string;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen (s);
	string = malloc (len + 1);
	if (string == NULL)
		return (NULL);
	while (i < len && s[i])
	{
		string[i] = s[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*joined_string;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen (s1);
	len2 = ft_strlen (s2);
	joined_string = malloc ((len1 + len2 + 1) * sizeof (char));
	if (!joined_string)
		return (NULL);
	dest = joined_string;
	while (*s1)
		*dest++ = *s1++;
	while (*s2)
		*dest++ = *s2++;
	*dest = '\0';
	free ((char *)s1);
	return (joined_string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_len;
	size_t	slen;
	char	*substring;

	if (!s)
		return (NULL);
	slen = ft_strlen (s);
	if (start >= slen)
		substr_len = 0;
	else if ((start + len) > slen)
		substr_len = slen - start;
	else
		substr_len = len;
	substring = malloc ((substr_len + 1) * sizeof (char));
	if (!substring)
		return (NULL);
	substring[substr_len] = '\0';
	while (substr_len > 0)
	{
		substr_len--;
		substring[substr_len] = s[start + substr_len];
	}
	return (substring);
}

/*
int main(void)
{
	int fd = open("file.txt", O_RDWR);
	if (fd <= -1)
		return(1);
	char *str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return(0);
}
*/