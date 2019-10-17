/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:51:25 by hthunder          #+#    #+#             */
/*   Updated: 2019/10/17 17:57:44 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	t_tetri		*parse_file(char *t_file)
{
	char	buf[546];
	int		fd;
	int		cntr;

	fd = open(t_file, O_RDONLY);
	cntr = (int)read(fd, buf, 546);
	if (cntr == -1 || cntr > 545 || cntr < 20)
		return (NULL);
	close(fd);
	buf[cntr] = '\0';
	if (!(is_valid(buf, cntr)))
		return (NULL);
	return (make_list(buf, cntr));
}

static	void		solve(t_tetri *tetri_begin)
{
	char	**map;
	int		map_size;

	map_size = min_size(tetri_cntr(tetri_begin));
	map = new_map(map_size);
	while (!solve_map(map, map_size, tetri_begin))
	{
		free_map(map, map_size);
		map_size++;
		map = new_map(map_size);
	}
	print_map(map, map_size);
	free_map(map, map_size);
}

int					main(int argc, char **argv)
{
	t_tetri *tetri_begin;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file");
		ft_putchar('\n');
		return (0);
	}
	if (!(tetri_begin = parse_file(argv[1])))
	{
		ft_putstr("error");
		ft_putchar('\n');
		return (0);
	}
	solve(tetri_begin);
	free_list(tetri_begin);
	return (0);
}
