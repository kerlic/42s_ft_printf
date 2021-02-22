/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:32:56 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/07 16:16:21 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_freestr(char **str, int idx)
{
	while (--idx >= 0)
	{
		free(*(--str));
		free(str);
	}
	return ;
}

static	char	*ft_subarray(char const *s, char c)
{
	int		cnt;
	char	*subarr;
	char	*ptr;

	cnt = 0;
	while (s[cnt] != c && s[cnt])
		cnt++;
	if (!(subarr = (char*)malloc(sizeof(char) * (cnt + 1))))
		return (0);
	ptr = subarr;
	while (cnt--)
		*subarr++ = *s++;
	*subarr = 0;
	return (ptr);
}

static	int		ft_cnt(char const *s, char c)
{
	int		idx;
	int		cnt;

	idx = 0;
	cnt = 0;
	while (s[idx++])
		if ((s[idx] == c && s[idx - 1] != c)
		|| (s[idx] == 0 && s[idx - 1] != c))
			cnt++;
	return (cnt);
}

char			**ft_split(char const *s, char c)
{
	int		idx;
	int		cnt;
	char	**str;

	idx = 0;
	cnt = ft_cnt(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (cnt + 1))))
		return (0);
	idx = 0;
	if (*s != c && *s)
		if (!(str[idx++] = ft_subarray(s++, c)))
			cnt = -1;
	while (*s++)
		if (*(s - 1) == c && *s != c && *s != 0)
			if (!(str[idx++] = ft_subarray(s, c)))
				cnt = -1;
	if (cnt == -1 && idx >= 0)
	{
		ft_freestr(&str[idx], idx);
		idx--;
		return (0);
	}
	str[idx] = 0;
	return (str);
}
