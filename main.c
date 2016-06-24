/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:58:54 by dgalide           #+#    #+#             */
/*   Updated: 2016/05/31 15:58:56 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

void			print_it(t_data *data, int index_ant, int room)
{
	char *name;
	t_room *tmp;

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
	ft_putnbr(index_ant);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

int				next_room_is_able(int **path, int *room, int len_path, t_data *data)
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

void			print(int *l, int len)
{
	int i;

	i = -1;
	while (++i < len)
		printf("{%d}\n", l[i]);
	ft_putendl("end print");
}

void			print_solution(t_data *data)
{
	int *path;
	int **ants;
	int len_path;
	int i;
	int j;

	i = -1;
	j = data->nb_ants;
	len_path = data->final_path[0] - 1;
	path = (int *)malloc(sizeof(int) * len_path);
	while (++i < len_path)
		path[i] = 1;
	i = -1;
	ants = (int **)malloc(sizeof(int *) * data->nb_ants);
	while (++i < j)
	{
		ants[i] = (int *)malloc(sizeof(int) * 1);
		ants[i][0] = 0;
	}
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

int				main(int argc, char **argv)
{
	int		fd;
	t_data	*data;

	fd = 0;
	data = NULL;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	data = load_struct();
	parse(fd, data);
	process(data, data->start_cursor, 0);
	if (!data->final_path)
		error_exit(data, 1);
	else	
	{
		ft_putchar('\n');
		print_solution(data);
		error_exit(data, 0);
	}
	return (0);
}
