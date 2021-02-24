/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:14:38 by wvaara            #+#    #+#             */
/*   Updated: 2020/09/03 14:50:39 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	***empty_matrix(int size, int a, int b, char c)
{
	char	***matrix;
	int		s;
	int		i;
	int		j;

	s = 0;
	i = 0;
	matrix = (char***)malloc(sizeof(char**) * (size + 1));
	while (s < size)
	{
		matrix[s] = (char**)malloc(sizeof(char*) * (a + 1));
		while (i < a)
		{
			j = 0;
			matrix[s][i] = ft_strnew(b);
			while (j < b)
				matrix[s][i][j++] = c;
			i++;
		}
		matrix[s][i] = NULL;
		s++;
		i = 0;
	}
	matrix[s] = NULL;
	return (matrix);
}

static char	**insert_into_matrix(char ***matrix, char **str)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	c = 0;
	while (matrix[a] != 0)
	{
		while (matrix[a][b] != 0)
		{
			while (matrix[a][b][c] != 0)
			{
				if (str[a][b * 5 + c] == '#')
					matrix[a][b][c] = 65 + a;
				c++;
			}
			b++;
			c = 0;
		}
		a++;
		b = 0;
	}
	free_fillit_str(str);
	return (0);
}

static int	delete_empty_row(char ***matrix)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	while (matrix[a] != 0)
	{
		while (matrix[a][b] != 0)
		{
			if (!(ft_strcmp(matrix[a][b], "....")))
			{
				free(matrix[a][b]);
				c = b--;
				while (matrix[a][c++] != 0)
					matrix[a][c - 1] = matrix[a][c];
			}
			b++;
		}
		b = 0;
		a++;
	}
	return (0);
}

static int	delete_column(char ***matrix)
{
	int a;
	int b;
	int c;

	a = 0;
	b = 0;
	c = 0;
	while (matrix[a] != 0)
	{
		while (matrix[a][b][c] != 0)
		{
			c = delete_dots(matrix, a, b, c);
			c++;
		}
		a++;
		c = 0;
	}
	return (0);
}

int			input_to_solution(char **str, int tetro_num)
{
	char ***matrix;

	matrix = empty_matrix(tetro_num, 4, 4, '.');
	if (!matrix)
		return (-1);
	insert_into_matrix(matrix, str);
	delete_empty_row(matrix);
	delete_column(matrix);
	solve_fillit(matrix, tetro_num);
	return (0);
}
