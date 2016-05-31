/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:58:54 by dgalide           #+#    #+#             */
/*   Updated: 2016/05/31 15:58:56 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

int main(int argc, char **argv)
{
	int fd;
	char *buff;

	fd = 0;
	buff = NULL;
	if (argc != 2)
	{
		ft_putendl("Error");
		return (0);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &buff) == 1)
			ft_putendl(buff);
	}
	return (0);
}