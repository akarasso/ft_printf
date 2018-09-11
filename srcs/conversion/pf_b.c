/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 09:15:28 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 10:04:53 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pf_b(t_printf *f)
{
	uintmax_t	n;

	if (f->type == 'O' && f->conv < 4)
		f->conv = 4;
	n = pf_va_uarg(f);
	f->flag.plus = 0;
	f->flag.space = 0;
	f->arg_len = pf_max(f->preci, pf_unbr_len(n, 2));
	f->field_len = pf_max(f->arg_len, f->width);
	ufield(f, n, "01");
}
