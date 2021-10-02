/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:43:30 by ltouret           #+#    #+#             */
/*   Updated: 2021/10/02 18:42:16 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	**if_err(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	arr = NULL;
	return (arr);
}

static int	str_count(char const *s, char c)
{
	int		sta;
	int		end;
	int		count;

	sta = 0;
	end = ft_strlen(s);
	count = 0;
	while (s[sta] == c && s[sta])
		sta++;
	while (s[end] == c && s[end])
		end--;
	while (end > sta)
	{
		while (s[sta] != c && end > sta)
			sta++;
		while (s[sta] == c && end > sta)
			sta++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		sta;
	int		i;
	int		o;

	o = 0;
	i = -1;
	if (!s)
		return (NULL);
	arr = mymalloc(sizeof(char *) * (str_count(s, c) + 1));
	if (!arr)
		return (NULL);
	while (str_count(s, c) > ++i)
	{
		while (s[o] == c && s[o])
			o++;
		sta = o;
		while (s[o] != c && s[o])
			o++;
		arr[i] = (char *)(malloc(sizeof(*arr[i]) * ((o - sta) + 1)));
		if (!(arr[i]))
			return (if_err(arr));
		ft_strlcpy(arr[i], s + sta, (o - sta) + 1);
	}
	return (arr);
}
