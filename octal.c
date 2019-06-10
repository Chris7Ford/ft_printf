/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:21:36 by chford            #+#    #+#             */
/*   Updated: 2019/05/16 11:24:03 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_octal_length(unsigned long long n, int *length)
{
	if (n == 0)
	{
		*length += 1;
		return ;
	}
	while (n)
	{
		*length += 1;
		n >>= 3;
	}
}

void	print_octal(unsigned long long n, int fd)
{
	if (n <= 7)
	{
		ft_putchar_fd((n & 7) + '0', fd);
		return ;
	}
	print_octal(n >> 3, fd);
	ft_putchar_fd((n & 7) + '0', fd);
}

void	add_octal_prefix(t_format *variable, int fd)
{
	if (variable->flags & ALTERNATE)
	{
		if (variable->spec == 'o')
			write(fd, "0", 1);
	}
}

void	cast_octal(t_format variable, int fd)
{
	if (variable.length == 0)
		print_octal(*((unsigned int *)variable.value), fd);
	else if (variable.length & HH)
		print_octal(*((unsigned char *)variable.value), fd);
	else if (variable.length & H)
		print_octal(*((unsigned short *)variable.value), fd);
	else if (variable.length & L)
		print_octal(*((unsigned long *)variable.value), fd);
	else if (variable.length & LL)
		print_octal(*((unsigned long long *)variable.value), fd);
}

int		printo(t_format var, int fd)
{
	int		length;

	if ((length = check_d_edge(var, fd)) != -1)
		return (length);
	length = 0;
	cast_octal_length(var, &length);
	check_minus_and_zero(&var);
	if (var.flags & ZERO && var.precision >= 0)
		var.flags -= ZERO;
	if (var.flags & MINUS)
	{
		print_digit_prefix(var, fd, 0);
		print_precision_hex(var, var.flags & ALTERNATE &&
				!(oxx_is_zero(var)) ? length - 2 : length, fd, 0);
		cast_octal(var, fd);
		print_padding(var, length, 0);
	}
	else
	{
		print_padding(var, length, 0);
		print_precision_hex(var, var.flags & ALTERNATE &&
				!(oxx_is_zero(var)) ? length - 2 : length, fd, 0);
		cast_octal(var, fd);
	}
	return (get_diouxx_return(var, length, 0));
}
