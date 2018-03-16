/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlange <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 10:37:39 by jlange            #+#    #+#             */
/*   Updated: 2017/01/06 13:04:03 by jlange           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <inttypes.h>

typedef struct			s_printf
{
	int			(*fill[15])(void *type, struct s_printf *buf, char *format);
	void		(*size[15])(void *type, struct s_printf *buf, char *format);
	int			error;
	int			width;
	int			precision;
	int			rprecision;
	int			tmplen;

	int			plus;
	int			minus;
	int			zero;
	int			space;
	int			sharp;

	int			len;
	char		*buf;
	char		*index;
}						t_printf;

void					ft_len_arg(char *format, t_printf *buf, va_list ap);
int						purcent_padding(char *format);
int						putwchar(wchar_t data, t_printf *buf);
int						putwstr(wchar_t *str, t_printf *buf);
int						wcharlen_printf(wchar_t c);
int						wstrlen_printf(wchar_t *str);
int						type_i(void *type, t_printf *buf, char *format);
int						type_d(void *type, t_printf *buf, char *format);
int						type_u(void *type, t_printf *buf, char *format);
int						type_u_maj(void *type, t_printf *buf, char *format);
int						type_d_maj(void *type, t_printf *buf, char *format);
int						type_o(void *type, t_printf *buf, char *format);
int						type_o_maj(void *type, t_printf *buf, char *format);
int						type_x(void *type, t_printf *buf, char *format);
int						type_x_maj(void *type, t_printf *buf, char *format);
int						type_c(void *type, t_printf *buf, char *format);
int						type_s(void *type, t_printf *buf, char *format);
int						type_c_maj(void *type, t_printf *buf, char *format);
int						type_s_maj(void *type, t_printf *buf, char *format);
int						type_p(void *type, t_printf *buf, char *format);
int						type_b(void *type, t_printf *buf, char *format);
void					type_ilen(void *type, t_printf *buf, char *format);
void					type_dlen(void *type, t_printf *buf, char *format);
void					type_ulen(void *type, t_printf *buf, char *format);
void					type_u_majlen(void *type, t_printf *buf, char *format);
void					type_d_majlen(void *type, t_printf *buf, char *format);
void					type_olen(void *type, t_printf *buf, char *format);
void					type_o_majlen(void *type, t_printf *buf, char *format);
void					type_xlen(void *type, t_printf *buf, char *format);
void					type_x_majlen(void *type, t_printf *buf, char *format);
void					type_clen(void *type, t_printf *buf, char *format);
void					type_slen(void *type, t_printf *buf, char *format);
void					type_c_majlen(void *type, t_printf *buf, char *format);
void					type_s_majlen(void *type, t_printf *buf, char *format);
void					type_plen(void *type, t_printf *buf, char *format);
void					type_blen(void *type, t_printf *buf, char *format);
void					ft_add_precision(t_printf *buf, int nb, int neg);
void					fill_purcent_padding(char *format, t_printf *buf);
int						ft_atoi(const char *str);
int						ft_intlen(intmax_t nb);
int						ft_uintlen(uintmax_t nb);
size_t					ft_strlen(const char *s);
int						ft_isdigit(int c);
int						ft_uintlen2(uintmax_t nb, t_printf *buf);
int						ft_intlen2(intmax_t nb, char *f, int *precision,
		t_printf *buf);
int						ft_uintlen2base(uintmax_t nb, int base, t_printf *buf);
int						search_zero(char *format);
int						valid_purcent(char *str, int opt);
void					ft_strncat_printf(char **s1, const char *s2, int n);
void					ft_strcat_printf(char **s1, const char *s2);
int						ft_intlen_printf(intmax_t nb);
int						ft_check_type(char c);
int						ft_check_flag(char c);
int						ft_check_length(char c);
int						check_str(char *format, char *str);
void					ft_len_buf(char *format, t_printf *buf, va_list ap);
int						ft_width_len(char *format);
int						ft_precision_len(char *format);
int						ft_precision_len_char(char *format);
int						ft_uintlenbase(uintmax_t nb, int base);
void					ft_fill_width_precision(t_printf *buf, int neg);
void					ft_fill_width(t_printf *buf);
void					ft_fill_precision(t_printf *buf, int neg);
void					ft_fill_buf(char *format, t_printf *buf, va_list ap);
void					ft_itoa_printf(intmax_t n, t_printf *buf, int type,
		char *f);
void					ft_uitoa_printf(uintmax_t n, t_printf *buf, int type,
		char *f);
void					ft_uitoa_base_printf(uintmax_t n, t_printf *buf,
		int base, int type);
void					ft_uitoa_base_printf_p(uintmax_t n, t_printf *buf,
		int base);
void					ft_uitoa_base_maj_printf(uintmax_t n, t_printf *buf,
		int base, int type);
int						wstr_precision(int precision, wchar_t *str);
void					ft_init_flags(t_printf *buf, char *f, int type,
		int arg);

#endif
