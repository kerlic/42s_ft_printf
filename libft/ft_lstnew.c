/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 01:11:00 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/30 01:28:47 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *nlist;

	if (!(nlist = (t_list *)malloc(sizeof(t_list))))
		return (0);
	nlist->content = content;
	nlist->next = 0;
	return (nlist);
}
