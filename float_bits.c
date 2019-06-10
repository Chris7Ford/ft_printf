/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 10:03:19 by chford            #+#    #+#             */
/*   Updated: 2019/05/16 13:00:44 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_f_edge(t_format var, int exponent, char *mantissa, int fd)
{
	t_unholy_d	unholy_d;

	if (!(var.length & CL) && exponent == 1024)
	{
		unholy_d.d = *((double *)var.value);
		if (ft_strcmp(mantissa, "0") == 0)
		{
			if (unholy_d.l >> 63)
			{
				ft_putstr_fd("-inf", fd);
				return (4);
			}
			ft_putstr_fd("inf", fd);
			return (3);
		}
		else
		{
			ft_putstr_fd("nan", fd);
			return (3);
		}
	}
	return (0);
}

char	*get_mantissa_d(t_format var)
{
	unsigned long long	big;
	t_unholy_d			unholy_d;
	t_unholy_l			unholy_l;
	int					index;

	if (!(var.length & CL))
	{
		unholy_d.d = *((double *)var.value);
		return (ft_lltoa((long long)(unholy_d.l & 4503599627370495)));
	}
	else
	{
		unholy_l.d = *((long double *)var.value);
		index = 7;
		big = 0;
		while (index > 0)
		{
			big += unholy_l.l[index];
			big <<= 8;
			index--;
		}
		big += unholy_l.l[index];
		return (ft_ulltoa(big));
	}
}

int		get_exponent_d(t_format var)
{
	t_unholy_d	unholy_d;
	t_unholy_l	unholy_l;
	int			num;

	if (!(var.length & CL))
	{
		unholy_d.d = *((double *)var.value);
		return (((unholy_d.l & 9218868437227405312) >> 52) - 1023);
	}
	unholy_l.d = *((long double *)var.value);
	num = unholy_l.l[9] & 127;
	num <<= 8;
	num += unholy_l.l[8];
	num -= 16383;
	return (num);
}
