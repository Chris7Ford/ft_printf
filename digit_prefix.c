/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:16:16 by chford            #+#    #+#             */
/*   Updated: 2019/05/16 12:38:16 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_digit_prefix(t_format var, int fd, int neg)
{
	if (!neg)
	{
		if (var.flags & PLUS)
			write(fd, "+", 1);
		else if (var.flags & SPACE)
			write(fd, " ", 1);
	}
	else
		write(fd, "-", 1);
	if (var.flags & ALTERNATE && var.spec == X && !(oxx_is_zero(var)))
		write(fd, "0x", 2);
	else if (var.flags & ALTERNATE && var.spec == CX && !(oxx_is_zero(var)))
		write(fd, "0X", 2);
	else if (var.flags & ALTERNATE && var.spec == O && !(oxx_is_zero(var)))
		write(fd, "0", 1);
}

int		d_only_zero(t_format var, int fd)
{
	if (var.spec & O && var.flags & ALTERNATE && write(fd, "0", 1))
		return (1);
	return (0);
}

int		is_negative_digit(t_format variable, int *length)
{
	if ((variable.length == 0 && *((int *)variable.value) < 0) ||
		(variable.length == HH && *((char *)variable.value) < 0) ||
			(variable.length == H && *((short *)variable.value) < 0) ||
			(variable.length == L && *((long *)variable.value) < 0) ||
			(variable.length == LL && *((long long *)variable.value) < 0))
	{
		if (variable.width > variable.precision
				|| *length >= variable.precision)
			*length += 1;
		return (1);
	}
	if (variable.flags & PLUS && (variable.width > variable.precision
				|| *length > variable.precision))
		*length += 1;
	else if (variable.flags & SPACE && (variable.width > variable.precision
				|| *length > variable.precision))
		*length += 1;
	return (0);
}
