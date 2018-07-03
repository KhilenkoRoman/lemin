/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:02:46 by rkhilenk          #+#    #+#             */
/*   Updated: 2017/11/05 14:02:49 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	flag;
	int	j;

	i = 0;
	j = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			j++;
		}
		if (s[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	return (j);
}

static char	*split_word(const char *str, int start, char c)
{
	int		len;
	int		i;
	char	*tmp;

	len = 0;
	i = start;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	tmp = ft_strsub(str, start, len);
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;
	char	*word;

	if (s == NULL)
		return (NULL);
	array = (char **)malloc(sizeof(*array) * (count_words(s, c) + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word = split_word(s, i, c);
			array[j++] = word;
			i += ft_strlen(word);
		}
		else
			i++;
	}
	array[j] = NULL;
	return (array);
}
