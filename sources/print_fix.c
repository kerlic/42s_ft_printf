/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 20:56:10 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/16 23:28:10 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_sign(char *data, int *flg)
{
	if (flg[plus])
		if (*data == '-')
			write(1, "-", 1);
		else
			write(1, "+", 1);
	else if (flg[spc])
		if (*data == '-')
			write(1, "-", 1);
		else
			write(1, " ", 1);
	else if (*data == '-')
		write(1, "-", 1);
	else
		return (0);
	return (1);
}

int		print_0x(char *data, char fmt, int *flg)
{
	if ((fmt == 'x' && flg[hash] && *data != 0 && *data != '0') || fmt == 'p')
	{
		write(1, "0x", 2);
		return (2);
	}
	else if (fmt == 'X' && flg[hash] && *data != 0 && *data != '0')
	{
		write(1, "0X", 2);
		return (2);
	}
	else if (fmt == 'o' && flg[hash] && *data != 0 && *data != '0')
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

int		print_space(char *data, int width, int *flg, char fmt)
{
	char	ch;
	int		nop;

	nop = 0;
	ch = flg[fill_0] && flg[r_arr] && (flg[is_pri] == 0 || fmt == '%')
	? '0' : ' ';
	if (ch == '0' && (fmt == 'p' || ((fmt == 'x' || fmt == 'X' || fmt == 'o')))
	&& flg[r_arr] == 1)
		nop += print_0x(data, fmt, flg);
	if (ch == '0' && fmt != 's' && fmt != 'c')
		nop += print_sign(data, flg);
	while ((width-- - 2 * (fmt == 'p' || ((*data && *data != '0')
	&& (fmt == 'x' || fmt == 'X' || fmt == 'o') && flg[hash])) > 0))
	{
		write(1, &ch, 1);
		nop++;
	}
	if (ch == ' ' && (fmt == 'p' || ((fmt == 'x' || fmt == 'X' || fmt == 'o')))
	&& flg[r_arr] == 1)
		nop += print_0x(data, fmt, flg);
	if (ch == ' ' && flg[r_arr] && fmt != 's' && fmt != 'c')
		nop += print_sign(data, flg);
	return (nop);
}
