/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:28:37 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/05 22:28:38 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
