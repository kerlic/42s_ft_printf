/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 01:50:56 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/05 22:12:44 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		n;

	if (lst == 0)
		return (0);
	n = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		n++;
	}
	return (n);
}
