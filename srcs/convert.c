/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:28:00 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/06 08:58:10 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert(t_printf *f)
{
	if (f->type == 'd' || f->type == 'D' || f->type == 'i')
		pf_d(f);
	else if (f->type == 's')
		pf_s(f);
	else if (f->type == 'S')
		pf_ss(f);
	else if (f->type == 'p')
		pf_p(f);
	else if (f->type == 'o' || f->type == 'O')
		pf_o(f);
	else if (f->type == 'u' || f->type == 'U')
		pf_u(f);
	else if (f->type == 'x' || f->type == 'X')
		pf_x(f);
	else if (f->type == 'c')
		pf_c(f);
	else if (f->type == 'C')
		pf_cc(f);
	else if (f->type == 'b')
		pf_b(f);
	else
		pf_mod(f);
}
