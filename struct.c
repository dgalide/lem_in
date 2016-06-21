/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:32:18 by dgalide           #+#    #+#             */
/*   Updated: 2016/06/02 15:32:19 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

t_data 	*load_struct(void)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	data->nb_ants = 0;
	data->nb_room = 0;
	data->end_room_parse = 0;
	data->end_parse = 0;
	data->room_start = 0;
	data->room_end = 0;
	data->room = NULL;
	data->last_room = NULL;
	data->parse_ants = 0;
	data->parse_room = 0;
	data->matrix = NULL;
	data->cur_path = NULL;
	data->final_path = NULL;
	return (data);
}