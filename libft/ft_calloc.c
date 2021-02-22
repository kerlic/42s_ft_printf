/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 21:04:05 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/28 02:00:34 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nitems, size_t size)
{
	void		*temp;
	void		*ptr;
	size_t		idx;

	idx = nitems * size;
	temp = (void*)malloc(nitems * size);
	ptr = temp;
	if (temp == 0)
		return (0);
	while (idx--)
		*((unsigned char*)temp + idx) = 0;
	return (ptr);
}
