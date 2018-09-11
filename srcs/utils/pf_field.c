/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_field.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 04:25:16 by root              #+#    #+#             */
/*   Updated: 2018/05/05 09:54:19 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		wstr_field(t_printf *f, wchar_t *c)
{
	char	buffer[f->field_len + 1];
	size_t	index;

	index = 0;
	while (index < f->field_len)
		buffer[index++] = (f->flag.zero) ? '0' : ' ';
	buffer[f->field_len] = 0;
	if (*c)
	{
		if (f->flag.minus)
			pf_wstrcpy(f, &buffer[0], c);
		else
			pf_wstrcpy(f, &buffer[index - f->arg_len], c);
	}
	else
		buffer[0] = 0;
	pf_putnstr(f, buffer, f->field_len);
}

void		str_field(t_printf *f, char *str)
{
	char		buffer[f->field_len + 1];
	size_t		index;

	index = 0;
	while (index < f->field_len)
		buffer[index++] = (f->flag.zero) ? '0' : ' ';
	buffer[f->field_len] = 0;
	if (f->flag.minus)
		pf_strcpy(f, &buffer[0], str);
	else
		pf_strcpy(f, &buffer[index - f->arg_len], str);
	pf_putnstr(f, buffer, f->field_len);
}

void		char_field(t_printf *f, char c)
{
	char	buffer[f->field_len + 1];
	size_t	index;

	index = 0;
	while (index < f->field_len)
		buffer[index++] = (f->flag.zero) ? '0' : ' ';
	buffer[f->field_len] = 0;
	if (f->flag.minus)
		buffer[0] = c;
	else
		buffer[index - 1] = c;
	pf_putnstr(f, buffer, f->field_len);
}

void		field(t_printf *f, intmax_t n, char *charset)
{
	char		buffer[f->field_len + 1];
	size_t		index;

	index = 0;
	while (index < f->field_len)
		buffer[index++] = (f->flag.zero) ? '0' : ' ';
	buffer[f->field_len] = 0;
	pf_itoa_base(f, buffer, ABS(n), charset);
	pf_putnstr(f, buffer, f->field_len);
}

void		ufield(t_printf *f, uintmax_t n, char *charset)
{
	char		buffer[f->field_len + 1];
	size_t		index;

	index = 0;
	while (index < f->field_len)
		buffer[index++] = (f->flag.zero) ? '0' : ' ';
	buffer[f->field_len] = 0;
	pf_itoa_base(f, buffer, n, charset);
	pf_putnstr(f, buffer, f->field_len);
}
