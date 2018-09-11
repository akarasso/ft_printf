/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 07:11:27 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 07:11:47 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wcharlen(wchar_t wc)
{
	if (wc < 0x80)
		return (1);
	else if (wc < 0x800)
		return (2);
	else if (wc < 0x10000)
		return (3);
	return (4);
}
