/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:24:34 by dgalide           #+#    #+#             */
/*   Updated: 2016/05/31 16:24:35 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

static void print_data(t_data *data)
{
	t_room *tmp;

	tmp = NULL;
	if (data->room)
	{
		tmp = data->room;
		while (tmp)
		{
			printf("[print_data]--> room_name = {%s} && matrix_name = {%d} && BOOL_end = {%d} && BOOL_start = {%d} && nb_room = {%d}\n", tmp->name, tmp->matrix_name, tmp->end, tmp->start, data->nb_room);
			tmp = tmp->next;
		}

	}
}

static int		fill_data(char *buff, t_data *data)
{
	if (buff)
	{	
		if (buff[0] == '#')
			comment_handler(buff, data);
		else if (check_if_digit(buff))
			is_nb_ants(buff, data);
		else if (ft_strchr(buff, '-') == NULL && ft_countwords(buff, ' ') == 3)
			add_room(buff, data);
		else if (ft_strchr(buff, '-') != NULL && ft_countwords(buff, '-') == 2)
			is_pipe(buff, data);
		else
			process(data);
	}	
	return (1);
}

int				parse(int fd, t_data *data)
{
	char	*buff;
	int		ret;

	buff = NULL;
	while ((ret = get_next_line(fd, &buff)) == 1)
	{
		printf("\nbuff in parse = {%s}\n", buff);
		if (buff && !fill_data(buff, data))
			return (0);
	}
	printf("\nfourmis = %d\n", data->nb_ants);
	print_data(data);
	return (1);
}