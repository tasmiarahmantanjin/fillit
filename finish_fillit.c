/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_fillit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:12:11 by trahman           #+#    #+#             */
/*   Updated: 2020/09/03 14:50:46 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_fillit_old(char ***old_map, int tetro_num)
{
	int i;
	int ii;

	i = 0;
	ii = 0;
	while (i < tetro_num)
	{
		while (old_map[i][ii] != '\0')
		{
			free(old_map[i][ii]);
			ii++;
		}
		ii = 0;
		free(old_map[i]);
		i++;
	}
	free(old_map);
}

int			finish_fillit(char **map, char ***old_map, int tetro_num)
{
	int a;

	a = 0;
	while (map[a] != 0)
	{
		ft_putendl(map[a]);
		a++;
	}
	free_fillit(map);
	free_fillit_old(old_map, tetro_num);
	return (0);
}
