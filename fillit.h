/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahman <trahman@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:53:30 by trahman           #+#    #+#             */
/*   Updated: 2020/09/01 17:20:01 by wvaara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int			g_p;
int			g_pp;

int			ft_read(const int fd, char *path);
int			ft_join_lines(char **s);
int			ft_check_line_break(int fd);
int			ft_valid_file(char *str);
int			ft_count_hash(char *str);
int			ft_input_to_solution(char **str, int tetro_num);
char		***empty_matrix(int size, int a, int b, char c);
char		**insert_into_matrix(char ***matrix, char **str);
int			ft_clean_row(char ***matrix);
int			ft_clean_column(char ***matrix);
int			ft_clean_single_column(char ***matrix, int a, int b, int c);
int			ft_solution(char ***tetra, int tetro_num);
int			min_space_sqrt(int n);
char		**ft_empty_map(int j, char c);
int			ft_algorithm(char **map, char ***old_map, int index);
int			fill_map(char **map, char **old_map, int i, int j);
int			ft_is_safe(char **map, char **old_map, int i, int j);
int			ft_clean_wrong_insert(char **map, char **old_map, int i, int j);
int			ft_free_map(char **map);
int			ft_print_map(char **map);
void		ft_free_str(char **str);
void		ft_free_old(char ***old_map, int tetro_num);

#endif
