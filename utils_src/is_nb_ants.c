/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_nb_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:23:23 by dgalide           #+#    #+#             */
/*   Updated: 2016/06/02 14:23:25 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	check_if_digit(char *buff)
{
	int i;

	i = 0;
	while (buff && buff[i])
	{
		if (ft_isdigit(buff[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int			is_nb_ants(char *buff, t_data *data)
{
	char *tmp;
	int tmp2;

	tmp = NULL;
	if (data->parse_ants == 1)
		error_exit(data, 1);
	if (check_if_digit(buff))
	{
		tmp2 = ft_atoi(buff);
		tmp = ft_itoa(tmp2);
		if (ft_strequ(buff, tmp) == 0)
			error_exit(data, 1);
		if (tmp2 > INT_MAX)
			error_exit(data, 1);
		data->nb_ants = tmp2;
		data->parse_ants = 1;
		return (1);
	}
	else
	{
		error_exit(data, 1);
		return (0);
	}
}
