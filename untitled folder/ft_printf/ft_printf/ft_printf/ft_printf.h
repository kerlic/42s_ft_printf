/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 23:04:36 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/08 23:35:05 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

////
void	*ft_memmove(void *dest, const void *src, size_t count);
size_t	ft_strlen(const char *str);
int	ft_intlen(int nbr);
char		*ft_itoa(int nbr);
int	ft_atoi(const char *str);
////
char	*strjoin(char const *s1, char *s2);
void	to_upper(char *data);
char	*dec_to_hex(long long int dec);
char	*data_ptr(long long int adrress);
char	*data_int(va_list *ap);
char		*ft_us_itoa(unsigned int nbr);
char	*data_unsign_dec(unsigned int ud);
char	*data_char(va_list *ap);
char	*ft_strdup(const char *s);
void	num_of_printed(int nop, int *addr);
int		is_ch(const char ch, char *cmpstr);

int		print_sign(char *data, int *flg);

int		print_space(char *data, int width, int *flg, char fmt);
char	*z_arr(int len);
int		print_data(char *data, int *flg, int sign, char fmt);
int		print_c_str(char *data, int *flg, char fmt);
int		print_dec(char *data, int *flg, char fmt);
char	*make_data(char format, int *flg, int *nop, va_list *ap);
char	flag_on(const char *ch, int *flg, va_list *ap);
char	*null_init(void);
void		print_main(const char *ch, va_list *ap, int *nop);
int		ft_printf(const char *str, ...);
#endif
