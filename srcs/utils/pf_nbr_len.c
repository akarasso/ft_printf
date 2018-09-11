/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 14:30:23 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/05 09:54:43 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_unbr_len(unsigned long long n, unsigned long long base)
{
	int len;

	len = (!n) ? 1 : 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	pf_nbr_len(long long n, long long base)
{
	int len;

	len = (n <= 0) ? 1 : 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}
