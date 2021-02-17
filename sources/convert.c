/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:55:24 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/16 23:21:10 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	int					digit;
	int					i;
	long	long	int	temp;
	long	long	int	div;
	char				*hex;

	digit = 1;
	div = 1;
	temp = dec;
	while (temp /= 16)
	{
		digit++;
		div *= 16;
	}
	if (!(hex = malloc(sizeof(char) * (digit + 1))))
		exit(-1);
	hex[digit] = 0;
	i = 0;
	while (digit--)
	{
		hex[i++] = ((dec / div) < 10) ? (dec / div) + '0' : (dec / div) + 'W';
		dec %= div;
		div /= 16;
	}
	return (hex);
}

char	*to_oct(long long int dec)
{
	int					digit;
	int					i;
	long	long	int	temp;
	long	long	int	div;
	char				*oct;

	digit = 1;
	div = 1;
	temp = dec;
	while (temp /= 8)
	{
		digit++;
		div *= 8;
	}
	if (!(oct = malloc(sizeof(char) * (digit + 1))))
		exit(-1);
	oct[digit] = 0;
	i = 0;
	while (digit--)
	{
		oct[i++] = (dec / div) + '0';
		dec %= div;
		div /= 8;
	}
	return (oct);
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
