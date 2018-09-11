/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:26:16 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/29 14:26:20 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_buffer(t_printf *f, char *s, size_t len)
{
	while (len)
	{
		if (f->ibuffer < PF_BUFF)
		{
			f->buffer[f->ibuffer] = *s;
			f->ibuffer++;
			s++;
			len--;
		}
		else
		{
			write(1, f->buffer, PF_BUFF);
			f->ibuffer = 0;
		}
	}
}
