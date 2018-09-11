/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 15:24:11 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 10:04:05 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pf_s(t_printf *f)
{
	char	*str;

	if (f->type == 's' && f->conv == 3)
		return (pf_ss(f));
	str = (char *)va_arg(f->args, char *);
	if (!str)
		str = "(null)";
	if (f->preci == -1)
		f->arg_len = ft_strlen(str);
	else
		f->arg_len = pf_min(f->preci, ft_strlen(str));
	f->field_len = pf_max(f->arg_len, f->width);
	str_field(f, str);
}
