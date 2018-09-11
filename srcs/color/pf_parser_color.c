/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 11:34:19 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 09:55:10 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_color.h"

void	pf_parse_format(t_printf *f)
{
	while (*f->str && *f->str != '}')
	{
		if (*f->str == ':')
			f->str++;
		if (!pf_get_bg_color(f) && !pf_get_style(f) && !pf_get_color(f))
		{
			if (!pf_strncmp(f->str, "clr", 3))
			{
				pf_buffer(f, "\e[0m", 5);
				f->str += 3;
			}
			else
				f->str++;
		}
	}
	if (*f->str && *f->str == '}')
		f->str++;
}
