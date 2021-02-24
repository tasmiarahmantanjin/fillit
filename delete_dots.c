/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_dots.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 15:49:10 by wvaara            #+#    #+#             */
/*   Updated: 2020/09/02 16:21:09 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	delete_dots(char ***matrix, int a, int b, int c)
{
	int cc;

	cc = 0;
	while (matrix[a][b] != 0)
	{
		if (matrix[a][b][c] == '.')
			cc++;
		b++;
	}
	if (cc == b)
	{
		b = 0;
		while (matrix[a][b] != 0)
		{
			cc = c;
			while (matrix[a][b][cc] != 0)
			{
				matrix[a][b][cc] = matrix[a][b][cc + 1];
				cc++;
			}
			b++;
		}
		c--;
	}
	return (c);
}
