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

static int			check_if_exist(t_data *data, char *name)
{
	t_room *tmp;

	tmp = data->room;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name) == 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int			check_room(char **buff)
{
	if (ft_strchr(buff[0], 'L') != NULL)
		return (0);
	if (check_if_digit(buff[1]) == 0)
		return (0);
	if (check_if_digit(buff[2]) == 0)
		return (0);
	return (1);
}

static void			add_room_ext(t_data *data, t_room *room)
{
	if (!data->room)
	{
		data->room = room;
		data->last_room = room;
	}
	else
	{
		room->previous = data->last_room;
		data->last_room->next = room;
		data->last_room = room;
	}
}

static void			load_new_room(t_data *data, char **tmp, t_room *room)
{
	room->matrix_name =
	(data->last_room) ? data->last_room->matrix_name + 1 : 0;
	room->next = NULL;
	room->previous = NULL;
	room->name = ft_strdup(tmp[0]);
	room->start = (data->room_start) ? 1 : 0;
	room->end = (data->room_end) ? 1 : 0;
}

int					add_room(char *buff, t_data *data)
{
	t_room			*room;
	char			**tmp;

	room = NULL;
	tmp = NULL;
	if (data->parse_ants == 0 || data->parse_room == 1)
		return (0);
	else
	{
		tmp = ft_strsplit(buff, ' ');
		if (check_room(tmp) == 0)
			error_exit(data, 1);
		if (check_if_exist(data, tmp[0]) == 0)
			error_exit(data, 1);
		room = (t_room *)malloc(sizeof(t_room));
		load_new_room(data, tmp, room);
		if (data->room_start)
			data->start_cursor = room->matrix_name;
		data->room_end = 0;
		data->room_start = 0;
		data->nb_room += 1;
		add_room_ext(data, room);
		return (1);
	}
}
