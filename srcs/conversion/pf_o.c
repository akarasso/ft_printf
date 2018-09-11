/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 15:20:10 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 08:17:35 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pf_o(t_printf *f)
{
	uintmax_t	n;

	if (f->type == 'O' && f->conv < 4)
		f->conv = 4;
	n = pf_va_uarg(f);
	f->flag.plus = 0;
	f->flag.space = 0;
	if (n == 0 && f->preci == 0)
		f->arg_len = f->flag.hash;
	else if (f->flag.hash && n != 0)
		f->arg_len = pf_max(f->preci, pf_unbr_len(n, 8) + 1);
	else
		f->arg_len = pf_max(f->preci, pf_unbr_len(n, 8));
	f->field_len = pf_max(f->arg_len, f->width);
	ufield(f, n, "01234567");
}
