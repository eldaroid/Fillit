/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:33:04 by hthunder          #+#    #+#             */
/*   Updated: 2019/10/16 20:13:34 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef	struct			s_tetri
{
	int					coords[10];
	char				letter;
	struct s_tetri		*next;
}						t_tetri;

int						is_valid(char *buf, int size);
t_tetri					*make_list(char *buf, int size);
int						min_size(int tetri_num);
int						tetri_cntr(t_tetri *tetri_list);
char					**new_map(int map_size);
int						solve_map(char **map, int map_size, t_tetri *tetri);
void					print_map(char **map, int map_size);
void					free_map(char **map, int map_size);
void					free_list(t_tetri *tetri_begin);

#endif
