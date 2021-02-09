/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:55:42 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/30 23:35:57 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
//#include "chr_str.c"


void	*ft_memmove(void *dest, const void *src, size_t count)
{
	char		*tmp;
	const char	*s;

	if (!dest && !src)
		return (0);
	tmp = dest;
	s = src;
	if (dest <= src)
	{
		while (count--)
			*tmp++ = *s++;
	}
	else
	{
		tmp += count;
		s += count;
		while (count--)
			*--tmp = *--s;
	}
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t n;

	n = 0;
	while (*str++)
		n++;
	return (n);
}

/////itoa
static	int	ft_intlen(int nbr)
{
	int		len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int nbr)
{
	int					len;
	char				*str;
	long	long	int	l_nbr;

	len = ft_intlen(nbr);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	l_nbr = nbr;
	if (l_nbr < 0)
	{
		l_nbr *= -1;
		str[0] = '-';
	}
	str[len] = 0;
	while (l_nbr >= 0)
	{
		str[--len] = (l_nbr % 10) + '0';
		l_nbr /= 10;
		if (l_nbr == 0)
			return (str);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	int	n;
	long	int num;

	n = 1;
	while (*str && ((9 <= *str && *str <= 13) || *str == 32))
		str++;
	if (*str == '+' || *str == '-')
		n = (*str++ == '-') ? -1 : 1;
	num = 0;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		num *= 10;
		num = num + *str - '0';
		str++;
		if (num > 2147483647 && n == 1)
			return (-1);
		if (num > 2147483648 && n == -1)
			return (0);
	}
	return (n * num);
}





/////////////////////////////////////




char	*data_int(va_list ap)
{
	return (ft_itoa(va_arg(ap, int)));//수정 가능
}

char	*data_char(va_list ap)
{
	char *ch;

	if (!(ch = (char *)malloc(sizeof(char) + 1)))
		exit(-1);
	*ch = *(char *)va_arg(ap, int);
	return (ch);
}

char	*ft_strdup(const char *s)
{
	char	*buff;
	size_t	slen;

	slen = 0;
	while (s[slen++])
		;
	if (!(buff = (char*)malloc(sizeof(char) * slen)))
		exit (-1);
	if (buff == 0)
		return (0);
	while (--slen + 1)
		buff[slen] = s[slen];
	return (buff);
}

void	num_of_printed(int nop, int *addr)
{
	*addr = nop;
	return ;
}

char	*data_ptr(void *adrress)
{

}

//////////////////////////////
////////////////////////////

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

char	is_para(const char *ch)
{
	char	*para;
	char	*flag_width;

	flag_width = "-.*0123456789\0";
	para = "cspdiuxX%n\0";//추가시 설정유의
	while (is_ch(*ch, flag_width))
		ch++;
	if (is_ch(*ch, para))
		return (*ch);
	return (0);
}

int		print_space(int width, int is_zero)
{
	char	ch;
	int		nop;

	if (width <= 0)
		return (0);
	nop = 0;
	ch = is_zero ? '0' : ' ';
	while (width--)
	{
		write(1, &ch, 1);
		nop++;
	}
	return (nop);
}

int		print_id_data(char *data, int len, int pricison)
{
	int nop;

	nop = 0;
	*data == '-' ? (write(1, "-", 1), data++, nop++) : 0;//ft_memmove(data, data + 1, len)삭
	nop += print_space(pricison - len, 1);
	while (*data)
	{
		write(1, data, 1);
		data++;
		nop++;
	}
	return (nop);
}

int		print_main(char *data, int *flag)
{
	int nop;

	nop = 0;
	*data == '-' ? flag[4]++ : 0;
	if ( >= flag[3] && flag[0] >= flag[4])
		nop += print_id_data(data,flag[0] ,0);
	else if (flag[3] >= flag[0] && flag[3] > flag[4])
	{
		flag[1] == 0 ? nop += print_data(data, flag[0], flag[4]) : 0;
		nop += (flag[3] - flag[0] > flag[3] - flag[4])
		? print_space(flag[3] - flag[4], 0)
		: print_space(flag[3] - flag[0], 0);
		flag[1] == 1 ? nop += print_data(data, flag[0], flag[4]) : 0;
	}
	else if (flag[4] >= flag[3])
		nop += print_id_data(data, flag[0], flag[4]);
	return (nop);
}

int		print_id_flag(const char *ch, char format, char *data, va_list ap)
{
	int flag[10];

	if (data == NULL)
		return (0);
	flag[0] = ft_strlen(data);//len
	flag[1] = 1;// r_arr;
	flag[2] = 0;//fill_zero;
	flag[3] = 0;//width
	flag[4] = 0;//pricisn
	*ch == '-' ? (flag[1] = 0, ch++) : (*ch == '0' ? (flag[2] = 1, ch++) : NULL);
	*ch == '*' ? (ch++, flag[3] = va_arg(ap, int)) : ((is_ch(*ch, "0123456789")) ? (flag[3] = ft_atoi(ch)) : 0);
	while (!is_ch(*ch, "cspdiuxXn"))//%s는 빼야함
		*ch++ == '.' ? *(ch) == '*' ? flag[4] = va_arg(ap, int)
		: ((is_ch(*(ch),"0123456789")) ? flag[4] = ft_atoi(ch) : 0) : 0;
	format++;//임시 추카코드
	return (print_main(data, flag));
}

void		print_format(const char *ch, va_list ap, int *nop)//nop은 코드 아끼기 위
{
	char	format;
	char	*data;
	const	char	*ch_init;
	va_list	ap_init;

	data = NULL;
	ch_init = ch;
	va_copy(ap_init, ap);
	if (!(format = is_para(ch)))
		return ;
	while (!is_ch(*ch, "cspdiuxXn"))//%빼야?
		*ch++ == '*' ? va_arg(ap, int) : 0;
	(format == 'c') ? data = data_char(ap) : 0;
	(format == 's') ? data = ft_strdup((const char *)va_arg(ap, int)) : 0;
//	(format == 'p') ? data = data_ptr((void *)va_arg(ap, double)) : 0;
	(format == 'd' || format == 'i') ? data = data_int(ap) : 0;
	(format == 'n') ? num_of_printed(*nop, (int *)va_arg(ap, long long int)) : NULL;
	*nop += print_id_flag(ch_init, format, data, ap_init);
//	free(data);
	data = NULL;
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
			*(str + 1) == '%' ? (write(1, "%", 1), str++, nop++)
			: print_format(str + 1, ap, &nop);
			if (*(str + 1) != '%')
				while (is_ch(*str, "%-.*0123456789\0"))
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

int		main(void)
{
//		float	fn = 123;
	int num = -12345;
//	char buff[] = "abcde";
	int	digit;
	int	temp;

	digit = ft_printf("%%%-10.7d:%d::\n%n", num, num, &temp);
	ft_printf("nop=>%d\n",temp);
	ft_printf("digit=>%d\n",digit);
	printf("1234567890123456789\n");
	digit = printf("%%%-10.8d:%d::\n%n", num, num, &temp);
	printf("nop=>%d\n",temp);
	printf("digit=>%d",digit);

	//digit = ft_printf("%%%-10.7d:%d::\n%n", num, num, &temp);
	//ft_printf("nop=>%d\n",temp);
	//ft_printf("digit=>%d\n",digit);
	//printf("1234567890123456789\n");
	//digit = printf("%%%-10.7d:%d::\n%n", num, num, &temp);
	//printf("nop=>%d\n",temp);
	//printf("digit=>%d",digit);
}

