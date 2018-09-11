/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 09:25:38 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/06 09:01:28 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_init(t_printf *info, const char *src)
{
	info->str = src;
	info->ibuffer = 0;
	info->printed = 0;
	info->error = 0;
	info->noprint = 0;
	info->buffer[PF_BUFF] = 0;
}

static void	pf_percent(t_printf *info)
{
	++info->str;
	parse(info);
}

int			ft_printf(const char *src, ...)
{
	t_printf	info;

	pf_init(&info, src);
	va_start(info.args, src);
	while (*info.str && !info.error)
	{
		if (*info.str == '%')
		{
			pf_percent(&info);
		}
		else if (*info.str == '{' && (*(info.str + 1) == ':'
					|| *(info.str + 1) == '/'))
		{
			++info.str;
			pf_parse_format(&info);
		}
		else
			pf_putnstr(&info, (char *)info.str++, 1);
	}
	if (!info.noprint)
		pf_clear_buffer(&info);
	va_end(info.args);
	return (info.error) ? -1 : info.printed;
}
