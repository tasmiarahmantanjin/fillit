/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_wrong_insert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 14:59:58 by wvaara            #+#    #+#             */
/*   Updated: 2020/09/02 15:36:51 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	clean_wrong_insert(char **map, char **old_map, int i, int j)
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
