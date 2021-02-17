/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:55:42 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/17 02:04:24 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		is_ch(const char ch, char *cmpstr)
{
	int i;

	i = 0;
	while (cmpstr[i])
	{
		if (ch != cmpstr[i++])
			continue;
		return (1);
	}
	return (0);
}

char	*make_data(char fmt, int *flg, int *nop, va_list *ap)
{
	char	*data;

	data = NULL;
	(fmt == '%') ? data = data_percent(flg) : 0;
	(fmt == 'c') ? data = data_char(ap) : 0;
	(fmt == 's') ? data = ft_strdup(va_arg(*ap, char *)) : 0;
	(fmt == 'p') ? data = data_ptr(va_arg(*ap, long long int)) : 0;
	(fmt == 'd' || fmt == 'i') ? data = ft_itoa(va_arg(*ap, int)) : 0;
	(fmt == 'u') ? data = ft_us_itoa(va_arg(*ap, unsigned int)) : 0;
	(fmt == 'n') ? *(int *)va_arg(*ap, long long int) = *nop : 0;
	(fmt == 'x' || fmt == 'X') ? data = to_hex(va_arg(*ap, unsigned int)) : 0;
	(fmt == 'o') ? data = to_oct(va_arg(*ap, unsigned int)) : 0;
	data && fmt != 'c' ? flg[lenth] = ft_strlen(data) : 0;
	fmt == 'c' ? flg[lenth] = 1 : 0;
	if (data != NULL && *data == '0' && flg[is_pri] == 1 && flg[prcsn] == 0)
	{
		*data = '\0';
		flg[lenth]--;
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
	int		flg[10];
	va_list	temp;

	data = NULL;
	format = flag_on(ch, flg, ap);
	va_copy(temp, *ap);
	if (format == 's' && va_arg(temp, void *) == NULL)
	{
		data = null_init();
		flg[lenth] = 6;
	}
	else
		data = make_data(format, flg, nop, ap);
	format == 'X' ? to_upper(data) : 0;
	if (data != NULL && ((format == 's') || (format == 'c')))
		*nop += print_c_str(data, flg, format);
	else if (data != NULL)
		*nop += print_dec(data, flg, format);
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
			while (is_ch(*str, "# +-.*0123456789\0"))
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
