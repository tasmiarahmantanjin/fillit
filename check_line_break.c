/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_break.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 11:05:13 by wvaara            #+#    #+#             */
/*   Updated: 2020/09/03 14:50:54 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_hash(char *str)
{
	int i;
	int count_hash;
	int count_dot;

	i = 0;
	count_hash = 0;
	count_dot = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			count_hash++;
		if (str[i] == '.')
			count_dot++;
		i++;
	}
	if (count_dot % 12 != 0)
		return (-1);
	return (0);
}

int			check_line_break(int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		count;

	count = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (buf[ret - 1] != '\n')
			return (-1);
		if (buf[ret - 1] == '\n' && buf[ret - 2] == '\n')
			return (-1);
		count++;
		if (buf[0] == '\0' || buf[0] == '\n')
			return (-1);
	}
	if (count != 1)
		return (-1);
	if (check_hash(buf) == -1)
		return (-1);
	return (0);
}
