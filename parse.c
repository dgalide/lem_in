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

static int		fill_data(char *buff, t_data *data)
{
	if (buff[0] == '#')
	{
		if (comment_handler(buff, data) == 0)
			error_exit(data, 1);
	}
	else if (check_if_digit(buff))
	{
		if (is_nb_ants(buff, data) == 0)
			return (0);
	}
	else if (ft_strchr(buff, '-') == NULL && ft_countwords(buff, ' ') == 3)
	{
		if (add_room(buff, data) == 0)
			return (0);
	}
	else if (ft_strchr(buff, '-') != NULL && ft_countwords(buff, '-') == 2)
	{
		if (add_pipe(buff, data) == 0)
			return (0);
	}
	else
		error_exit(data, 1);
	return (1);
}

int				parse(int fd, t_data *data)
{
	char	*buff;
	char	*tmp;
	int		ret;

	buff = NULL;
	ret = 0;
	tmp = ft_strnew(1);
	tmp[0] = '\n';
	while ((ret = get_next_line(fd, &buff)) == 1)
	{
		if (buff && !fill_data(buff, data))
		{
			ft_memdel((void **)&tmp);
			return (0);
		}
		buff = ft_strjoin_free(&buff, &tmp, 1, 0);
		data->data = ft_strjoin_free(&data->data, &buff, 1, 1);
	}
	return (1);
}
