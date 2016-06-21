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

int			*add_to_cur_path(int room, int **cur_path)
{
	int 	*new_path;
	int i;

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

static int check_path(int cursor, int *path)
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

static	void save_path(t_data *data)
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

static	int	check_end(t_data *data, int room)
{
	t_room *tmp;

	tmp = data->room;
	while (tmp->matrix_name != room)
		tmp = tmp->next;
	return ((tmp->end) ? 1 : 0); 
}

void		print_path(int *path)
{
	int i;

	i = 0;
	while (i < path[0])
	{
		ft_putnbr(path[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void		reset_path(t_data *data)
{
	ft_memdel((void **)&data->cur_path);
	data->cur_path = (int *)malloc(sizeof(int) * data->nb_room);
	data->cur_path[0] = 2;
	data->cur_path[1] = data->start_cursor;
}

void		process(t_data *data, int room, int cursor)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!data->cur_path)
	{
		data->cur_path = (int *)malloc(sizeof(int) * data->nb_room);
		data->cur_path[0] = 2;
		data->cur_path[1] = room;
	}
	while (cursor < data->nb_room)
	{
		j = data->cur_path[0] - 1;
		if (j > 1 && cursor == data->cur_path[j - 1])
			cursor++;
		if (data->matrix[cursor][room] == 1)
		{
			if (check_path(cursor, data->cur_path) == 1)
				cursor++;
			else
			{
				if (check_end(data, cursor) == 1)
				{
					data->cur_path = add_to_cur_path(cursor, &(data->cur_path));
					save_path(data);
					reset_path(data);
					printf("END // cursor = {%d}\n", cursor);
					print_path(data->cur_path);
					cursor++;
				}
				else
				{
					printf("RECURSIVE, cursor == {%d}\n", cursor);
					data->cur_path = add_to_cur_path(cursor, &(data->cur_path));
					print_path(data->cur_path);
					process(data, cursor, 0);
					data->cur_path[0] -= 1;
					cursor++;
				}
			}
		}
		else
			cursor++;
	}
	printf("END PROCESS... EXIT");
	print_path(data->final_path);
	if (!data->final_path)
		error_exit(data, 1);
	else
		error_exit(data, 0);
}
