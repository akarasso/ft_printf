/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_color.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <akarasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 11:49:48 by akarasso          #+#    #+#             */
/*   Updated: 2018/05/06 09:01:47 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_COLOR_H
# define FT_PRINTF_COLOR_H
# include "ft_printf.h"

int		pf_get_color(t_printf *f);
int		pf_get_bg_color(t_printf *f);
int		pf_get_style(t_printf *f);

#endif
