/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:05:05 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/20 15:22:03 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_data_cstr(char *data, int len, char fmt)
{
	int nop;

	nop = 0;
	if (fmt == 'c')
	{
		write(1, data, 1);
		nop++;
	}
	else
		while (*data && len--)
		{
			write(1, data, 1);
			data++;
			nop++;
		}
	return (nop);
}

int		print_data(char *data, int *flg, int sign)
{
	int	nop;
	int	znum;

	znum = 0;
	nop = 0;
	if (sign)
		nop += print_sign(data, flg);
	if (*data == '-')
		data++;
	znum = flg[PRCSN] - flg[LNTH];
	while (--znum >= 0)
	{
		write(1, "0", 1);
		nop++;
	}
	while (*data)
	{
		write(1, data++, 1);
		nop++;
	}
	return (nop);
}

int		print_num(char *data, int *flg, char fmt)
{
	int	nop;

	nop = 0;
	*data == '-' ? --flg[LNTH] : 0;
	if (flg[WDTH] >= flg[LNTH] && flg[WDTH] > flg[PRCSN])
	{
		if (flg[R_ARR] == 0)
		{
			nop += print_0x(data, fmt, flg);
			nop += print_data(data, flg, 1);
		}
		nop += (flg[LNTH] < flg[PRCSN])
		? print_space(data, flg[WDTH] - flg[PRCSN]
		- (*data == '-' || flg[PLUS] || flg[SPC]), flg, fmt)
		: print_space(data, flg[WDTH] - flg[LNTH]
		- (*data == '-' || flg[PLUS] || flg[SPC]), flg, fmt);
		nop += flg[R_ARR] == 1
		? print_data(data + (*data == '-' && flg[FILL_0]), flg, 0) : 0;
	}
	else
	{
		nop += print_0x(data, fmt, flg);
		nop += print_data(data, flg, 1);
	}
	return (nop);
}

int		print_c_str(char *data, int *flg, char fmt)
{
	int nop;

	nop = 0;
	if (fmt == 'c')
	{
		nop += flg[R_ARR] == 0 ? print_data_cstr(data, 0, 'c') : 0;
		nop += (flg[IS_WDTH])
		? print_space(data, flg[WDTH] - flg[LNTH], flg, 'c') : 0;
		nop += flg[R_ARR] == 1 ? print_data_cstr(data, 0, 'c') : 0;
	}
	else if (flg[IS_PRI] == 1 && flg[LNTH] >= flg[PRCSN])
	{
		flg[R_ARR] == 0 ? nop += print_data_cstr(data, flg[PRCSN], 's') : 0;
		nop += flg[PRCSN] >= 0 ?
		print_space(data, flg[WDTH] - flg[PRCSN], flg, 's')
		: print_space(data, flg[WDTH] - flg[LNTH], flg, 's');
		flg[R_ARR] == 1 ? nop += print_data_cstr(data, flg[PRCSN], 's') : 0;
	}
	else
	{
		flg[R_ARR] == 0 ? nop += print_data_cstr(data, -1, 's') : 0;
		nop += print_space(data, flg[WDTH] - flg[LNTH], flg, 's');
		flg[R_ARR] == 1 ? nop += print_data_cstr(data, -1, 's') : 0;
	}
	return (nop);
}
