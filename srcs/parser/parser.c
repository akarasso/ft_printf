/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:18:53 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 10:00:07 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_get_flag(t_printf *f)
{
	while (*f->str && (*f->str == '-' || *f->str == '+' || *f->str == ' '
			|| *f->str == '0' || *f->str == '#'))
	{
		if (*f->str == '-')
			f->flag.minus = 1;
		if (*f->str == '+')
			f->flag.plus = 1;
		if (*f->str == ' ')
			f->flag.space = 1;
		if (*f->str == '0')
			f->flag.zero = 1;
		if (*f->str == '#')
			f->flag.hash = 1;
		f->str++;
	}
}

static void			pf_get_width_preci(t_printf *f)
{
	f->width = pf_atoi(f);
	if (*f->str == '*')
	{
		if ((f->width = va_arg(f->args, int)) < 0)
		{
			f->flag.minus = 1;
			f->width = -(f->width);
		}
		++f->str;
	}
	if (*f->str >= '0' && *f->str <= '9')
		f->width = pf_atoi(f);
	if (*f->str == '.')
	{
		f->str++;
		f->preci = pf_atoi(f);
		if (*f->str == '*')
		{
			++f->str;
			if ((f->preci = va_arg(f->args, int)) < 0)
				f->preci = -1;
		}
		if (*f->str >= '0' && *f->str <= '9')
			f->preci = pf_atoi(f);
	}
}

static void			pf_get_conv(t_printf *f)
{
	while (*f->str && (*f->str == 'h' || *f->str == 'l' || *f->str == 'L'
		|| *f->str == 'z' || *f->str == 'j' || *f->str == 't'))
	{
		if (*f->str == 'h' && *(f->str + 1) == 'h' && f->conv < 1)
			f->conv = 1;
		if (*f->str == 'h' && *(f->str + 1) != 'h' && f->conv < 2)
			f->conv = 2;
		if (*f->str == 'l' && *(f->str + 1) != 'l' && f->conv < 3)
			f->conv = 3;
		if (*f->str == 'l' && *(f->str + 1) == 'l' && f->conv < 4)
			f->conv = 4;
		if (*f->str == 'L' && f->conv < 5)
			f->conv = 5;
		if (*f->str == 'z' && f->conv < 6)
			f->conv = 6;
		if (*f->str == 'j' && f->conv < 7)
			f->conv = 7;
		if (*f->str == 't' && f->conv < 8)
			f->conv = 8;
		if (f->conv)
			(f->conv == 1 || f->conv == 4) ? f->str += 2 : f->str++;
		else
			return ;
	}
}

static void			pf_get_type(t_printf *f)
{
	if (*f->str == 'p' || *f->str == 'd' || *f->str == 'D'
		|| *f->str == 'i' || *f->str == 'o'
		|| *f->str == 'O' || *f->str == 'u' || *f->str == 'U'
		|| *f->str == 'x' || *f->str == 'X'
		|| *f->str == 'b' || *f->str == 'f' || *f->str == 'F')
	{
		if ((f->flag.minus || f->preci > -1))
			f->flag.zero = 0;
		f->type = *f->str;
		++f->str;
	}
	else if (*f->str)
	{
		f->type = *f->str;
		++f->str;
	}
}

void				parse(t_printf *f)
{
	f->flag.minus = 0;
	f->flag.plus = 0;
	f->flag.space = 0;
	f->flag.zero = 0;
	f->flag.hash = 0;
	f->signed_t = 1;
	f->width = -1;
	f->preci = -1;
	f->conv = 0;
	f->type = 0;
	f->neg = 0;
	f->arg_len = 0;
	f->field_len = 0;
	pf_get_flag(f);
	pf_get_width_preci(f);
	pf_get_conv(f);
	pf_get_type(f);
	if (!f->flag.minus && f->flag.zero && f->width > -1 && f->preci == -1)
		f->preci = f->width - 1;
	convert(f);
}
