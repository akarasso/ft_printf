/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:26:29 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/03 05:28:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			modify_case(t_printf *f, char *buffer, ssize_t pos)
{
	if (f->type == 'x' && f->flag.hash)
	{
		if (f->flag.space || f->flag.plus)
			buffer[pos + 3] = 'x';
		else
			buffer[pos + 2] = 'x';
	}
	if (f->type == 'X' && f->flag.hash)
	{
		if (f->flag.space || f->flag.plus)
			buffer[pos + 3] = 'X';
		else
			buffer[pos + 2] = 'X';
	}
	if (f->type == 'p')
	{
		if (f->flag.space || f->flag.plus)
			buffer[pos + 3] = 'x';
		else
			buffer[pos + 2] = 'x';
	}
}

void				pf_itoa_base(t_printf *f,
		char *buffer, unsigned long long n, char *base)
{
	ssize_t				pos;
	size_t				larg;
	unsigned long long	sbase;

	sbase = ft_strlen(base);
	larg = f->arg_len;
	pos = (f->flag.minus) ? f->arg_len - 1 : f->field_len - 1;
	while (larg)
	{
		buffer[pos--] = base[n % sbase];
		n /= sbase;
		--larg;
	}
	modify_case(f, buffer, pos);
	++pos;
	if (f->signed_t)
	{
		if (f->neg)
			buffer[pos--] = '-';
		else if (f->flag.plus)
			buffer[pos--] = '+';
		else if (f->flag.space)
			buffer[pos--] = ' ';
	}
}
