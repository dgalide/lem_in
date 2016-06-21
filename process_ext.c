/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 17:03:32 by dgalide           #+#    #+#             */
/*   Updated: 2016/06/21 17:03:33 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

int				*add_to_cur_path(int room, int **cur_path)
{
	int		*new_path;
	int		i;

	i = 0;
	new_path = (int *)malloc(sizeof(int) * (*cur_path)[0] + 1);
	while (i < (*cur_path)[0])
	{
		new_path[i] = (*cur_path)[i];
		i++;
	}
	new_path[0] += 1;
	new_path[i] = room;
	return (new_path);
}

int				check_path(int cursor, int *path)
{
	int i;

	i = 1;
	while (i < path[0])
	{
		if (path[i] == cursor)
			return (1);
		i++;
	}
	return (0);
}

void			save_path(t_data *data)
{
	int i;

	i = 0;
	if (!data->final_path || data->cur_path[0] < data->final_path[0])
	{
		data->final_path = (int *)malloc(sizeof(int) * data->cur_path[0]);
		while (i < data->cur_path[0])
		{
			data->final_path[i] = data->cur_path[i];
			i++;
		}
		
	}

}

int				check_end(t_data *data, int room)
{
	t_room *tmp;

	tmp = data->room;
	while (tmp->matrix_name != room)
		tmp = tmp->next;
	return ((tmp->end) ? 1 : 0);
}
