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

int		check_room(char **buff)
{
	if (ft_strchr(buff[0], 'L') != NULL)
		return (0);
	if (check_if_digit(buff[1]) == 0)
		return (0);
	if (check_if_digit(buff[2]) == 0)
		return (0);
	return (1);
}

int		add_room(char *buff, t_data *data)
{
	t_room *room;
	char **tmp;

	room = NULL;
	tmp = NULL;
	if (data->parse_room == 1)
	{
		process(data);
		return (1);
	}
	else
	{
		printf("ADD_ROOM, buff = {%s} && BOOL_END = %d && BOOL_START = %d\n", buff, data->room_end, data->room_start);
		tmp = ft_strsplit(buff, ' ');
		if (check_room(tmp) == 0)
			return (0);
		room = (t_room *)malloc(sizeof(t_room));
		room->next = NULL;
		room->previous = NULL;
		room->name = ft_strdup(tmp[0]);
		room->start = (data->room_start) ? 1 : 0;
		room->end = (data->room_end) ? 1 : 0;
		data->room_end = 0;
		data->room_start = 0;
		room->matrix_name = (data->last_room) ? data->last_room->matrix_name + 1 : 0;
		room->pos = (int *)malloc(sizeof(int) * 2);
		room->pos[0] = ft_atoi(tmp[1]);
		room->pos[1] = ft_atoi(tmp[2]);
		data->nb_room += 1;
		if (!data->room)
		{
			data->room = room;
			data->last_room = room;
			return (1);
		}
		else
		{
			room->previous = data->last_room;
			data->last_room->next = room;
			data->last_room = room;
			return (1);
		}
	}
}
