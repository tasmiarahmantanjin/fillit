/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fillit_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 10:53:02 by wvaara            #+#    #+#             */
/*   Updated: 2020/09/03 15:08:59 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		validate_file(char *str)
{
	int count;

	count = 0;
	if (*str == '\n')
		return (0);
	while (*str != '\0')
	{
		if (*str != '#' && *str != '.')
			return (-1);
		if (*str == '#' || *str == '.')
			count++;
		str++;
	}
	return (count);
}

static int		check_connect(char *str, int *hash, int *connection, int *empty)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (-1);
		if (str[i] == '.')
			(*empty)++;
		if (str[i] == '#')
		{
			if (str[i + 5] == '#')
				(*connection)++;
			if (str[i - 5] == '#')
				(*connection)++;
			if (str[i + 1] == '#')
				(*connection)++;
			if (str[i - 1] == '#')
				(*connection)++;
			(*hash)++;
		}
		i++;
	}
	return (0);
}

static int		verify_tetri(char *str)
{
	int	hash;
	int empty;
	int	connection;

	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' ||
			str[19] != '\n' || (str[20] != '\n' && str[20] != '\0'))
	{
		return (-1);
	}
	hash = 0;
	empty = 0;
	connection = 0;
	check_connect(str, &hash, &connection, &empty);
	if ((empty != 12 || hash != 4 || connection < 6))
		return (-1);
	return (1);
}

static char		**input_strings(char *path, int size)
{
	int		fd;
	int		ret;
	int		i;
	char	buf[21];
	char	**output;

	i = 0;
	if (!(output = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((ret = read(fd, buf, 21)))
	{
		if (verify_tetri(buf) < 0 || ret < 20)
			return (NULL);
		output[i] = ft_strdup(buf);
		i++;
	}
	output[i] = NULL;
	if (close(fd) == -1)
		return (NULL);
	return (output);
}

int				read_fillit_file(const int fd, char *path)
{
	char	*line;
	int		rethash;
	int		ret;
	int		tetro_num;
	char	**str;

	ret = 0;
	rethash = 0;
	while (ft_gnl(fd, &line) > 0)
	{
		ret = ret + validate_file(line);
		rethash = rethash + count_hash(line);
		if (ret == -1 || rethash == -1)
			return (-1);
		free(line);
	}
	tetro_num = rethash / 4;
	if (ret % 16 != 0 || ret / rethash != 4)
		return (-1);
	str = input_strings(path, tetro_num);
	if (!str)
		return (-1);
	input_to_solution(str, tetro_num);
	return (0);
}
