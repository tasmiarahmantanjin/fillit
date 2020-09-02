/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trahman <trahman@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:53:30 by trahman           #+#    #+#             */
/*   Updated: 2020/08/31 17:57:26 by trahman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int			ft_read(const int fd, char *path);
int			ft_join_lines(char **s);
int			ft_check_line_break(int fd);
int			ft_valid_file(char *str);
int			ft_count_hash(char *str);
char		***empty_matrix(int size, int a, int b, char c);
char		**insert_into_matrix(char ***matrix, char **str);
int			ft_clean_row(char ***matrix);
int			ft_clean_column(char ***matrix);
int			ft_clean_single_column(char ***matrix, int a, int b, int c);
int			ft_solution_tasmia(char ***tetra, int tetro_num);
int			min_space_sqrt(int n);
char		**ft_empty_map(int j, char c);
int			ft_algorithm(char **map, char ***old_map, int index);
int			fill_map(char **map, char **old_map, int i, int j);
int			ft_is_safe(char **map, char **old_map, int i, int j);
int			ft_clean_wrong_insert(char **map, char **old_map, int i, int j);
int			**ft_free_map(char **map);
int			ft_print_map(char **map);

#endif
