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
	t_data *data;

	fd = 0;
	data = NULL;
	if (argc != 2)
	{
		ft_putendl("ERROR");
		return (0);
	}
	else
	{
		data = load_struct();
		fd = open(argv[1], O_RDONLY);
		parse(fd, data);
		process(data);
	}
	return (0);
}