/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:04:46 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/12/07 16:04:50 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 10

typedef struct	s_gnl_struct
{
	char				*content;
	char				*posle;
	int					fd;
	int					pos;
	char				**ret;
	struct s_gnl_struct	*next;
}				t_gnl_struct;
#endif
