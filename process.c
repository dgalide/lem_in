/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:25:53 by dgalide           #+#    #+#             */
/*   Updated: 2016/06/07 18:25:55 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

void		reset_path(t_data *data)
{
	ft_memdel((void **)&data->cur_path);
	data->cur_path = (int *)malloc(sizeof(int) * data->nb_room);
	data->cur_path[0] = 2;
	data->cur_path[1] = data->start_cursor;
}

void		process_ext(t_data *data, int *cursor)
{
	if (check_path((*cursor), data->cur_path) == 1)
		(*cursor)++;
	else
	{
		if (check_end(data, (*cursor)) == 1)
		{
			data->cur_path = add_to_cur_path((*cursor), &(data->cur_path));
			save_path(data);
			(*cursor)++;
		}
		else
		{
			data->cur_path = add_to_cur_path((*cursor), &(data->cur_path));
			process(data, (*cursor), 0);
			data->cur_path[0] -= 1;
			(*cursor)++;
		}
	}
}

void		process(t_data *data, int room, int cursor)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!data->cur_path)
		reset_path(data);
	if (data->matrix)
	{
		while (cursor < data->nb_room)
		{
			j = data->cur_path[0] - 1;
			if (j > 1 && cursor == data->cur_path[j - 1])
				cursor++;
			if (cursor < data->nb_room && data->matrix[cursor][room] == 1)
				process_ext(data, &cursor);
			else
				cursor++;
		}
	}
}
