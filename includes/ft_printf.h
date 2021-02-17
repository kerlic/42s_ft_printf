/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 23:04:36 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/17 02:02:48 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define	r_arr 0
# define	fill_0 1
# define	lenth 2
# define	wdth 3
# define	prcsn 4
# define	plus 5
# define	spc 6
# define	hash 7
# define	is_pri 8
# define	is_wdth 9


int		is_ch(const char ch, char *cmpstr);
void	to_upper(char *data);
char	*to_hex(long long int dec);
char	*to_oct(long long int dec);
char	*ft_us_itoa(unsigned int nbr);
int		print_0x(char *data, char fmt, int *flg);
int		print_sign(char *data, int *flg);
int		print_space(char *data, int width, int *flg, char fmt);
int		print_data_cstr(char *data, int len, char fmt);
int		print_data(char *data, int *flg, int sign);
int		print_c_str(char *data, int *flg, char fmt);
int		print_dec(char *data, int *flg, char fmt);
char	*make_data(char format, int *flg, int *nop, va_list *ap);
char	*data_ptr(long long int adrress);
char	*data_char(va_list *ap);
char	*data_percent(int *flg);

void	init_flag(int *flg);
void	flg_1(const char *ch, int *flg);
void	flg_width(const char *ch, int *flg, va_list *ap);
void	flg_pricisn(const char *ch, int *flg, va_list *ap);
char	flag_on(const char *ch, int *flg, va_list *ap);
char	*null_init(void);
void	print_main(const char *ch, va_list *ap, int *nop);
int		ft_printf(const char *str, ...);

#endif
