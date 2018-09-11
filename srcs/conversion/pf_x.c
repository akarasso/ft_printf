/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:31:07 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 10:03:14 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			norm(t_printf *f)
{
	f->flag.space = 0;
	f->flag.plus = 0;
}

void				pf_x(t_printf *f)
{
	uintmax_t	n;

	norm(f);
	n = pf_va_uarg(f);
	if (n == 0 && f->preci == 0)
		f->arg_len = 0;
	else if (f->flag.hash)
	{
		if (n == 0)
			f->arg_len = 1;
		else
		{
			if (f->flag.zero)
				f->arg_len = pf_max(f->preci, pf_unbr_len(n, 16)) + 1;
			else
				f->arg_len = pf_max(f->preci, pf_unbr_len(n, 16)) + 2;
		}
	}
	else
		f->arg_len = pf_max(f->preci, pf_unbr_len(n, 16));
	f->field_len = pf_max(f->arg_len, f->width);
	if (f->type == 'x')
		ufield(f, n, "0123456789abcdef");
	else
		ufield(f, n, "0123456789ABCDEF");
}
