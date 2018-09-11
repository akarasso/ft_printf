/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 15:28:02 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/06 09:08:16 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		check_plage(wchar_t c)
{
	if (c > 0x10FFFF || c < 0 || (c > 0xd7ff && c < 0xe000))
		return (1);
	return (0);
}

static int		check(wchar_t c)
{
	if (MB_CUR_MAX == 1 && c > 255)
		return (0);
	if (MB_CUR_MAX == 1 && c <= 255)
		return (1);
	if (c < 255 && c > 127)
		return (0);
	if (check_plage(c) || c == 0xffef || c == 0xffff || c == 3250)
		return (0);
	return (1);
}

void			pf_cc(t_printf *f)
{
	int		clen;
	wchar_t	c;

	c = va_arg(f->args, wchar_t);
	clen = 1;
	if (c > 0x7F)
		++clen;
	if (c > 0x7FF)
		++clen;
	if (c > 0xFFFF)
		++clen;
	if (check_plage(c))
		f->noprint = 1;
	if (!check(c) || clen > MB_CUR_MAX)
		f->error = 1;
	f->arg_len = clen;
	f->field_len = pf_max(f->width, clen);
	wstr_field(f, &c);
}
