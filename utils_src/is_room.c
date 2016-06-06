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

int		add_room(char *buff, t_data *data)
{
	t_room *room;
	char **tmp;

	printf("ADD_ROOM, buff = {%s} && BOOL_END = %d && BOOL_START = %d\n", buff, data->room_end, data->room_start);
	tmp = ft_strsplit(buff, ' ');
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
