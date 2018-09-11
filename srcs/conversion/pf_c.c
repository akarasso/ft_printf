/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 15:29:48 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 08:24:01 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pf_c(t_printf *f)
{
	char	c;

	if (f->type == 'c' && f->conv == 3)
		return (pf_cc(f));
	c = pf_va_arg(f);
	f->arg_len = 1;
	f->field_len = pf_max(f->arg_len, f->width);
	char_field(f, c);
}
