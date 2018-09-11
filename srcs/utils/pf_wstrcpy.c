/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wstrcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:02:03 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 17:29:42 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	cp2(char *buffer, wchar_t *str, size_t *i, size_t *len)
{
	buffer[(*i)++] = (*str >> 6) + 0xC0;
	buffer[(*i)++] = (*str & 0x3F) + 0x80;
	*len = *len - 2;
}

static void	cp3(char *buffer, wchar_t *str, size_t *i, size_t *len)
{
	buffer[(*i)++] = ((*str >> 12) + 0xE0);
	buffer[(*i)++] = ((*str >> 6) & 0x3F) + 0x80;
	buffer[(*i)++] = (*str & 0x3F) + 0x80;
	*len = *len - 3;
}

static void	cp4(char *buffer, wchar_t *str, size_t *i, size_t *len)
{
	buffer[(*i)++] = (*str >> 18) + 0xF0;
	buffer[(*i)++] = ((*str >> 12) & 0x3F) + 0x80;
	buffer[(*i)++] = ((*str >> 6) & 0x3F) + 0x80;
	buffer[(*i)++] = (*str & 0x3F) + 0x80;
	*len = *len - 4;
}

void		pf_wstrcpy(t_printf *f, char *buffer, wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str && f->arg_len && i < f->field_len)
	{
		if (*str <= 0x7F)
		{
			buffer[i++] = *str;
			f->arg_len--;
		}
		else if (*str <= 0x7FF)
			cp2(buffer, str, &i, &(f->arg_len));
		else if (*str <= 0xFFFF)
			cp3(buffer, str, &i, &(f->arg_len));
		else
			cp4(buffer, str, &i, &(f->arg_len));
		str++;
	}
}
