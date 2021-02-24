/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:05:20 by wvaara            #+#    #+#             */
/*   Updated: 2020/09/03 11:17:29 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	min_space_sqrt(int n)
{
	int size;

	size = 1;
	while (size * size < n)
		size++;
	return (size);
}

static char	**new_fillit_box(int j, char c)
{
	int		row;
	int		col;
	int		i;
	char	**map;

	row = 0;
	col = 0;
	i = 0;
	if (!(map = (char **)malloc(sizeof(*map) * (j + 1))))
		return (NULL);
	while (i < j)
	{
		if (!(map[i] = (char*)malloc(sizeof(*map) * (j + 1))))
			return (NULL);
		while (col < j)
			map[i][col++] = c;
		map[i][col] = '\0';
		col = 0;
		i++;
	}
	map[i] = NULL;
	i = 0;
	return (map);
}

int			solve_fillit(char ***old_map, int tetro_num)
{
	int		min_size;
	char	**map;

	min_size = min_space_sqrt(tetro_num * 4);
	map = new_fillit_box(min_size, '.');
	while (fillit_algorithm(map, old_map, 0))
	{
		min_size++;
		free_fillit(map);
		map = new_fillit_box(min_size, '.');
	}
	finish_fillit(map, old_map, tetro_num);
	return (0);
}
