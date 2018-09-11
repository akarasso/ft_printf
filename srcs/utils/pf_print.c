/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:25:30 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/01 08:20:23 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_strlen(char *s)
{
	char *end;

	end = s;
	while (*end)
		end++;
	return (end - s);
}

void			pf_clear_buffer(t_printf *f)
{
	write(1, f->buffer, f->ibuffer);
	f->ibuffer = 0;
}

void			pf_putnstr(t_printf *f, char *s, size_t len)
{
	f->printed += len;
	pf_buffer(f, s, len);
}

void			pf_putstr(t_printf *f, char *s)
{
	size_t len;

	len = ft_strlen(s);
	pf_putnstr(f, s, len);
}
