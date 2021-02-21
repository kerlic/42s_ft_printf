/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:49:35 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/20 15:31:43 by ilsong           ###   ########.fr       */
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
	flg[SPC] = 0;
	flg[PLUS] = 0;
	flg[PRCSN] = 0;
	return (ft_strdup("%"));
}

char	*data_unsign_dec(va_list *ap, int *flg)
{
	if (flg[SIZE] == 2)
		return (ft_llus_itoa(va_arg(*ap, unsigned long long int)));
	else if (flg[SIZE] == 1)
		return (ft_lus_itoa(va_arg(*ap, unsigned long int)));
	else if (flg[SIZE] == 0)
		return (ft_us_itoa(va_arg(*ap, unsigned int)));
	else if (flg[SIZE] == -1)
		return (ft_sus_itoa((short unsigned int)va_arg(*ap, int)));
	else if (flg[SIZE] == -2)
		return (ft_ssus_itoa((unsigned char)va_arg(*ap, int)));
	return (NULL);
}

char	*data_int(va_list *ap, int *flg)
{
	if (flg[SIZE] == 2)
		return (ft_llong_itoa(va_arg(*ap, long long int)));
	else if (flg[SIZE] == 1)
		return (ft_long_itoa(va_arg(*ap, long int)));
	else if (flg[SIZE] == 0)
		return (ft_itoa(va_arg(*ap, int)));
	else if (flg[SIZE] == -1)
		return (ft_short_itoa((short int)va_arg(*ap, int)));
	else if (flg[SIZE] == -2)
		return (ft_sshort_itoa((signed char)va_arg(*ap, int)));
	return (NULL);
}
