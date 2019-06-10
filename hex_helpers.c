/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 07:27:14 by chford            #+#    #+#             */
/*   Updated: 2019/06/10 16:31:31 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_used_length(t_format variable, int length, int neg)
{
	int		used_length;

	length = variable.flags & ALTERNATE && variable.spec & O &&
		!(oxx_is_zero(variable)) ? length + 1 : length;
	used_length = length > variable.precision ? length : variable.precision;
	used_length = (neg || variable.flags & PLUS || variable.flags & SPACE) &&
		variable.precision >= 0 && variable.precision >= length
		? used_length + 1 : used_length;
	used_length = variable.flags & ALTERNATE &&
		(variable.spec & X || variable.spec & CX) &&
		!(oxx_is_zero(variable)) ?
		used_length + 2 : used_length;
	return (used_length);
}

void	print_padding(t_format variable, int length, int neg)
{
	int		used_length;

	used_length = get_used_length(variable, length, neg);
	if (variable.flags & ZERO)
	{
		print_digit_prefix(variable, variable.fd, neg);
		while (used_length < variable.width)
		{
			write(variable.fd, "0", 1);
			used_length++;
		}
	}
	else
	{
		while (used_length < variable.width)
		{
			write(variable.fd, " ", 1);
			used_length++;
		}
		if (!(variable.flags & MINUS))
			print_digit_prefix(variable, variable.fd, neg);
	}
}

void	cast_hex_length(t_format variable, int *length)
{
	if (variable.length == 0)
		get_hex_length(*((unsigned int *)variable.value), length);
	else if (variable.length & HH)
		get_hex_length(*((unsigned char *)variable.value), length);
	else if (variable.length & H)
		get_hex_length(*((unsigned short *)variable.value), length);
	else if (variable.length & L)
		get_hex_length(*((unsigned long *)variable.value), length);
	else if (variable.length & LL)
		get_hex_length(*((unsigned long long *)variable.value), length);
}

int		get_diouxx_return(t_format var, int length, int neg)
{
	if (var.flags & ALTERNATE && (var.spec & X || var.spec & CX)
			&& !(oxx_is_zero(var)))
		length += 2;
	else if (var.flags & ALTERNATE && var.spec & O && !(oxx_is_zero(var)))
		length += 1;
	if (var.precision >= 0 && var.precision >= var.width)
	{
		if (var.precision >= length)
		{
			if (neg || var.flags & SPACE || var.flags & PLUS)
				return (var.precision + 1);
			if (var.flags & ALTERNATE &&
					(var.spec & X || var.spec & CX) && !(oxx_is_zero(var)))
				return (var.precision + 2);
			return (var.precision);
		}
		return (length);
	}
	else if (length > var.width)
		return (length);
	return (var.width);
}

void	print_precision_hex(t_format variable, int length, int fd, int neg)
{
	if (variable.spec & O && variable.flags & ALTERNATE &&
			!(oxx_is_zero(variable)))
		variable.precision--;
	if ((neg || variable.flags & SPACE || variable.flags & PLUS)
			&& variable.precision >= length &&
			variable.width > variable.precision)
		write(fd, "0", fd);
	if (variable.flags & ALTERNATE && !(oxx_is_zero(variable)))
		length += 2;
	while (length < variable.precision)
	{
		write(fd, "0", fd);
		length++;
	}
}
