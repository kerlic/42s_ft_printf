/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:16:40 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/04 12:00:13 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buff;
	size_t	slen;

	slen = 0;
	while (s[slen++])
		;
	buff = (char*)malloc(sizeof(char) * slen);
	if (buff == 0)
		return (0);
	while (--slen + 1)
		buff[slen] = s[slen];
	return (buff);
}
