/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filechecking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 21:18:29 by hthunder          #+#    #+#             */
/*   Updated: 2019/10/15 19:29:10 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	neighbor_cntr(char *buf)
{
	int		i;
	int		cntr;

	i = 0;
	cntr = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				cntr++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				cntr++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				cntr++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				cntr++;
		}
		i++;
	}
	return (cntr);
}

static int	char_cntr(char *buf)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i < 19)
	{
		if (buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			return (0);
		if (buf[i] == '\n' && ((i + 1) % 5) != 0)
			return (0);
		if (buf[i] == '#')
			count++;
		i++;
	}
	if (buf[i] != '\n')
		return (0);
	return (count);
}

int			is_valid(char *buf, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		if ((char_cntr(buf + i)) != 4)
			return (0);
		if (neighbor_cntr(buf + i) != 6 && neighbor_cntr(buf + i) != 8)
			return (0);
		i += 21;
	}
	return (1);
}
