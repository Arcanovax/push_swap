/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:51:37 by mboutte           #+#    #+#             */
/*   Updated: 2025/12/19 13:54:01 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (-1);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_remove_start(char *buffer, int to_remove)
{
	int	i;

	i = 0;
	if (to_remove < ft_strlen_secure(buffer))
	{
		while (buffer[i + to_remove])
		{
			buffer[i] = buffer[i + to_remove];
			i++;
		}
	}
	buffer[i] = '\0';
}

static char	*ft_creat_string(char *output, char *buffer, char *new)
{
	int	i;
	int	j;

	i = 0;
	if (output)
	{
		while (output[i])
		{
			new[i] = output[i];
			i++;
		}
		free(output);
	}
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		new[i + j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		new[i + j++] = '\n';
	new[i + j] = '\0';
	ft_remove_start(buffer, j);
	return (new);
}

static char	*ft_add_left(char *output, char *buffer)
{
	char	*new;
	int		size;

	size = ft_find(buffer);
	if (size == -1)
		size = ft_strlen_secure(buffer);
	if (buffer[size] == '\n')
		size++;
	new = malloc(sizeof(char) * (ft_strlen_secure(output) + size + 1));
	if (!new)
		return (NULL);
	return (ft_creat_string(output, buffer, new));
}

char	*get_next_line(int fd)
{
	static char	buffer[64 + 1];
	char		*output;
	int			byte_read;

	if (fd < 0)
		return (NULL);
	output = NULL;
	if (ft_find(buffer) > -1)
		return (ft_add_left(output, buffer));
	if (buffer[0] != '\0')
		output = ft_add_left(output, buffer);
	byte_read = read(fd, buffer, 64);
	while (byte_read > 0)
	{
		buffer[byte_read] = '\0';
		output = ft_add_left(output, buffer);
		if (output && ft_find(output) > -1)
			return (output);
		byte_read = read(fd, buffer, 64);
	}
	if (byte_read == -1 && (output))
		free(output);
	if (byte_read == -1 || !output || output[0] == '\0')
		return (NULL);
	return (output);
}
