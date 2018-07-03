/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:39:52 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/11/06 20:39:54 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int		i;
	char	*str;

	str = (char*)s;
	i = 0;
	if (s != NULL)
	{
		while (str[i] != '\0')
			ft_putchar(s[i++]);
	}
	ft_putchar('\n');
}
