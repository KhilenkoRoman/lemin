/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrtochar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:51:34 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/01/17 16:51:35 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nbr_to_char(long nbr)
{
	char	*str;
	int		len;
	int		flag;

	flag = 0;
	len = ft_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len--] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		flag = 1;
	}
	while (len >= 0)
	{
		str[len--] = '0' + (nbr % 10);
		nbr = nbr / 10;
	}
	if (flag == 1)
		str[0] = '-';
	return (str);
}
