/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:23:45 by dgalide           #+#    #+#             */
/*   Updated: 2016/06/02 14:23:47 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	find_index(char *name, t_data *data)
{
	t_room *tmp;

	tmp = data->room;
	while(tmp && ft_strequ(name, tmp->name) != 1)
		tmp = tmp->next;
	return (tmp->matrix_name);
}

static int	is_valid_pipe(char **buff, t_data *data)
{
	t_room	*tmp;
	int		bool_0;	
	printf("IS_VALID_PIPE,nb_room == {%d} && buff[0] = {%s} && buff[1] = {%s}\n", data->nb_room, buff[0], buff[1]);
	tmp = data->room;
	bool_0 = 0;
	while (tmp)
	{
		if (ft_strequ(buff[0], tmp->name) == 1)
			bool_0 += 1;
		if (ft_strequ(buff[1], tmp->name) == 1)
			bool_0 += 1;
		tmp = tmp->next;
	}
	return ((bool_0 == 2) ? 1 : 0);
}

int			add_pipe(char *buff, t_data *data)
{
	char **tmp;
	int	i;
	int j;

	tmp = ft_strsplit(buff, '-');
	data->parse_room = 1;
	i = -1;
	j = 0;
	if (is_valid_pipe(tmp, data) == 0)
		return (0);
	if (!data->matrix)
	{
		data->matrix = (int **)malloc(sizeof(int *) * data->nb_room);
		while (++i < data->nb_room)
			data->matrix[i] = (int *)malloc(sizeof(int) * data->nb_room);
		i = 0;
		while (i < data->nb_room)
		{
			j = -1;
			while (++j < data->nb_room)
				data->matrix[i][j] = 0;
			i++;
		}
	}
	else
	{
		data->matrix[find_index(tmp[0], data)][find_index(tmp[1], data)] = 1;
		data->matrix[find_index(tmp[1], data)][find_index(tmp[0], data)] = 1;
	}
	printf("IS_PIPE, buff == {%s} && data->nb_ants == {%d}\n", buff, data->nb_ants);
	return (1);
}
