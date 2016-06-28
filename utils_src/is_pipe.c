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

static int			find_index(char *name, t_data *data)
{
	t_room *tmp;

	tmp = data->room;
	while (tmp && ft_strequ(name, tmp->name) != 1)
		tmp = tmp->next;
	return (tmp->matrix_name);
}

static int			is_valid_pipe(char **buff, t_data *data)
{
	t_room	*tmp;
	int		bol;

	tmp = data->room;
	bol = 0;
	while (tmp)
	{
		if (ft_strequ(buff[0], tmp->name) == 1)
			bol += 1;
		if (ft_strequ(buff[1], tmp->name) == 1)
			bol += 1;
		tmp = tmp->next;
	}
	return ((bol == 2) ? 1 : 0);
}

static int			**load_matrix(int nb_room)
{
	int		**matrix;
	int		i;
	int		j;

	i = -1;
	j = -1;
	matrix = (int **)malloc(sizeof(int *) * nb_room);
	while (++i < nb_room)
		matrix[i] = (int *)malloc(sizeof(int) * nb_room);
	i = 0;
	while (i < nb_room)
	{
		j = -1;
		while (++j < nb_room)
			matrix[i][j] = 0;
		i++;
	}
	return (matrix);
}

int					add_pipe(char *buff, t_data *data)
{
	char **tmp;

	tmp = ft_strsplit(buff, '-');
	if (ft_strequ(tmp[0], tmp[1]) == 1)
		return (0);
	data->parse_room = 1;
	if (!data->matrix)
		data->matrix = load_matrix(data->nb_room);
	if (is_valid_pipe(tmp, data) == 0)
		return (0);
	data->matrix[find_index(tmp[0], data)][find_index(tmp[1], data)] = 1;
	data->matrix[find_index(tmp[1], data)][find_index(tmp[0], data)] = 1;
	ft_memdel((void **)tmp);
	return (1);
}
