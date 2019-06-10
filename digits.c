/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:58:16 by chford            #+#    #+#             */
/*   Updated: 2019/05/16 12:38:06 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_digit(long long n, int fd)
{
	int		num;

	num = ft_absval(n % 10);
	if (n >= -9 && n <= 9)
	{
		ft_putchar_fd(num + '0', fd);
		return ;
	}
	print_digit(n / 10, fd);
	ft_putchar_fd(num + '0', fd);
}

void	cast_digit_length(t_format variable, int *length)
{
	*length = 0;
	if (variable.length == 0)
		get_number_length(*((int *)variable.value), length);
	else if (variable.length & HH)
		get_number_length(*((char *)variable.value), length);
	else if (variable.length & H)
		get_number_length(*((short *)variable.value), length);
	else if (variable.length & L)
		get_number_length(*((long *)variable.value), length);
	else if (variable.length & LL)
		get_number_length(*((long long *)variable.value), length);
}

void	cast_digit(t_format variable, int fd)
{
	if (variable.length == 0)
		print_digit(*((int *)variable.value), fd);
	else if (variable.length & HH)
		print_digit(*((char *)variable.value), fd);
	else if (variable.length & H)
		print_digit(*((short *)variable.value), fd);
	else if (variable.length & L)
		print_digit(*((long *)variable.value), fd);
	else if (variable.length & LL)
		print_digit(*((long long *)variable.value), fd);
}

int		check_d_edge(t_format var, int fd)
{
	int		length;

	length = var.width;
	if (oxx_is_zero(var) && var.precision == 0)
	{
		if (var.width == 0 && !(var.flags & PLUS))
			return (d_only_zero(var, fd));
		if (var.flags & MINUS && var.flags & PLUS)
			length -= write(fd, "+", 1);
		else if (var.flags & MINUS && var.spec == O && var.flags & ALTERNATE)
			length -= write(fd, "0", 1);
		else if (var.flags & PLUS || (var.spec == O && var.flags & ALTERNATE))
			length--;
		while (length-- > 0)
			write(fd, " ", 1);
		if (!(var.flags & MINUS) && var.flags & PLUS)
			write(fd, "+", 1);
		else if (!(var.flags & MINUS) && var.flags & ALTERNATE && var.spec == O)
			write(fd, "0", 1);
		length = var.width;
		if (!length && var.flags & PLUS)
			length++;
		return (length);
	}
	return (-1);
}

int		printd(t_format var, int fd)
{
	int		length;
	int		neg;

	if ((length = check_d_edge(var, fd)) != -1)
		return (length);
	cast_digit_length(var, &length);
	check_minus_and_zero(&var);
	neg = is_negative_digit(var, &length);
	if (var.flags & ZERO && var.precision >= 0)
		var.flags -= ZERO;
	if (var.flags & MINUS)
	{
		print_digit_prefix(var, fd, neg);
		print_precision_hex(var, length, fd, neg);
		cast_digit(var, fd);
		print_padding(var, length, neg);
	}
	else
	{
		print_padding(var, length, neg);
		print_precision_hex(var, length, fd, neg);
		cast_digit(var, fd);
	}
	return (get_diouxx_return(var, length, neg));
}
