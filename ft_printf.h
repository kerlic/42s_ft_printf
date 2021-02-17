/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 23:04:36 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/17 01:30:16 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define R-ARR 0
# define FILL_0 1
# define LENTH 2
# define WDTH 3
# define PRCSN 4
# define PLUS 5
# define SPC 6
# define HASH 7
# define IS_PRI 8
# define IS_WDTH 9

void	n_of_printed(int nop, int *addr);
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
