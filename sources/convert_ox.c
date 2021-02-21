/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:12:19 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/20 15:22:13 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*data_x(va_list *ap, int *flg)
{
	if (flg[SIZE] == 2)
		return (to_hex(va_arg(*ap, unsigned long long int)));
	else if (flg[SIZE] == 1)
		return (to_hex(va_arg(*ap, unsigned long int)));
	else if (flg[SIZE] == 0)
		return (to_hex(va_arg(*ap, unsigned int)));
	else if (flg[SIZE] == -1)
		return (to_hex((short unsigned int)va_arg(*ap, int)));
	else if (flg[SIZE] == -2)
		return (to_hex((unsigned char)va_arg(*ap, int)));
	return (NULL);
}

char	*data_o(va_list *ap, int *flg)
{
	if (flg[SIZE] == 2)
		return (to_oct(va_arg(*ap, unsigned long long int)));
	else if (flg[SIZE] == 1)
		return (to_oct(va_arg(*ap, unsigned long int)));
	else if (flg[SIZE] == 0)
		return (to_oct(va_arg(*ap, unsigned int)));
	else if (flg[SIZE] == -1)
		return (to_oct((short unsigned int)va_arg(*ap, int)));
	else if (flg[SIZE] == -2)
		return (to_oct((unsigned char)va_arg(*ap, int)));
	return (NULL);
}
