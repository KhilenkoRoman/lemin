/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 16:13:59 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/12/30 16:14:01 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_putsps2(char c, int n)
{
	char	*str;

	if (n <= 0)
	{
		str = (char *)malloc(sizeof(*str));
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(*str) * (n + 1));
	str[n] = '\0';
	n--;
	while (n >= 0)
		str[n--] = c;
	return (str);
}

int		ft_putsps(char c, int n)
{
	int		i;
	char	*str;

	if (n <= 0)
		return (n);
	str = (char *)malloc(sizeof(*str) * n + 1);
	str[n] = '\0';
	i = 0;
	while (i < n)
	{
		str[i++] = c;
	}
	write(1, str, n);
	free(str);
	return (n);
}
