/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubartemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:30:50 by ubartemi          #+#    #+#             */
/*   Updated: 2019/07/15 17:51:57 by aestella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_PRINTF_H
# define PRINTF_FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./libft/libft.h"

# define HASH       1
# define ZERO       2
# define MINUS      4
# define PLUS       8
# define SPACE      16
# define ZERO_PRIC  32
# define H          1
# define L_ONE      2
# define HH         4
# define LL         8
# define X          1

typedef struct		s_plist
{
	unsigned int	flag;
	unsigned int	mod;
	unsigned int	h;
	size_t			w;
	size_t			pr;
	size_t			len;
}					t_plist;

typedef struct		s_len
{
	size_t			cur_n;
	size_t			r;
	size_t			pow;
	size_t			i_part;
	int				is_float_p;
	unsigned long	one_left_one;
}					t_len;

int					ft_printf(const char *apformat, ...);
int					ft_analise_flags(char *format, t_plist *lst);
int					ft_is_type(char *c, t_plist *lst);
void				ft_a_typ(char *format, char *res, va_list ap, t_plist *lst);
void				ft_hex_type(char *format, char **result, va_list ap,
		t_plist *lst);
void				ft_digit_type(char **result, va_list ap, t_plist *lst);
void				ft_octal_type(char **result, va_list ap, t_plist *lst);
void				ft_unsigned_type(char **result, va_list ap, t_plist *lst);
t_plist				*make_struct_for_flags(char *format);
char				*ft_add_string(char **result, char *str_arg, t_plist *lst,
		int num_s);
void				ft_add_char(char **result, int chr_arg_int, t_plist *lst);
void				ft_add_integer(char **result, int arg, t_plist *lst);
void				ft_ltoa(char **result, long long arg, int i);
void				ft_long_to_str(char **result, long long int arg,
		t_plist *lst);
void				ft_transform_int_result(char **result, char *cpy_num,
		t_plist *lst);
void				ft_change_type_int(int *arg, t_plist *lst);
void				ft_minus(char **result, char *arg, t_plist *lst,
		size_t len);
void				ft_minus_negative_l(char **result, char *arg,
		t_plist *lst, size_t len);
void				ft_recording(char **result, char *arg, t_plist *lst,
		char fill);
void				ft_recording_negative(char **result,
		char *arg, t_plist *lst, char fill);
void				ft_pricision(char **res, t_plist *lst, size_t len,
		char *arg);
void				ft_plus(char **result, char *arg, t_plist *lst, size_t len);
void				ft_plus_negative(char **result, char *arg, t_plist *lst,
		size_t len);
void				ft_pricision_hex(char *result, t_plist *lst, size_t len,
		char *str);
void				ft_add_unsigned(char **result,
		unsigned long long int arg, t_plist *lst);
void				ft_add_pointer(char **result, unsigned long arg,
		t_plist *lst);
void				ft_add_hex_str(char **result, long long arg, t_plist *lst,
		char sym);
void				ft_uh(char **result, unsigned long long arg, t_plist *lst,
		char sym);
void				ft_add_octal_u(char **result, unsigned long long arg,
		t_plist *lst);
void				ft_add_octal(char **result, unsigned int arg, t_plist *lst);
char				*ft_itoa_base_ul(unsigned long n);
int					ft_lennum_base(unsigned long num);
char				*ft_itoa_base_hex(int n);
size_t				ft_lennum_hex(long long int num);
size_t				ft_lennum_uhex(unsigned long long int num);
void				ft_change_type_hex_l(long long int *arg, t_plist *lst);
void				ft_change_type_hex(long long int *arg, t_plist *lst);
void				ft_pricision_hex2(char *result, t_plist *lst, size_t len,
		char *str);
void				ft_change_type_hex(long long int *arg, t_plist *lst);
void				ft_pricision_hex(char *result, t_plist *lst, size_t len,
		char *str);
char				*ft_itoa_hex(long long int n, char sym);
char				*ft_itoa_uhex(unsigned long long int n, char sym);
int					ft_if_zero_x(char **result, char *str, t_plist *lst);
void				ft_add_uhex_str2(char **result, char *str, char sym,
		t_plist *lst);
void				ft_change_type_oct_h(unsigned int *arg, t_plist *lst);
void				ft_change_type_oct(unsigned int *arg, t_plist *lst);
size_t				ft_lennum_octal(long long num);
size_t				ft_lennum_octal_u(unsigned long long num);
char				*ft_itoa_octal(unsigned long long n);
char				*ft_add_d(unsigned long mant, short exp, int sign,
		t_plist *lst);
void				ft_parse_d(char **result, long double arg_d, t_plist *lst);
void				ft_plus_float(char *cur_n, char *power_two, t_len *l);
void				ft_plus_int(char *cn, char *cp, t_len *l);
size_t				ft_check_len_int(char *nbr);
int					is_nan_inf(char *dbl);
void				ft_roundering(char *cur_res, size_t pricision, t_len *l);
void				ft_add_neg_sign(char **float_nbr, char **buff);
t_len				*ft_make_len_struct(void);
void				ft_make_even(char *cur_num, char *power_two);
void				ft_handle_result_f(int len, int *int_res, char *result);
void				ft_make_power(char *current_power);
char				*ft_find_power(int power);
void				ft_choice_options(char **result, char *tmp_result,
		t_plist *lst);
void				ft_change_type_u(unsigned long long *arg, t_plist *lst);
#endif
