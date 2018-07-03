/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:42:26 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/01/27 17:42:27 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

void	ft_write_f(char *file, char *str)
{
	int		fd;

	fd = open(file, O_WRONLY);
	ft_putstr_fd(str, fd);
}
