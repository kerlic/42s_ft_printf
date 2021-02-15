/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:55:42 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/15 18:06:55 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define	r_arr 0
#define	fill_0 1
#define	lenth 2
#define	wdth 3
#define	prcsn 4
#define	plus 5
#define	spc 6
#define	hash 7
#define	is_pri 8
#define	is_wdth 9

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


int		ft_intlen(int nbr)
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

char	*ft_itoa(int nbr)
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
	return (NULL);
}

int		ft_atoi(const char *str)
{
	long	int	n;
	long	int	num;

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

char	*strjoin(char const *s1, char *s2)
{
	char	*str;
	char	*ptr;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	ptr = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*(str) = 0;
	return (ptr);
}

void	to_upper(char *data)
{
	while (*data)
	{
		if ('a' <= *data && *data <= 'z')
			*data -= 32;
		data++;
	}
}


char	*to_hex(long long int dec)
{
	int	digit;
	int	i;
	long	long	int	temp;
	long	long	int	div;
	char	*hex;

	digit = 1;
	div = 1;
	temp = dec;
	while(temp /= 16)
	{
		digit++;
		div *= 16;
	}
	if (!(hex = malloc(sizeof(char) * (digit + 1))))
		exit (-1);
	hex[digit] = 0;
	i = 0;
	while (digit--)
	{
		hex[i++] = ((dec / div) < 10) ? (dec / div) + '0' : (dec / div) + 'W';
		dec > 16 ? (dec %= div, div /= 16) : (dec %= div, div /= 16);
	}
	return (hex);
}

char	*to_oct(long long int dec)
{
	int	digit;
	int	i;
	long	long	int	temp;
	long	long	int	div;
	char	*oct;

	digit = 1;
	div = 1;
	temp = dec;
	while(temp /= 8)
	{
		digit++;
		div *= 8;
	}
	if (!(oct = malloc(sizeof(char) * (digit + 1))))
		exit (-1);
	oct[digit] = 0;
	i = 0;
	while (digit--)
	{
		oct[i++] = (dec / div) + '0';
		dec > 8 ? (dec %= div, div /= 8) : (dec %= div, div /= 8);
	}
	return (oct);
}


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

char	*data_int(va_list *ap)
{
	return (ft_itoa(va_arg(*ap, int)));//수정 가능
}

char	*ft_us_itoa(unsigned int nbr)
{
	int					len;
	char				*str;
	unsigned	int		temp;

	len = 1;
	temp = nbr;
	while (temp /= 10)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = 0;
	while (nbr >= 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
		if (nbr == 0)
			return (str);
	}
	return (NULL);
}


char	*data_unsign_dec(unsigned int ud)
{
	return (ft_us_itoa(ud));
}


char	*data_char(va_list *ap)
{
	char	*ch;//char 로해야???

	if (!(ch = malloc(sizeof(char) + 1)))
		exit(-1);
	*ch = va_arg(*ap, int);
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

void	n_of_printed(int nop, int *addr)
{
	*addr = nop;
	return ;
}

//////////////////////////////
//////////////////////////////

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

char	*z_arr(int len)
{
	char *ret;

	if (len <= 0)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * len)))
		exit(-1);
	ret[len] = '\0';
	while (--len >= 0)
		ret[len] = '0';
	return (ret);
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
	ch = flg[fill_0] && flg[r_arr] && (flg[is_pri] == 0 || fmt == '%') ? '0' : ' ';
	if (ch == '0' && (fmt == 'p' || ((fmt == 'x' || fmt == 'X' || fmt == 'o'))) && flg[r_arr] == 1)
		nop += print_0x(data, fmt, flg);
	if (ch == '0' && fmt != 's' && fmt != 'c')////////////////////////////
		nop += print_sign(data, flg);
	while ((width-- - 2 * (fmt == 'p' || ((*data && *data != '0') && (fmt == 'x' || fmt == 'X' || fmt == 'o') && flg[hash])) > 0))
	{
		write(1, &ch, 1);
		nop++;
	}
	if (ch == ' ' && (fmt == 'p' || ((fmt == 'x' || fmt == 'X' || fmt == 'o'))) && flg[r_arr] == 1)
		nop += print_0x(data, fmt, flg);
	if (ch == ' ' && flg[r_arr] && fmt != 's'&& fmt != 'c')
		nop += print_sign(data, flg);
	return (nop);
}


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
//////////
///////////

int		print_data(char *data, int *flg, int sign, char fmt)
{
	int		nop;
	//char	*zarr;
	int	znum = 0;

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
	//if ((zarr = z_arr(flg[prcsn] - flg[lenth])))////write로 바꾸기
	//{
		//data = strjoin(zarr, data);
		//ori_data = data;
		//free(zarr);
		fmt = fmt == 'n'? 'n' : fmt;
	//}
	while (*data)
	{
		write(1, data++, 1);
		nop++;
	}
	//zarr != NULL ? free(ori_data) : 0;//////////
	return (nop);
}


