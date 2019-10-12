/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_read_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:33:57 by hthunder          #+#    #+#             */
/*   Updated: 2019/10/08 13:39:05 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	tetr_read_check(int fd)
{
	char	**strs;
	int		i;
	int		j;
	int		hashctr;
	int		gnl;

	hashctr = 0;
	while (true)
	{
		gnl = get_next_line(fd, strs);
		if (gnl == -1)
			return (0);
		else if (gnl == 0)
			break ;
		strs++;
	}

	while (strs[i])
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			if (strs[i][j] == '#')
				hashctr++;
			else if (strs[i][j] != '.')
				return (0);
			j++;
			if (j > 3)
				return (0);
		}
		if (!(i % 4))
		{
			if (strs[i][0] != '\n')
				return (0);
			hashctr = 0;
		}
	}

}
