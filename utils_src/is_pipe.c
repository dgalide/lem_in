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

int			is_pipe(char *buff, t_data *data)
{
	data->parse_room = 1;
	printf("IS_PIPE, buff == {%s} && data->nb_ants == {%d}\n", buff, data->nb_ants);
	return (1);
}
