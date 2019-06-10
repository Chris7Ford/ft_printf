/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:26:54 by chford            #+#    #+#             */
/*   Updated: 2019/05/11 10:15:49 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_nbr_len(long long n)
{
	int		length;

	length = 0;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

void	overwrite_flags(t_format *variable)
{
	if (variable->flags & PLUS && variable->flags & SPACE)
		variable->flags = variable->flags - SPACE;
	check_minus_and_zero(variable);
}

void	get_number_length(long long n, int *length)
{
	if (n == 0)
	{
		*length += 1;
		return ;
	}
	while (n)
	{
		*length += 1;
		n /= 10;
	}
}
