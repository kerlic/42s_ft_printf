/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:48:39 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/05 22:12:53 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*ptr;

	if (lst == 0 || f == 0)
		return (0);
	nlst = ft_lstnew((*f)(lst->content));
	ptr = nlst;
	lst = lst->next;
	while (lst)
	{
		nlst->next = ft_lstnew((*f)(lst->content));
		nlst = nlst->next;
		lst = lst->next;
		if (!nlst)
		{
			ft_lstclear(&ptr, del);
			return (NULL);
		}
	}
	return (ptr);
}
