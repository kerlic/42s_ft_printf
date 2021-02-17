/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:05:05 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/16 23:20:46 by ilsong           ###   ########.fr       */
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
	znum = flg[prcsn] - flg[lenth];
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

int		print_dec(char *data, int *flg, char fmt)
{
	int	nop;

	nop = 0;
	*data == '-' ? --flg[lenth] : 0;
	if (flg[wdth] >= flg[lenth] && flg[wdth] > flg[prcsn])
	{
		if (flg[r_arr] == 0)
		{
			nop += print_0x(data, fmt, flg);
			nop += print_data(data, flg, 1);
		}
		nop += (flg[lenth] < flg[prcsn])
		? print_space(data, flg[wdth] - flg[prcsn]
		- (*data == '-' || flg[plus] || flg[spc]), flg, fmt)
		: print_space(data, flg[wdth] - flg[lenth]
		- (*data == '-' || flg[plus] || flg[spc]), flg, fmt);
		nop += flg[r_arr] == 1
		? print_data(data + (*data == '-' && flg[fill_0]), flg, 0) : 0;
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
		nop += flg[r_arr] == 0 ? print_data_cstr(data, 0, 'c') : 0;
		nop += (flg[is_wdth])
		? print_space(data, flg[wdth] - flg[lenth], flg, 'c') : 0;
		nop += flg[r_arr] == 1 ? print_data_cstr(data, 0, 'c') : 0;
	}
	else if (flg[is_pri] == 1 && flg[lenth] >= flg[prcsn])
	{
		flg[r_arr] == 0 ? nop += print_data_cstr(data, flg[prcsn], 's') : 0;
		nop += flg[prcsn] >= 0 ?
		print_space(data, flg[wdth] - flg[prcsn], flg, 's')
		: print_space(data, flg[wdth] - flg[lenth], flg, 's');
		flg[r_arr] == 1 ? nop += print_data_cstr(data, flg[prcsn], 's') : 0;
	}
	else
	{
		flg[r_arr] == 0 ? nop += print_data_cstr(data, -1, 's') : 0;
		nop += print_space(data, flg[wdth] - flg[lenth], flg, 's');
		flg[r_arr] == 1 ? nop += print_data_cstr(data, -1, 's') : 0;
	}
	return (nop);
}
