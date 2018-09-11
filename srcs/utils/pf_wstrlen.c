/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 15:07:40 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/06 09:10:34 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		pf_wstrnlen(wchar_t *str, ssize_t preci)
{
	ssize_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F && i + 1 <= preci)
			i++;
		else if (*str <= 0x7FF && i + 2 <= preci)
			i += 2;
		else if (*str <= 0xFFFF && i + 3 <= preci)
			i += 3;
		else if (*str <= 0x10FFFF && i + 4 <= preci)
			i += 4;
		else
			break ;
		++str;
	}
	return (i);
}

size_t				pf_wstrlen(wchar_t *str, ssize_t preci)
{
	ssize_t i;

	if (preci != -1)
		return (pf_wstrnlen(str, preci));
	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		++str;
	}
	return (i);
}
