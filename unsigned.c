/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:59:19 by chford            #+#    #+#             */
/*   Updated: 2019/05/13 17:07:00 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_unsigned_length(unsigned long long n, int *length)
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

void	cast_unsigned_length(t_format variable, int *length)
{
	*length = 0;
	if (variable.length == 0)
		get_unsigned_length(*((unsigned int *)variable.value), length);
	else if (variable.length & HH)
		get_unsigned_length(*((unsigned char *)variable.value), length);
	else if (variable.length & H)
		get_unsigned_length(*((unsigned short *)variable.value), length);
	else if (variable.length & L)
		get_unsigned_length(*((unsigned long *)variable.value), length);
	else if (variable.length & LL)
		get_unsigned_length(*((unsigned long long *)variable.value), length);
}

void	print_unsigned(unsigned long long n, int fd)
{
	if (n <= 9)
	{
		ft_putchar_fd((n % 10) + '0', fd);
		return ;
	}
	print_unsigned(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	cast_unsigned(t_format variable, int fd)
{
	if (variable.length == 0)
		print_unsigned(*((unsigned int *)variable.value), fd);
	else if (variable.length & HH)
		print_unsigned(*((unsigned char *)variable.value), fd);
	else if (variable.length & H)
		print_unsigned(*((unsigned short *)variable.value), fd);
	else if (variable.length & L)
		print_unsigned(*((unsigned long *)variable.value), fd);
	else if (variable.length & LL)
		print_unsigned(*((unsigned long long *)variable.value), fd);
}

int		printu(t_format var, int fd)
{
	int		length;

	if ((length = check_d_edge(var, fd)) != -1)
		return (length);
	cast_unsigned_length(var, &length);
	check_minus_and_zero(&var);
	if (var.flags & ZERO && var.precision >= 0)
		var.flags -= ZERO;
	if (var.flags & MINUS)
	{
		print_digit_prefix(var, fd, 0);
		print_precision_hex(var, length, fd, 0);
		cast_unsigned(var, fd);
		print_padding(var, length, 0);
	}
	else
	{
		print_padding(var, length, 0);
		print_precision_hex(var, length, fd, 0);
		cast_unsigned(var, fd);
	}
	return (get_diouxx_return(var, length, 0));
}
