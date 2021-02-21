/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:55:42 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/21 16:22:09 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

char	flag_on(const char *ch, int *flg, va_list *ap)
{
	init_flag(flg);
	while (!ft_strchr(".*123456789lh%cspdiuxXno", *ch))
		flg_1(ch++, flg);
	if (*ch == '*' || ft_strchr("123456789", *ch))
		flg_width(ch++, flg, ap);
	if (flg[IS_WDTH] && flg[WDTH] < 0)
	{
		flg[WDTH] *= -1;
		flg[R_ARR] = 0;
	}
	while (!ft_strchr("lh.%cspdiuxXno", *ch))
		ch++;
	if (*ch == '.')
	{
		flg_pricisn(++ch, flg, ap);
		while (ft_strchr("*0123456789", *ch))
			ch++;
	}
	flg[PRCSN] < 0 ? flg[IS_PRI] = 0 : 0;
	while (ft_strchr("lh", *ch))
		type_size(ch++, flg);
	while (!ft_strchr("%cspdiuxXno", *ch))
		ch++;
	return (*ch);
}

char	*make_data(char fmt, int *flg, int *nop, va_list *ap)
{
	char	*data;

	data = NULL;
	(fmt == '%') ? data = data_percent(flg) : 0;
	(fmt == 'c') ? data = data_char(ap) : 0;
	(fmt == 's') ? data = ft_strdup(va_arg(*ap, char *)) : 0;
	(fmt == 'p') ? data = data_ptr(va_arg(*ap, long long int)) : 0;
	(fmt == 'd' || fmt == 'i') ? data = data_int(ap, flg) : 0;
	(fmt == 'u') ? data = data_unsign_dec(ap, flg) : 0;
	(fmt == 'x' || fmt == 'X') ? data = data_x(ap, flg) : 0;
	(fmt == 'o') ? data = data_o(ap, flg) : 0;
	(fmt == 'n') ? *(int *)va_arg(*ap, long long int) = *nop : 0;
	data && fmt != 'c' ? flg[LNTH] = ft_strlen(data) : 0;
	fmt == 'c' ? flg[LNTH] = 1 : 0;
	if (data != NULL && *data == '0' && flg[IS_PRI] == 1 && flg[PRCSN] == 0)
	{
		*data = '\0';
		flg[LNTH]--;
	}
	return (data);
}

char	*null_init(void)
{
	char	*ret;

	ret = malloc(sizeof(char) * 7);
	ret[0] = '(';
	ret[1] = 'n';
	ret[2] = 'u';
	ret[3] = 'l';
	ret[4] = 'l';
	ret[5] = ')';
	ret[6] = '\0';
	return (ret);
}

void	print_main(const char *ch, va_list *ap, int *nop)
{
	char	format;
	char	*data;
	int		flg[11];
	va_list	temp;

	data = NULL;
	format = flag_on(ch, flg, ap);
	va_copy(temp, *ap);
	if (format == 's' && va_arg(temp, void *) == NULL)
	{
		data = null_init();
		flg[LNTH] = 6;
	}
	else
		data = make_data(format, flg, nop, ap);
	format == 'X' ? to_upper(data) : 0;
	if (data != NULL && ((format == 's') || (format == 'c')))
		*nop += print_c_str(data, flg, format);
	else if (data != NULL)
		*nop += print_num(data, flg, format);
	data != NULL && format != 'n' ? free(data) : 0;
	return ;
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		nop;

	nop = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			print_main(++str, &ap, &nop);
			while (ft_strchr("# +-.*0123456789lh", *str))
				str++;
		}
		else
		{
			write(1, str, 1);
			nop++;
		}
		str++;
	}
	va_end(ap);
	return (nop);
}
