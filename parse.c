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
		{
			if (comment_handler(buff, data) == 0)
				error_exit(data, 1);
		}
		else if (check_if_digit(buff))
		{
			if (is_nb_ants(buff, data) == 0)
				return (0);
		}
		else if (ft_strchr(buff, '-') == NULL && ft_countwords(buff, ' ') == 3)
		{
			if (add_room(buff, data) == 0)
				return (0);
		}
		else if (ft_strchr(buff, '-') != NULL && ft_countwords(buff, '-') == 2)
		{
			if(add_pipe(buff, data) == 0)
				return (0);
		}
		else
			error_exit(data, 1);
	}	
	return (1);
}

int				parse(int fd, t_data *data)
{
	char	*buff;
	int		ret;
	int i;
	int j;

	i = -1;
	j = -1;
	buff = NULL;
	while ((ret = get_next_line(fd, &buff)) == 1)
	{
		ft_putendl(buff);
		if (buff && !fill_data(buff, data))
			return (0);
	}
	while (++i < data->nb_room)
	{
		j = -1;
		while (++j < data->nb_room)
		{
			ft_putnbr(data->matrix[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	printf("\nfourmis = %d\n", data->nb_ants);
	print_data(data);
	return (1);
}