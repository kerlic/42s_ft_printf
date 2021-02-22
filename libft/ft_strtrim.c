/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 21:36:17 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/07 03:28:38 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_set(char const *s1, char const *set)
{
	while (*set)
		if (*s1 == *set++)
			return (1);
	return (0);
}

static	size_t	ft_trmlen(char const *s1, char const *set)
{
	char	const	*start;
	char	const	*end;

	while (is_set(s1, set))
		s1++;
	if (*s1 == 0)
		return (0);
	start = s1;
	while (*s1)
		s1++;
	while (is_set(--s1, set) && start <= s1)
		;
	end = s1;
	return ((size_t)(end - start));
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		trlen;
	char		*trmd_str;

	trlen = ft_trmlen(s1, set);
	if (!trlen)
	{
		trmd_str = (char *)malloc(sizeof(char) * (1));
		trmd_str[0] = 0;
		return (trmd_str);
	}
	if (!(trmd_str = (char *)malloc(sizeof(char) * (trlen + 2))))
		return (0);
	while (is_set(s1, set))
		++s1;
	ft_memmove(trmd_str, s1, trlen + 1);
	trmd_str[trlen + 1] = 0;
	return (trmd_str);
}
