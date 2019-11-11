/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldaroid <eldaroid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 17:25:21 by eldaroid          #+#    #+#             */
/*   Updated: 2019/11/07 17:49:25 by eldaroid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     count_size(t_tetri *tetrimina)
{
    int     count;

    count = 0;
    while (tetrimina)
    {
        tetrimina = tetrimina->next;
        count++;
    }
    return (count);
}

int     size_min(int    amount_tetri)
{
    int     map_size;

    map_size = 2;
    while (map_size * map_size < (amount_tetri * 4))
        map_size++;
    return (map_size);
}

char    **new_map(int map_size)
{
    char    **map;
    int     i;

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