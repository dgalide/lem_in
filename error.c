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
	free(data->matrix);
}

void		error_exit(t_data *data, int error)
{
	end_del(data);
	if (error == 1)
		ft_putendl("ERROR");
	exit(3);
}
