/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:55:24 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/21 16:23:30 by ilsong           ###   ########.fr       */
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

char	*to_hex(long long unsigned int dec)
{
	int								digit;
	int								i;
	long	long	unsigned	int	temp;
	long	long	unsigned	int	div;
	char							*hex;

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

char	*to_oct(long long unsigned int dec)
{
	int								digit;
	int								i;
	long	long	unsigned	int	temp;
	long	long	unsigned	int	div;
	char							*oct;

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
