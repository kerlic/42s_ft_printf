/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 19:32:09 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/01 15:34:51 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	while (num--)
	{
		if (*str1 == *str2 && *str1 != 0 && *str2 != 0)
		{
			str1++;
			str2++;
			continue;
		}
		else
			return (*(unsigned char*)str1 - *(unsigned char*)str2);
	}
	return (0);
}
