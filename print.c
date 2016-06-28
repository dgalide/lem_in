/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 19:39:47 by dgalide           #+#    #+#             */
/*   Updated: 2016/06/24 19:39:48 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

void	print_it(t_data *data, int index_ant, int room)
{
	char	*name;
	t_room	*tmp;

	tmp = data->room;
	room = data->final_path[room + 1];
	while (tmp)
	{
		if (tmp->matrix_name == room)
		{
			name = ft_strdup(tmp->name);
			break ;
		}
		tmp = tmp->next;
	}
	ft_putchar('L');
	ft_putnbr(index_ant + 1);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

int		next_room_is_able(int **path, int *room, int len_path, t_data *data)
{
	if ((*room) == len_path - 1)
	{
		(*path)[(*room)] = 1;
		data->nb_ants -= 1;
		return (1);
	}
	else if ((*room) + 1 < len_path && (*path)[(*room) + 1])
	{
		(*path)[(*room)] = 1;
		(*path)[(*room) + 1] = 0;
		return (1);
	}
	else
		return (0);
}

void	load_data(int len_path, int **path, int nb_ants, int ***ants)
{
	int i;

	i = -1;
	(*path) = (int *)malloc(sizeof(int) * len_path);
	(*ants) = (int **)malloc(sizeof(int *) * nb_ants);
	while (++i < len_path)
		(*path)[i] = 1;
	i = -1;
	while (++i < nb_ants)
	{
		(*ants)[i] = (int *)malloc(sizeof(int) * 1);
		(*ants)[i][0] = 1;
	}
}

void	print_solution(t_data *data)
{
	int *path;
	int **ants;
	int len_path;
	int i;
	int j;

	j = data->nb_ants;
	len_path = data->final_path[0] - 1;
	load_data(len_path, &path, j, &ants);
	i = 0;
	while (data->nb_ants > 0)
	{
		while (i < j)
		{
			if (next_room_is_able(&path, &(ants[i][0]), len_path, data))
			{
				print_it(data, i, ants[i][0]);
				ants[i][0] += 1;
			}
			path[len_path - 1] = 1;
			i++;
		}
		i = 0;
		ft_putchar('\n');
	}
}
