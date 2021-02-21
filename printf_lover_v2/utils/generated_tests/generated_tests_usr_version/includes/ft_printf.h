/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 23:04:36 by ilsong            #+#    #+#             */
/*   Updated: 2021/02/20 23:32:34 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../includes/libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>

# define R_ARR 0
# define FILL_0 1
# define LNTH 2
# define WDTH 3
# define PRCSN 4
# define PLUS 5
# define SPC 6
# define HASH 7
# define IS_PRI 8
# define IS_WDTH 9
# define SIZE 10

int		is_ch(const char ch, char *cmpstr);

int		ft_printf(const char *str, ...);
void	print_main(const char *ch, va_list *ap, int *nop);
char	*null_init(void);
char	*make_data(char fmt, int *flg, int *nop, va_list *ap);
char	flag_on(const char *ch, int *flg, va_list *ap);

void	init_flag(int *flg);
void	flg_1(const char *ch, int *flg);
void	flg_width(const char *ch, int *flg, va_list *ap);
void	flg_pricisn(const char *ch, int *flg, va_list *ap);
void	type_size(const char *ch, int *flg);

char	*data_ptr(long long int adrress);
char	*data_char(va_list *ap);
char	*data_percent(int *flg);
char	*data_unsign_dec(va_list *ap, int *flg);
char	*data_int(va_list *ap, int *flg);

int		print_num(char *data, int *flg, char fmt);
int		print_c_str(char *data, int *flg, char fmt);
int		print_data(char *data, int *flg, int sign);
int		print_data_cstr(char *data, int len, char fmt);
int		print_sign(char *data, int *flg);
int		print_0x(char *data, char fmt, int *flg);
int		print_space(char *data, int width, int *flg, char fmt);

void	to_upper(char *data);
char	*to_oct(long long unsigned int dec);
char	*to_hex(long long unsigned int dec);

int		lintlen(long long int nbr);
char	*ft_llus_itoa(long long unsigned int nbr);
char	*ft_lus_itoa(long unsigned int nbr);
char	*ft_us_itoa(unsigned int nbr);
char	*ft_sus_itoa(short unsigned int nbr);
char	*ft_ssus_itoa(unsigned char nbr);
char	*data_o(va_list *ap, int *flg);
char	*data_x(va_list *ap, int *flg);
char	*ft_llong_itoa(long int nbr);
char	*ft_long_itoa(long int nbr);
char	*ft_short_itoa(short int nbr);
char	*ft_sshort_itoa(signed char nbr);
char	*data_int(va_list *ap, int *flg);
char	*ft_llus_itoa(long long unsigned int nbr);
char	*ft_lus_itoa(long unsigned int nbr);
char	*ft_us_itoa(unsigned int nbr);
char	*ft_sus_itoa(short unsigned int nbr);
char	*ft_ssus_itoa(unsigned char nbr);

#endif
