/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listmaking.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 22:51:59 by hthunder          #+#    #+#             */
/*   Updated: 2019/10/17 17:41:50 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	shift_x(t_tetri *piece, int n)
{
	int i;

	i = 0;
	while (i <= 6)
	{
		piece->coords[i] += n;
		i += 2;
	}
}

static	void	shift_y(t_tetri *piece, int n)
{
	int j;

	j = 1;
	while (j <= 7)
	{
		piece->coords[j] += n;
		j += 2;
	}
}

static	t_tetri	*align(t_tetri *tetri)
{
	while (tetri->coords[0] != 0 &&
			tetri->coords[2] != 0 &&
			tetri->coords[4] != 0 &&
			tetri->coords[6] != 0)
		shift_x(tetri, -1);
	while (tetri->coords[1] != 0 &&
			tetri->coords[3] != 0 &&
			tetri->coords[5] != 0 &&
			tetri->coords[7] != 0)
		shift_y(tetri, -1);
	return (tetri);
}

static	t_tetri	*make_tetri(char *buf, char letter)
{
	t_tetri		*tetri_ptr;
	int			x;
	int			y;
	int			i;

	i = 0;
	x = 0;
	y = 1;
	if (!(tetri_ptr = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			tetri_ptr->coords[y] = i / 5;
			tetri_ptr->coords[x] = i % 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	tetri_ptr->letter = letter;
	return (align(tetri_ptr));
}

t_tetri			*make_list(char *buf, int size)
{
	t_tetri		*current;
	t_tetri		*head;
	int			i;
	char		letter;

	i = 0;
	letter = 'A';
	while (i < size)
	{
		if (letter == 'A')
		{
			head = make_tetri(buf, letter++);
			current = head;
		}
		else
		{
			current->next = make_tetri(buf + i, letter++);
			if (!current->next)
				return (NULL);
			current = current->next;
		}
		i += 21;
	}
	current->next = NULL;
	return (head);
}
