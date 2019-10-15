/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthunder <hthunder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:19:30 by hthunder          #+#    #+#             */
/*   Updated: 2019/10/08 11:58:08 by hthunder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_cpyuntilchr(char **dst, char **src, char c)
{
	int				num;
	char			*tmp;

	if ((tmp = ft_strchr(*src, c)))
		num = tmp - *src;
	else
		num = ft_strlen(*src);
	*dst = ft_strsub(*src, 0, num);
	tmp = *src;
	if (num < (int)ft_strlen(*src))
	{
		*src = ft_strdup(*src + num + 1);
		free(tmp);
	}
	else
		ft_strclr(*src);
}

char				*ft_strjoinf(char *s1, char *s2)
{
	char			*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

t_list				*find_fd(t_list **head, int fd)
{
	t_list			*tmp;

	tmp = *head;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp->content_size = fd;
	tmp->next = NULL;
	tmp->content = (void *)ft_strnew(0);
	ft_lstadd(head, tmp);
	return (*head);
}

int					get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	ssize_t			ret;
	static t_list	*head;
	t_list			*curr;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	curr = find_fd(&head, fd);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!(curr->content = ft_strjoinf(curr->content, buff)))
			return (-1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret == 0 && !(ft_strlen(curr->content)))
		return (0);
	ft_cpyuntilchr(line, (char **)(&(curr->content)), '\n');
	return (1);
}
