/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:30:35 by ilsong            #+#    #+#             */
/*   Updated: 2020/12/22 23:30:35 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int ch)
{
	if (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z'))
		return (1);
	else
		return (0);
}
