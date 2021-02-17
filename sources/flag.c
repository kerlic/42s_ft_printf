/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:40:19 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/16 23:28:20 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_flag(int *flg)
{
	flg[r_arr] = 1;
	flg[fill_0] = 0;
	flg[wdth] = 0;
	flg[prcsn] = 0;
	flg[plus] = 0;
	flg[spc] = 0;
	flg[hash] = 0;
	flg[is_pri] = 0;
	flg[is_wdth] = 0;
}

void	flg_1(const char *ch, int *flg)
{
	if (*ch == '-')
		flg[r_arr] = 0;
	else if (*ch == '0')
		flg[fill_0] = 1;
	*ch == '+' ? flg[plus] = 1 : 0;
	*ch == ' ' ? flg[spc] = 1 : 0;
	*ch == '#' ? flg[hash] = 1 : 0;
}

void	flg_width(const char *ch, int *flg, va_list *ap)
{
	if (*ch == '*')
	{
		flg[is_wdth] = 1;
		flg[wdth] = va_arg(*ap, int);
		ch++;
	}
	else if (is_ch(*ch, "123456789"))
	{
		flg[wdth] = ft_atoi(ch);
		flg[is_wdth] = 1;
	}
}

void	flg_pricisn(const char *ch, int *flg, va_list *ap)
{
	if (*ch == '*')
	{
		flg[prcsn] = va_arg(*ap, int);
	}
	else if (is_ch(*ch, "0123456789"))
	{
		flg[prcsn] = ft_atoi(ch);
	}
	flg[is_pri] = 1;
}

char	flag_on(const char *ch, int *flg, va_list *ap)
{
	init_flag(flg);
	while (!is_ch(*ch, ".*123456789%cspdiuxXno"))
		flg_1(ch++, flg);
	if (*ch == '*' || is_ch(*ch, "123456789"))
		flg_width(ch++, flg, ap);
	if (flg[is_wdth] && flg[wdth] < 0)
	{
		flg[wdth] *= -1;
		flg[r_arr] = 0;
	}
	while (!is_ch(*ch, ".%cspdiuxXno"))
		ch++;
	if (*ch == '.')
		flg_pricisn(++ch, flg, ap);
	flg[prcsn] < 0 ? flg[is_pri] = 0 : 0;
	while (!is_ch(*ch, "%cspdiuxXno"))
		ch++;
	return (*ch);
}
