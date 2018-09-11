/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:29:50 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/04 15:14:31 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_strcpy(t_printf *f, char *buffer, char *str)
{
	ssize_t n;

	n = 0;
	if (f->preci == -1)
	{
		f->preci = f->arg_len;
	}
	while (*buffer && *str && n < f->preci)
	{
		*buffer++ = *str++;
		n++;
	}
}
