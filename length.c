/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:53:49 by chford            #+#    #+#             */
/*   Updated: 2019/05/10 10:39:48 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_l_ll(char **str, t_format *variable)
{
	if (**str == 'l')
	{
		if (*(*str + 1) == 'l')
		{
			variable->length = LL;
			(*str)++;
		}
		else
			variable->length = L;
		(*str)++;
		return (1);
	}
	return (0);
}

int		check_h_hh(char **str, t_format *variable)
{
	if (**str == 'h')
	{
		if (*(*str + 1) == 'h')
		{
			variable->length = HH;
			(*str)++;
		}
		else
			variable->length = H;
		(*str)++;
		return (1);
	}
	return (0);
}

int		check_cl(char **str, t_format *variable)
{
	if (**str == 'L')
	{
		variable->length = CL;
		(*str)++;
		return (1);
	}
	return (0);
}
