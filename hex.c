/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:26:50 by chford            #+#    #+#             */
/*   Updated: 2019/05/16 11:43:00 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_hex_length(unsigned long long n, int *length)
{
	if (n == 0)
	{
		*length += 1;
		return ;
	}
	if (n < 16)
	{
		*length += 1;
		return ;
	}
	get_hex_length(n / 16, length);
	*length += 1;
}

void	print_hex(unsigned long long n, int c, int fd)
{
	char	*array;

	if (c == X)
		array = "0123456789abcdef";
	else
		array = "0123456789ABCDEF";
	if (n < 16)
	{
		write(fd, &(array[n]), 1);
		return ;
	}
	print_hex(n / 16, c, fd);
	write(fd, &(array[n % 16]), 1);
}

void	cast_hex(t_format variable, int fd)
{
	if (variable.length == 0)
		print_hex(*((unsigned int *)variable.value), variable.spec, fd);
	else if (variable.length & HH)
		print_hex(*((unsigned char *)variable.value), variable.spec, fd);
	else if (variable.length & H)
		print_hex(*((unsigned short *)variable.value), variable.spec, fd);
	else if (variable.length & L)
		print_hex(*((unsigned long *)variable.value), variable.spec, fd);
	else if (variable.length & LL)
		print_hex(*((unsigned long long *)variable.value), variable.spec, fd);
}

int		oxx_is_zero(t_format var)
{
	if ((var.length == 0 && *((int *)var.value) == 0) ||
			(var.length & HH && *((unsigned char *)var.value) == 0) ||
			(var.length & H && *((unsigned short *)var.value) == 0) ||
			(var.length & L && *((unsigned long *)var.value) == 0) ||
			(var.length & LL && *((unsigned long long *)var.value) == 0))
		return (1);
	return (0);
}

int		printxx(t_format var, int fd)
{
	int		length;

	if ((length = check_d_edge(var, fd)) != -1)
		return (length);
	length = 0;
	cast_hex_length(var, &length);
	check_minus_and_zero(&var);
	if (var.flags & ZERO && var.precision >= 0)
		var.flags -= ZERO;
	if (var.flags & MINUS)
	{
		print_digit_prefix(var, fd, 0);
		print_precision_hex(var, var.flags & ALTERNATE &&
				!(oxx_is_zero(var)) ? length - 2 : length, fd, 0);
		cast_hex(var, fd);
		print_padding(var, length, 0);
	}
	else
	{
		print_padding(var, length, 0);
		print_precision_hex(var, var.flags & ALTERNATE &&
				!(oxx_is_zero(var)) ? length - 2 : length, fd, 0);
		cast_hex(var, fd);
	}
	return (get_diouxx_return(var, length, 0));
}
