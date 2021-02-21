/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:40:19 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/20 23:47:54 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_flag(int *flg)
{
	flg[R_ARR] = 1;
	flg[FILL_0] = 0;
	flg[WDTH] = 0;
	flg[PRCSN] = 0;
	flg[PLUS] = 0;
	flg[SPC] = 0;
	flg[HASH] = 0;
	flg[IS_PRI] = 0;
	flg[IS_WDTH] = 0;
	flg[SIZE] = 0;
}

void	flg_1(const char *ch, int *flg)
{
	if (*ch == '-')
		flg[R_ARR] = 0;
	else if (*ch == '0')
		flg[FILL_0] = 1;
	*ch == '+' ? flg[PLUS] = 1 : 0;
	*ch == ' ' ? flg[SPC] = 1 : 0;
	*ch == '#' ? flg[HASH] = 1 : 0;
}

void	flg_width(const char *ch, int *flg, va_list *ap)
{
	if (*ch == '*')
	{
		flg[IS_WDTH] = 1;
		flg[WDTH] = va_arg(*ap, int);
		ch++;
	}
	else if (ft_strchr("123456789", *ch))
	{
		flg[WDTH] = ft_atoi(ch);
		flg[IS_WDTH] = 1;
	}
}

void	flg_pricisn(const char *ch, int *flg, va_list *ap)
{
	if (*ch == '*')
	{
		flg[PRCSN] = va_arg(*ap, int);
	}
	else if (ft_strchr("0123456789", *ch))
	{
		flg[PRCSN] = ft_atoi(ch);
	}
	flg[IS_PRI] = 1;
}

void	type_size(const char *ch, int *flg)
{
	if (flg[SIZE] == 1 && *ch == 'l')
		flg[SIZE] = 2;
	else if (flg[SIZE] == 0 && *ch == 'l')
		flg[SIZE] = 1;
	else if (flg[SIZE] == -1 && *ch == 'h')
		flg[SIZE] = -2;
	else if (flg[SIZE] == 0 && *ch == 'h')
		flg[SIZE] = -1;
	return ;
}
