/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:07:32 by wvaara            #+#    #+#             */
/*   Updated: 2020/09/03 15:05:13 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_it_safe(char **map, char **old_map, int i, int j)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (old_map[a] != 0)
	{
		if (map[i + a] == 0)
			return (0);
		while (old_map[a][b] != 0)
		{
			if (map[i + a][j + b] == 0)
				return (0);
			if (old_map[a][b] != '.' && map[i + a][j + b] != '.')
				return (0);
			b++;
		}
		b = 0;
		a++;
	}
	return (1);
}

static int	insert_valid_tetri(char **map, char **old_map, int i, int j)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (old_map[a] != 0)
	{
		while (old_map[a][b] != 0)
		{
			if (old_map[a][b] != '.')
				map[i + a][j + b] = old_map[a][b];
			b++;
		}
		b = 0;
		a++;
	}
	return (0);
}

static int	clean_wrong_insert(char **map, char **old_map, int i, int j)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (old_map[a] != 0)
	{
		while (old_map[a][b] != 0)
		{
			if (old_map[a][b] != '.')
				map[i + a][j + b] = '.';
			b++;
		}
		b = 0;
		a++;
	}
	return (0);
}

int			fillit_algorithm(char **map, char ***old_map, int index)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (old_map[index] == 0)
		return (0);
	while (map[a] != 0)
	{
		while (map[a][b] != 0)
		{
			if (is_it_safe(map, old_map[index], a, b))
			{
				insert_valid_tetri(map, old_map[index], a, b);
				if (!fillit_algorithm(map, old_map, index + 1))
					return (0);
				clean_wrong_insert(map, old_map[index], a, b);
			}
			b++;
		}
		a++;
		b = 0;
	}
	return (1);
}
