/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldaroid <eldaroid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:20:42 by eldaroid          #+#    #+#             */
/*   Updated: 2019/11/07 17:06:35 by eldaroid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

t_tetri	*align(t_tetri *tetri)
{
	int	i;
	
	while (tetri->coords[0] != 0 && tetri->coords[2] != 0 && tetri->coords[4] != 0 && tetri->coords[6]!= 0)
	{
		i = 0;
		while (i < 8)
		{
			tetri->coords[i] -= 1;
			i += 2;
		}
	}
	while (tetri->coords[1] != 0 && tetri->coords[3] != 0 && tetri->coords[5] != 0 && tetri->coords[7]!= 0)
	{
		i = 1;
		while (i < 8)
		{
			tetri->coords[i] -= 1;
			i += 2;
		}
	}
	return (tetri);
}

t_tetri	*make_one(char *buf, char letter)
{
	t_tetri		*tetr;
	int			x;
	int			y;
	int			i;

	if (!(tetr = (t_tetri *)malloc(sizeof(t_tetri))))
		return (0);
	i = 0;
	x = 0;
	y = 1;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			tetr->coords[x] = i % 5;
			tetr->coords[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	tetr->letter = letter;
	tetr->coords[8] = 0;
	tetr->coords[9] = 0;
	return (align(tetr));
}

t_tetri	*make_list(char *buf, int cntr)
{
    int     i;
    char    letter;
    t_tetri *head;
    t_tetri *current;

    letter = 'A';
    while (i < cntr)
    {
         if (letter == 'A')
         {
             head = make_one(buf, letter++);
			 current = head;
         }
		 else
		 {
			current->next = make_one(buf, letter++);
			if (!current->next)
				return (NULL);
			current = current->next;
		 }
		 current->next = NULL;
        i += 21;
    }
    return (head);
}