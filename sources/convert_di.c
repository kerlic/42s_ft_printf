/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:06:00 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/21 16:23:48 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		lintlen(long long int nbr)
{
	int	len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_llong_itoa(long int nbr)
{
	int			len;
	char		*str;

	len = lintlen(nbr);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = 0;
	if (nbr < 0)
	{
		if (nbr == LLONG_MIN)
		{
			str[--len] = -1 * (nbr % 10) + '0';
			nbr /= 10;
		}
		nbr *= -1;
		str[0] = '-';
	}
	while (nbr >= 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
		if (nbr == 0)
			return (str);
	}
	return (NULL);
}

char	*ft_long_itoa(long int nbr)
{
	int			len;
	char		*str;

	len = lintlen(nbr);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = 0;
	if (nbr < 0)
	{
		if (nbr == LONG_MIN)
		{
			str[--len] = -1 * (nbr % 10) + '0';
			nbr /= 10;
		}
		nbr *= -1;
		str[0] = '-';
	}
	while (nbr >= 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
		if (nbr == 0)
			return (str);
	}
	return (NULL);
}

char	*ft_short_itoa(short int nbr)
{
	int			len;
	char		*str;

	len = lintlen(nbr);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = 0;
	if (nbr < 0)
	{
		if (nbr == SHRT_MIN)
		{
			str[--len] = -1 * (nbr % 10) + '0';
			nbr /= 10;
		}
		nbr *= -1;
		str[0] = '-';
	}
	while (nbr >= 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
		if (nbr == 0)
			return (str);
	}
	return (NULL);
}

char	*ft_sshort_itoa(signed char nbr)
{
	int			len;
	char		*str;

	len = lintlen(nbr);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = 0;
	if (nbr < 0)
	{
		if (nbr == CHAR_MIN)
		{
			str[--len] = -1 * (nbr % 10) + '0';
			nbr /= 10;
		}
		nbr *= -1;
		str[0] = '-';
	}
	while (nbr >= 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
		if (nbr == 0)
			return (str);
	}
	return (NULL);
}
