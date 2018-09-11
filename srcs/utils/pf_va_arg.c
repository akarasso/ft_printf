/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_va_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:25:01 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/06 08:56:44 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long		pf_va_uarg(t_printf *f)
{
	if (f->conv == 1)
		return ((unsigned char)va_arg(f->args, unsigned int));
	if (f->conv == 2)
		return ((unsigned short)va_arg(f->args, unsigned int));
	if (f->conv == 3)
		return (va_arg(f->args, unsigned long));
	if (f->conv == 4 || f->conv == 6)
		return (va_arg(f->args, unsigned long long));
	if (f->conv == 7)
		return (va_arg(f->args, uintmax_t));
	return (va_arg(f->args, unsigned int));
}

long long				pf_va_arg(t_printf *f)
{
	if (f->conv == 1)
		return ((char)va_arg(f->args, int));
	if (f->conv == 2)
		return ((short)va_arg(f->args, int));
	if (f->conv == 3)
		return (va_arg(f->args, long int));
	if (f->conv == 4)
		return (va_arg(f->args, long long int));
	if (f->conv == 5)
		return (va_arg(f->args, long double));
	if (f->conv == 7)
		return (va_arg(f->args, intmax_t));
	if (f->conv == 8)
		return (va_arg(f->args, ptrdiff_t));
	if (f->conv == 6)
		return (va_arg(f->args, size_t));
	return (va_arg(f->args, int));
}
