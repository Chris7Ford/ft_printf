/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_helpers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:40:57 by chford            #+#    #+#             */
/*   Updated: 2019/05/16 12:44:04 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_hex_prefix(t_format *variable, int fd, int *length)
{
	if (variable->flags & ALTERNATE)
	{
		if (variable->spec == X)
			write(fd, "0x", 2);
		else if (variable->spec == CX)
			write(fd, "0X", 2);
		*length += 2;
	}
}

void	print_hex_padding(t_format variable, int length, int fd)
{
	int	used_length;

	used_length = length > variable.precision ? length : variable.precision;
	if (variable.flags & ZERO)
	{
		while (used_length < variable.width)
		{
			write(fd, "0", 1);
			used_length++;
		}
	}
	else
	{
		while (used_length < variable.width)
		{
			write(fd, " ", 1);
			used_length++;
		}
	}
}

void	check_minus_and_zero(t_format *variable)
{
	if (variable->flags & ZERO && variable->flags & MINUS)
		variable->flags -= ZERO;
}
