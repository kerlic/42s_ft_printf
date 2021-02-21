/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 00:54:38 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/21 16:24:10 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_llus_itoa(long long unsigned int nbr)
{
	int								len;
	char							*str;
	long	long	unsigned	int	temp;

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

char	*ft_lus_itoa(long unsigned int nbr)
{
	int						len;
	char					*str;
	long	unsigned	int	temp;

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

char	*ft_us_itoa(unsigned int nbr)
{
	int				len;
	char			*str;
	unsigned	int	temp;

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

char	*ft_sus_itoa(short unsigned int nbr)
{
	int						len;
	char					*str;
	short	unsigned	int	temp;

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

char	*ft_ssus_itoa(unsigned char nbr)
{
	int					len;
	char				*str;
	unsigned	char	temp;

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
