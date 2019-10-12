/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Etetr_read_chech.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:23:53 by fgracefo          #+#    #+#             */
/*   Updated: 2019/10/12 20:09:14 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*to_check(char **last, char **line)
{
	char		*pointer_find;

	pointer_find = NULL;
	if (*last)
	{
		if ((pointer_find = ft_strchr(*last, '\n')))
		{
			*pointer_find = '\0';
			pointer_find++;
			*line = ft_strdup(*last);
			ft_strcpy(*last, pointer_find);
		}
		else
		{
			*line = ft_strdup(*last);
			ft_strclr(*last);
		}
	}
	else
		*line = ft_strnew(0);
	return (pointer_find);
}

char	*ft_strjoinf(char *s1, char *s2)
{
	char			*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char	*last[250];
	char		buf[BUFF_SIZE + 1];
	int			how_much;
	char		*pointer_f;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	pointer_f = to_check(&last[fd], line);
	if (pointer_f)
		if (!(*pointer_f))
			return (1);
	while ((!pointer_f) && (how_much = read(fd, buf, BUFF_SIZE)))
	{
		buf[how_much] = '\0';
		if ((pointer_f = ft_strchr(buf, '\n')))
		{
			*pointer_f = '\0';
			pointer_f++;
			last[fd] = ft_strdup(pointer_f);
		}
		*line = ft_strjoinf(*line, buf);
	}
	return (how_much || ft_strlen(last[fd]) || ft_strlen(*line) ? 1 : 0);
}

int	etetr_read_check(int fd)
{
	char	**line;
	int		gnl;
	int		count_hashteg;
	int		i;
	int		j;
	int	l;

	i = 0;
	j = 0;
	count_hashteg = 0;
	while (1)
	{
		ft_putstr("aaa");
		gnl = get_next_line(fd, line);
		if (ft_strlen(*line) != 4 || i > 3 || gnl < 0) // чтобы матрица по x и по y была ровно 4
			return (0);
		l = -1;
		while (*line[j])
		{
			if (*line[j] != '.' && *line[j] != '#')
				return (0);
			if (*line[j] != '#')
				count_hashteg -= -1;
			j++;
		}
		if (gnl == 0)
			break;
		i++;
	}
	if (i != 3 || count_hashteg != 3)
		return (0);
	return (1);
}
