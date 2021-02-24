/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:19:51 by wvaara            #+#    #+#             */
/*   Updated: 2020/09/04 13:57:44 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	exit_usage(void)
{
	ft_putendl("usage: ./fillit input_file");
	return (-1);
}

static int	exit_readerr(void)
{
	ft_putendl("error");
	return (-1);
}

static int	exit_error(void)
{
	ft_putendl("error");
	return (-1);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		fd1;

	if (argc != 2)
		return (exit_usage());
	if (argc == 2)
	{
		if ((fd1 = open(argv[1], O_RDONLY)) == -1)
			return (exit_readerr());
		if (check_line_break(fd1) == -1)
			return (exit_error());
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (exit_readerr());
		if (read_fillit_file(fd, argv[1]) == -1)
			return (exit_error());
	}
	return (0);
}
