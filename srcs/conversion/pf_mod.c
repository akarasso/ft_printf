/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 15:29:29 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 08:17:25 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pf_mod(t_printf *f)
{
	if (f->type)
	{
		f->arg_len = 1;
		f->field_len = pf_max(f->width, f->arg_len);
		char_field(f, f->type);
	}
}
