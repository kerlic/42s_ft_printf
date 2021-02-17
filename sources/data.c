/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:49:35 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/16 23:21:04 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*data_ptr(long long int adrress)
{
	char *ifnull;

	if (adrress == (long long)NULL)
	{
		ifnull = malloc(sizeof(char) * 2);
		ifnull[0] = '0';
		ifnull[1] = '\0';
		return (ifnull);
	}
	return (to_hex((long long int)adrress));
}

char	*data_char(va_list *ap)
{
	char	*ch;

	if (!(ch = malloc(sizeof(char) + 1)))
		exit(-1);
	*ch = va_arg(*ap, int);
	return (ch);
}

char	*data_percent(int *flg)
{
	flg[spc] = 0;
	flg[plus] = 0;
	flg[prcsn] = 0;
	return (ft_strdup("%"));
}
