/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:31:40 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/11/08 15:31:42 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;
	char	*str;

	str = (char*)s;
	i = 0;
	if (s != NULL)
	{
		while (str[i] != '\0')
			ft_putchar_fd(s[i++], fd);
	}
}
