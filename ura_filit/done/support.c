/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 23:23:41 by hthunder          #+#    #+#             */
/*   Updated: 2019/10/15 15:50:26 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map, int map_size)
{
	while (map_size--)
	{
		ft_putstr(*map++);
		ft_putchar('\n');
	}
}

void	free_map(char **map, int map_size)
{
	while (map_size--)
		free(*map++);
}

void	free_list(t_tetri *tetri_begin)
{
	t_tetri *tmp;

	while (tetri_begin)
	{
		tmp = tetri_begin;
		tetri_begin = tetri_begin->next;
		free(tmp);
	}
}

int		tetri_cntr(t_tetri *tetri_list)
{
	int		cntr;

	cntr = 0;
	while (tetri_list)
	{
		tetri_list = tetri_list->next;
		cntr++;
	}
	return (cntr);
}

int		min_size(int tetri_num)
{
	int		map_size;

	map_size = 2;
	while (map_size * map_size < (tetri_num * 4))
		map_size++;
	return (map_size);
}