int		print_dec(char *data, int *flg, char fmt)//pricision 입력 x와 0입력의 구
{
	int	nop;///p는 부호출력x

	if (data == NULL)
		return (0);
	nop = 0;
	*data == '-' ? --flg[lenth] : 0;/////////
	if (flg[wdth] >= flg[lenth] && flg[wdth] > flg[prcsn])
	{//%d는 lenth, width, prcsn순서
		flg[r_arr] == 0 ? (nop += print_0x(data, fmt ,flg),
		nop += print_data(data, flg, 1, fmt)) : 0;
		nop += (flg[lenth] < flg[prcsn])
		? print_space(data, flg[wdth] - flg[prcsn]
		- (*data == '-' || flg[plus] || flg[spc]), flg, fmt)
		: print_space(data, flg[wdth] - flg[lenth]
		- (*data == '-' || flg[plus] || flg[spc]), flg, fmt);
		nop += flg[r_arr] == 1
		? print_data(data + (*data == '-' && flg[fill_0]), flg, 0, fmt) : 0;
	}
	else
	{
		nop += print_0x(data, fmt, flg);
		nop += print_data(data, flg, 1, fmt);
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
	{//%s는 prcsn,lenth, wdth 순서 prcsn이 가장 작을떄
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
	return nop;
}


char	*make_data(char fmt, int *flg, int *nop, va_list *ap)
{
	char	*data;

	data = NULL;
	(fmt == '%') ? data = (flg[spc] = 0, flg[plus] = 0,
	flg[prcsn] = 0, ft_strdup("%")): 0;////////
	(fmt == 'c') ? data = data_char(ap) : 0;
	(fmt == 's') ? data = (ft_strdup(va_arg(*ap, char *))) : 0;
	(fmt == 'p') ? data = data_ptr(va_arg(*ap, long long int)) : 0;
	(fmt == 'd' || fmt == 'i') ? data = data_int(ap) : 0;
	(fmt == 'u') ? data = data_unsign_dec(va_arg(*ap, unsigned int)) : 0;
	(fmt == 'n') ? n_of_printed(*nop, (int *)va_arg(*ap, long long int)) : NULL;
	(fmt == 'x' || fmt == 'X') ? data = to_hex(va_arg(*ap, unsigned int)) : 0;
	(fmt == 'o') ? data = to_oct(va_arg(*ap, unsigned int)) : 0;
	data && fmt != 'c' ? flg[lenth] = ft_strlen(data) : 0;
	fmt == 'c' ? flg[lenth] = 1 : 0;////////////////
	if (fmt == 'p' && *data == '0' && flg[is_pri] == 1 && flg[prcsn] == 0)
	{
		*data = '\0';
		flg[lenth]--;
	}
	else if (fmt != 'p' && *data == '0' && flg[is_pri] == 1 && flg[prcsn] == 0)
	{
		*data = '\0';
		flg[lenth]--;
	}
	return (data);
}

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

char	flag_on(const char *ch, int *flg, va_list *ap)
{
	init_flag(flg);
	while (!is_ch(*ch, ".*123456789%cspdiuxXno"))
	{
		*ch == '-' ? flg[r_arr] = 0	: (*ch == '0' ? flg[fill_0] = 1 : 0);
		*ch == '+' ? flg[plus] = 1 : 0;
		*ch == ' ' ? flg[spc] = 1 : 0;
		*ch == '#' ? flg[hash] = 1 : 0;
		ch++;
	}//-,0::-우선  +,spc :: +우선  오류처리는 따로?(-1리턴)
	*ch == '*' ? (flg[wdth] = va_arg(*ap, int), flg[is_wdth] = 1, ch++)
	: (is_ch(*ch, "123456789")
	? (flg[wdth] = ft_atoi(ch), flg[is_wdth] = 1, ch++) : 0);
	if (flg[is_wdth] && flg[wdth] < 0)
	{
		flg[wdth] *= -1;
		flg[r_arr] = 0;
	}
	while (!is_ch(*ch, ".%cspdiuxXno"))
		ch++;
	flg[is_pri] = *ch == '.' ? (*(++ch) == '*' ? (flg[prcsn] = va_arg(*ap, int)
	,1)	: (is_ch(*(ch),"0123456789") ? (flg[prcsn] = ft_atoi(ch), 1) : 1)) : 0;
	flg[prcsn] < 0 ? flg[is_pri] = 0 : 0;
	while (!is_ch(*ch, "%cspdiuxXno"))
		ch++;
	return (*ch);
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
	if ((format == 's') || (format == 'c'))
		*nop += print_c_str(data, flg, format);//////////////
	else
		*nop += print_dec(data, flg, format);
	data != NULL ? free(data) : 0;
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


