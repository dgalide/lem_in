/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:23:38 by dgalide           #+#    #+#             */
/*   Updated: 2016/06/02 14:23:40 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	start_exist(t_data *data)
{
	t_room *tmp;

	tmp = NULL;
	if (data->room)
	{
		tmp = data->room;
		while (tmp)
		{
			if (tmp->start)
				return (1);
			tmp = tmp->next;
		}
		return (0);
	}
	else
		return (0);
}

static int	end_exist(t_data *data)
{
	t_room *tmp;

	tmp = NULL;
	if (data->room)
	{
		tmp = data->room;
		while (tmp)
		{
			if (tmp->end)
				return (1);
			tmp = tmp->next;
		}
		return (0);
	}
	else
		return (0);
}

static int	check_room(t_data *data, char **buff, t_room *room)
{
	if (data->room_start && start_exist(data))
		data->end_parse = 1;
	else if (data->room_start && !start_exist(data))
		room->start = 1;
	else if (data->room_end && end_exist(data))
		data->end_parse = 1;
	else if (data->room_end && !end_exist(data))
		room->end = 1;
	if (!check_if_digit(buff[1]) || !check_if_digit(buff[2]))
		data->end_parse = 1;
	return ((data->end_parse) ? 0 : 1);
}

static void		add_room(t_data *data, char **buff, t_room *tmp)
{
	printf("ADD ROOM\n\n");
	if (check_room(data, buff, tmp))
	{
		tmp->pos = (int *)malloc(sizeof(int) * 2);
		tmp->pos[0] = ft_atoi(buff[1]);
		tmp->pos[1] = ft_atoi(buff[2]);
		tmp->name = ft_strdup(buff[0]);
		tmp->next = NULL;
		tmp->previous = NULL;
		tmp->matrix_name = (data->last_room) ?
		data->last_room->matrix_name + 1 : 0;
		if (!data->room)
		{
			data->room = tmp;
			data->last_room = tmp;
		}
		else
		{
			data->last_room->next = tmp;
			tmp->previous = data->last_room;
			data->last_room = tmp;
		}
	}
}

int			is_room(char *buff, t_data *data)
{
	t_room *tmp;

	tmp = (t_room *)malloc(sizeof(t_room));
	ft_putchar('A');
	if (ft_countwords(buff, ' ') == 3 && ft_strchr(buff, '-') == NULL
		&& ft_strchr(buff, 'L') == NULL)
	{
		ft_putchar('H');
		add_room(data, ft_strsplit(buff, ' '), tmp);
		ft_putchar('I');
	}
	else if (ft_countwords(buff, '-') == 2)
		data->end_room_parse = 1;
	else if (ft_countwords(buff, '-') > 2)
		data->end_parse = 1;
	else if (ft_strchr(buff, 'L') != NULL)
		data->end_parse = 1;
	return (1);
}
