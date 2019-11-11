/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldaroid <eldaroid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:25:14 by eldaroid          #+#    #+#             */
/*   Updated: 2019/11/07 17:50:23 by eldaroid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/includes/libft.h"
# include <stdio.h>

typedef struct      s_tetri
{
    char            letter;
    int             coords[10];
    struct s_tetri  *next;
}                   t_tetri;

t_tetri	*parse_valid(char *file);
int validfile(char *buf, int size);
static int char_count(char *buf);
static int neighbor_count(char *buf);
t_tetri	*make_list(char *buf, int cntr);
t_tetri	*make_one(char *buf, char letter);
t_tetri	*align(t_tetri *tetri);
int     size_min(int    amount_tetri);
int     count_size(t_tetri *tetrimina);
char    **new_map(int map_size);

# endif