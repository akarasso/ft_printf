/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_calc_field_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:30:01 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/29 14:30:18 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_calc_field_len(t_printf *f, ssize_t len)
{
	size_t len_field;

	len_field = 0;
	if (len >= f->width && len > f->preci)
	{
		len_field = len;
		if (f->flag.plus || f->flag.space)
			len_field++;
	}
	else
	{
		len_field = (f->width < f->preci) ? f->preci : f->width;
		if (f->preci >= f->width &&
			(f->flag.plus || f->flag.space || f->neg))
		{
			len_field++;
		}
	}
	return (len_field);
}
