/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 15:25:46 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 10:04:14 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pf_p(t_printf *f)
{
	uintmax_t	n;

	if (f->conv < 3)
		f->conv = 4;
	n = pf_va_uarg(f);
	f->flag.plus = 0;
	if (f->flag.space)
		f->flag.space = 0;
	if (n == 0 && f->preci == 0)
		f->arg_len = 2;
	else
	{
		f->arg_len = pf_max(f->preci, pf_unbr_len(n, 16)) + 2;
		if (f->flag.zero && n == 0)
			--f->arg_len;
	}
	f->field_len = pf_max(f->arg_len, f->width);
	ufield(f, n, "0123456789abcdef");
}
