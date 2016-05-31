/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:24:34 by dgalide           #+#    #+#             */
/*   Updated: 2016/05/31 16:24:35 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

int			check_validity(char *str)
{
	
	return (1);
}

void		fill_data(char *str, t_data *data)
{

}

int			parse(int fd, t_data *data)
{
	char *buff;
	int ret;

	buff = NULL;
	while ((ret = get_next_line(fd, &str)) == 1)
	{
		if (ret == -1)
			return (ret);
		else
		{
			if (!check_validity(str))
				return (0);
			else
				fill_data(str, data);
		}
	}
	return (1);
}