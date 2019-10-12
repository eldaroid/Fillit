/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Etetr_read_chech.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:23:53 by fgracefo          #+#    #+#             */
/*   Updated: 2019/10/12 16:23:53 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	Etetr_read_check(int fd)
{
	char	**line;
	int		gnl;
	int		count_hashteg;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count_hashteg = 0;
	while (true)
	{
		gnl = get_next_line(fd, line);
		if (ft_strlen(line) != 4 || i > 3 || gnl < 0) // чтобы матрица по x и по y была ровно 4
			return (0);
		while (line[fd][j])
		{
			if (line[fd][j] != '.' && line[fd][j] != '#')
				return (0);
			if (line[fd][j] != '#')
				count_hashteg -= -1;
			j++;
		}
		else if (gnl == 0)
			break		
		i++;
	}
	if (i != 3 || count_hashteg != 3)
		return (0);
	return (1);
}