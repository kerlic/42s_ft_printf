/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:15:13 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/01 15:15:01 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const	void	*ft_memchr(const void *buf, int c, size_t count)
{
	const void *temp;

	temp = buf;
	while (count--)
	{
		if (*(unsigned char *)temp == (unsigned char)c)
			return (temp);
		temp++;
	}
	return (0);
}
