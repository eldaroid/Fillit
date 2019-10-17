/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:39:28 by hthunder          #+#    #+#             */
/*   Updated: 2019/10/14 22:56:54 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**new_map(int map_size)
{
	char	**map;
	int		i;

	map = (char **)ft_memalloc(sizeof(char *) * map_size);
	i = 0;
	while (i < map_size)
	{
		map[i] = ft_strnew(map_size);
		ft_memset(map[i], '.', map_size);
		i++;
	}
	return (map);
}

static	int		is_inside(t_tetri *tetri, int map_size, char axis)
{
	if (axis == 'x')
		return (tetri->coords[0] + tetri->coords[8] < map_size &&
			tetri->coords[2] + tetri->coords[8] < map_size &&
			tetri->coords[4] + tetri->coords[8] < map_size &&
			tetri->coords[6] + tetri->coords[8] < map_size);
	else
		return (tetri->coords[1] + tetri->coords[9] < map_size &&
			tetri->coords[3] + tetri->coords[9] < map_size &&
			tetri->coords[5] + tetri->coords[9] < map_size &&
			tetri->coords[7] + tetri->coords[9] < map_size);
}

static	int		is_overlap(char **map, t_tetri *tetri)
{
	int x;
	int y;
	int i;
	int	j;

	x = 0;
	y = 1;
	while (x <= 6)
	{
		j = tetri->coords[x] + tetri->coords[8];
		i = tetri->coords[y] + tetri->coords[9];
		if (map[i][j] != '.')
			return (1);
		x += 2;
		y += 2;
	}
	return (0);
}

static	void	place(char **map, t_tetri *tetri, char c)
{
	int i;
	int j;
	int x;
	int y;

	x = 0;
	y = 1;
	while (x <= 6)
	{
		j = tetri->coords[x] + tetri->coords[8];
		i = tetri->coords[y] + tetri->coords[9];
		map[i][j] = c;
		x += 2;
		y += 2;
	}
}

int				solve_map(char **map, int map_size, t_tetri *tetri)
{
	if (!tetri)
		return (1);
	tetri->coords[8] = 0;
	tetri->coords[9] = 0;
	while (is_inside(tetri, map_size, 'y'))
	{
		while (is_inside(tetri, map_size, 'x'))
		{
			if (!is_overlap(map, tetri))
			{
				place(map, tetri, tetri->letter);
				if (solve_map(map, map_size, tetri->next))
					return (1);
				else
					place(map, tetri, '.');
			}
			(tetri->coords[8])++;
		}
		tetri->coords[8] = 0;
		(tetri->coords[9])++;
	}
	return (0);
}
