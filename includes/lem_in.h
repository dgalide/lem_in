/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:28:22 by dgalide           #+#    #+#             */
/*   Updated: 2016/05/31 15:28:25 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN

# include "../libft/includes/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct  	s_room
{
	int				end;
	int				start;
	int 			matrix_name;
	char			*name;
	struct s_room	*next;
	struct s_room	*previous;
}					t_room;

typedef struct 		s_data
{
	t_room			*room;
	t_room			*last_room;
	int 			nb_ants;
	int				nb_room;
	int 			**matrix;
	int				end_room_parse;
	int				end_parse;
	int				room_start;
	int				room_end;
	int				parse_ants;
	int 			parse_room;
	int				*cur_path;
	int				*final_path;
	int				start_cursor;
	char			*data;
}					t_data;

int					main(int argc, char **argv);
t_data				*load_struct(void);
int					parse(int fd, t_data *data);
void				process(t_data *data, int room, int cursor);
void				error_exit(t_data *data, int error);
int					*add_to_cur_path(int room, int **cur_path);
int					check_path(int cursor, int *path);
void				save_path(t_data *data);
int					check_end(t_data *data, int room);
void				print_path(int *path);

int					comment_handler(char *buff, t_data *data);
int					is_nb_ants(char *buff, t_data *data);
int					add_room(char *buff, t_data *data);
int					add_pipe(char *buff, t_data *data);
int					check_if_digit(char *buff);

#endif