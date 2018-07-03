/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:47:34 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/02/10 17:47:36 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digits(int n, int base)
{
	int i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char	ft_convert(int n)
{
	if (n > 9 && n < 16)
		n = (n - 10) + 65;
	if (n <= 9)
		n = n + '0';
	return (n);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (base < 2 || base > 16)
		return (NULL);
	len = ft_count_digits(value, base);
	str = (char*)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	while (len-- > 0)
	{
		value = value % base;
		str[len] = ft_convert(value);
		value /= base;
	}
	return (str);
}
