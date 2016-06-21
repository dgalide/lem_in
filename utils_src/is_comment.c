/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:22:45 by dgalide           #+#    #+#             */
/*   Updated: 2016/06/02 14:22:46 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			comment_handler(char *buff, t_data *data)
{
	if (buff)
	{
		if (ft_strequ(buff, "##end") == 1)
		{
			data->room_end = 1;
			return ((data->room_start) ? 0 : 1);
		}
		else if (ft_strequ(buff, "##start") == 1)
		{
			data->room_start = 1;
			return ((data->room_end) ? 0 : 1);
		}
		else
			return (1);
	}
	return (1);
}
