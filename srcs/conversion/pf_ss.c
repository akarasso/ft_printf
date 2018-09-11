/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:33:06 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/06 09:12:01 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_plage(t_printf *f, wchar_t c)
{
	if (c > 0x10FFFF || c < 0 || (c > 0xd7ff && c < 0xe000))
	{
		f->noprint = 1;
		return (1);
	}
	return (0);
}

static int		check(t_printf *f, wchar_t c)
{
	if (MB_CUR_MAX == 1 && c > 255)
		return (0);
	if (MB_CUR_MAX == 1 && c <= 255)
		return (1);
	if (c < 255 && c > 127)
		return (0);
	if (check_plage(f, c) || c == 0xffef || c == 0xffff || c == 3250)
		return (0);
	return (1);
}

static int		checkwstr(t_printf *f, wchar_t *str)
{
	while (*str)
	{
		if (!check(f, *str))
			return (0);
		str++;
	}
	return (1);
}

void			pf_ss(t_printf *f)
{
	wchar_t *s;
	ssize_t	slen;

	s = (wchar_t *)va_arg(f->args, wchar_t *);
	if (!s)
		s = L"(null)";
	if (!checkwstr(f, s))
		f->error = 1;
	slen = pf_wstrlen(s, f->preci);
	f->arg_len = slen;
	f->field_len = pf_max(f->width, slen);
	wstr_field(f, s);
}
