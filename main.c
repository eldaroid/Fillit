/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgracefo <fgracefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:29:48 by fgracefo          #+#    #+#             */
/*   Updated: 2019/10/12 20:01:40 by fgracefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     main(int argc, char **argv)
{
    int fd;
    int res;
    int i;

    fd = open(argv[1], O_RDONLY);
    ft_putstr("aaa");
    if(!(res = etetr_read_check(fd)))
    {
        printf("error");
    }
    else
    {
        printf("%d", res);
    }
    close(fd);
    return (0);
}