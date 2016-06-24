/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 18:16:44 by dgalide           #+#    #+#             */
/*   Updated: 2016/06/17 18:16:45 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

void		end_del(t_data *data)
{
	t_room *tmp;
	t_room *tmp2;

	tmp = data->last_room;
	while (tmp)
	{
		ft_memdel((void **)&tmp->name);
		tmp2 = tmp->previous;
		free(tmp);
		tmp = tmp2;
	}
	ft_memdel((void **)&data->cur_path);
	ft_memdel((void **)&data->final_path);
	ft_memdel((void **)&data->data);
	free(data);
}

void		error_exit(t_data *data, int error)
{
	if (error)
	{
		ft_putendl(data->data);
		ft_putendl("ERROR");
	}
	end_del(data);
	exit(3);
}
