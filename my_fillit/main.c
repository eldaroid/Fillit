/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldaroid <eldaroid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:22:35 by eldaroid          #+#    #+#             */
/*   Updated: 2019/11/08 08:38:28 by eldaroid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*parse_valid(char *file)
{
	int			fd;
	int			cntr;
	char		buf[546];

	fd = open(file, O_RDONLY);
	cntr = (int)read(fd, buf, 546);  //read возвращает количество прочитанных
	if (cntr == -1 || cntr > 545 || cntr < 20)
		return (0);
	close(fd);
	buf[cntr] = '\0';
	if (!(validfile(buf, cntr)))
		return (0);
	return (make_list(buf, cntr));
}

t_tetri	*decision(t_tetri *tetrimina)
{
	char	**map;
	int		map_size;
	int		count_tetr;

	count_tetr = count_size(tetrimina);
	map_size = size_min(count_tetr);
	map = new_map(map_size);
	// solve_map(map, map_size, tetrimina);
	// {
		
	// }
}

int		main(int argc, char **argv)
{
	t_tetri		*tetrimina;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file");
		ft_putchar('\n');
		return (0);
	}
	if (!(tetrimina = parse_valid(argv[1])))
	{
		ft_putstr("error");
		ft_putchar('\n');
		return (0);
	}
	decision(tetrimina);
	return (0);
}
