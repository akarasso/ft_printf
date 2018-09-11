/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 13:34:44 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 09:57:41 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_color.h"
#include "ft_printf.h"

static int	test_format(t_printf *f, char *test, char *str)
{
	int size;

	size = ft_strlen(test);
	if (!pf_strncmp(f->str, test, size))
	{
		f->str += size;
		pf_buffer(f, str, ft_strlen(str));
		return (1);
	}
	return (0);
}

static int	test_style(t_printf *f, char *test, char *str)
{
	if (test_format(f, test, str))
	{
		pf_buffer(f, str, ft_strlen(str));
		return (1);
	}
	return (0);
}

int			pf_get_style(t_printf *f)
{
	if (test_style(f, "bold", "\e[1m")
		|| test_style(f, "/bold", "\e[22m")
		|| test_style(f, "italic", "\e[3m")
		|| test_style(f, "/italic", "\e[23m")
		|| test_style(f, "underline", "\e[4m")
		|| test_style(f, "/underline", "\e[24m"))
	{
		while (*f->str && *f->str != ':' && *f->str != '}')
			f->str++;
		return (1);
	}
	return (0);
}

int			pf_get_color(t_printf *f)
{
	if (test_format(f, "/", "\e[39m")
		|| test_format(f, "black", "\e[30m")
		|| test_format(f, "red", "\e[31m")
		|| test_format(f, "green", "\e[32m")
		|| test_format(f, "yellow", "\e[33m")
		|| test_format(f, "blue", "\e[34m")
		|| test_format(f, "purple", "\e[35m")
		|| test_format(f, "cyan", "\e[36m")
		|| test_format(f, "white", "\e[37m")
		|| test_format(f, "lblack", "\e[90m")
		|| test_format(f, "lred", "\e[91m")
		|| test_format(f, "lgreen", "\e[92m")
		|| test_format(f, "lyellow", "\e[93m")
		|| test_format(f, "lblue", "\e[94m")
		|| test_format(f, "lpurple", "\e[95m")
		|| test_format(f, "lcyan", "\e[96m"))
	{
		while (*f->str && *f->str != ':' && *f->str != '}')
			f->str++;
		return (1);
	}
	return (0);
}

int			pf_get_bg_color(t_printf *f)
{
	if (test_format(f, "/bg", "\e[49m")
		|| test_format(f, "bg_black", "\e[40m")
		|| test_format(f, "bg_red", "\e[41m")
		|| test_format(f, "bg_green", "\e[42m")
		|| test_format(f, "bg_yellow", "\e[43m")
		|| test_format(f, "bg_blue", "\e[44m")
		|| test_format(f, "bg_purple", "\e[45m")
		|| test_format(f, "bg_cyan", "\e[46m")
		|| test_format(f, "bg_white", "\e[47m")
		|| test_format(f, "bg_lblack", "\e[100m")
		|| test_format(f, "bg_lred", "\e[101m")
		|| test_format(f, "bg_lgreen", "\e[102m")
		|| test_format(f, "bg_lyellow", "\e[103m")
		|| test_format(f, "bg_lblue", "\e[104m")
		|| test_format(f, "bg_lpurple", "\e[105m")
		|| test_format(f, "bg_lcyan", "\e[106m"))
	{
		while (*f->str && *f->str != ':' && *f->str != '}')
			f->str++;
		return (1);
	}
	return (0);
}
