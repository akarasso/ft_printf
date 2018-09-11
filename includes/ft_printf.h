/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 11:38:14 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/06 09:01:35 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PF_BUFF 4096
# define ABS(x) (x < 0) ? -x : x
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/types.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct		s_flag
{
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
}					t_flag;

typedef struct		s_printf
{
	const char	*str;
	t_flag		flag;
	ssize_t		width;
	ssize_t		preci;
	char		conv;
	char		type;
	char		neg;
	char		signed_t;
	size_t		arg_len;
	size_t		field_len;
	va_list		args;
	long long	printed;
	char		buffer[PF_BUFF + 1];
	int			ibuffer;
	int			error;
	int			noprint;
}					t_printf;

int					ft_printf(const char *s, ...);
void				parse(t_printf *f);
void				convert(t_printf *f);

/*
** util
*/

void				pf_clear_buffer(t_printf *info);
void				ufield(t_printf *f, uintmax_t n, char *charset);
void				field(t_printf *f, intmax_t n, char *charset);
void				char_field(t_printf *f, char c);
void				str_field(t_printf *f, char *str);
void				wstr_field(t_printf *f, wchar_t *wstr);
void				pf_normalize_struct(t_printf *f);
void				pf_putnstr(t_printf *f, char *s, size_t len);
void				pf_buffer(t_printf *f, char *s, size_t len);
void				pf_strcpy(t_printf *f, char *buffer, char *s);
void				pf_putstr(t_printf *f, char *s);
void				pf_wstrcpy(t_printf *f, char *buffer, wchar_t *str);
void				pf_itoa_base(t_printf *f, char *buffer,
						unsigned long long n, char *base);

int					pf_strncmp(const char *s1, char *s2, int n);
int					pf_max(int n1, int n2);
int					pf_min(int n1, int n2);
int					pf_nbr_len(long long n, long long base);
int					pf_unbr_len(unsigned long long n, unsigned long long base);
size_t				pf_wstrlen(wchar_t *str, ssize_t preci);
size_t				ft_wcharlen(wchar_t wc);
size_t				pf_calc_field_len(t_printf *f, ssize_t len);
size_t				ft_strlen(char *s);
ssize_t				pf_atoi(t_printf *f);

long long			pf_va_arg(t_printf *f);
unsigned long long	pf_va_uarg(t_printf *f);

/*
** Convert function
*/

void				pf_d(t_printf *f);
void				pf_s(t_printf *f);
void				pf_ss(t_printf *f);
void				pf_p(t_printf *f);
void				pf_o(t_printf *f);
void				pf_u(t_printf *f);
void				pf_x(t_printf *f);
void				pf_c(t_printf *f);
void				pf_cc(t_printf *f);
void				pf_mod(t_printf *f);
void				pf_b(t_printf *f);

/*
** Color
*/
void				pf_parse_format(t_printf *f);

#endif
