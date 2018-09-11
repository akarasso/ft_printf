/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 15:28:41 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 08:17:14 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_d(t_printf *f)
{
	intmax_t	n;

	if (f->type == 'D' && f->conv < 3)
		f->conv = 4;
	n = pf_va_arg(f);
	f->neg = (n < 0) ? 1 : 0;
	if (n == 0 && !f->preci)
		f->arg_len = 0;
	else
	{
		if (f->preci > -1 && f->neg)
			++f->preci;
		f->arg_len = pf_max(f->preci, pf_nbr_len(n, 10));
	}
	if (!f->neg && (f->flag.space || f->flag.plus))
		++f->arg_len;
	f->field_len = pf_max(f->arg_len, f->width);
	field(f, n, "0123456789");
}
