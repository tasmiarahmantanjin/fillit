/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvaara <wvaara@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:53:30 by trahman           #+#    #+#             */
/*   Updated: 2020/09/03 15:00:42 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int			read_fillit_file(const int fd, char *path);
int			check_line_break(int fd);
int			count_hash(char *str);
int			input_to_solution(char **str, int tetro_num);
int			delete_dots(char ***matrix, int a, int b, int c);
int			solve_fillit(char ***tetra, int tetro_num);
int			fillit_algorithm(char **map, char ***old_map, int index);
int			free_fillit(char **map);
int			finish_fillit(char **map, char ***old_map, int tetro_num);
void		free_fillit_str(char **str);

#endif
