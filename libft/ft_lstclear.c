/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 04:00:10 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/30 13:46:54 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *past;
	t_list *crrnt;

	crrnt = *lst;
	while (crrnt->next)
	{
		past = crrnt;
		crrnt = crrnt->next;
		del(past->content);
		free(past);
	}
	del(crrnt->content);
	free(crrnt);
	*lst = 0;
}
