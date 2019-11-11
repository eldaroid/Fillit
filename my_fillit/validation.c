/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldaroid <eldaroid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 22:14:05 by eldaroid          #+#    #+#             */
/*   Updated: 2019/11/04 23:02:58 by eldaroid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int neighbor_count(char *buf)
{
    int count;
    int size;

    count = 0;
    size = 0;
    while (size < 19)
    {
        if (size + 1 < 19 && buf[size + 1] == '#' && buf[size] == '#')
            count++;
        if (size - 1 >= 0 && buf[size - 1] == '#' && buf[size] == '#')
            count++;
       if (size + 5 < 19 && buf[size + 5] == '#' && buf[size] == '#')
            count++;
       if (size - 5 >= 0 && buf[size - 5] == '#' && buf[size] == '#')
            count++;
        size++;
    }
    return (count);
}

static int char_count(char *buf)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (i < 19)
    {
        if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
            return (0);
        if (buf[i] == '\n' && (i + 1) % 5 != 0)
            return (0);
        if (buf[i] == '#')
            count++;
        i++;
    }
    if (buf[i] != '\n')
        return (0);
    return (count);
}

int validfile(char *buf, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (char_count(buf + i) != 4)
            return (0);
        if (neighbor_count(buf + i) != 6 &&  neighbor_count(buf + i) != 8) //when you have a square and amount of neighbors starts to be 8
            return (0);
        i += 21;
    }
    return (1);
}