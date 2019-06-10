/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:58:48 by chford            #+#    #+#             */
/*   Updated: 2019/05/16 12:39:10 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_csp_padding(int length, int width, int fd)
{
	while (length < width)
	{
		write(fd, " ", 1);
		length++;
	}
}

int		prints(t_format var, int fd)
{
	char	*nullstr;
	int		len;

	nullstr = 0;
	if (!(char *)var.value)
	{
		nullstr = ft_strnew(6);
		ft_strcpy(nullstr, "(null)");
		var.value = (void *)nullstr;
	}
	len = ft_strlen((char *)var.value);
	len = var.precision >= 0 && var.precision <= len ? var.precision : len;
	if (var.flags & MINUS)
	{
		ft_putstr_constrain_fd((char *)var.value, var.precision, fd);
		print_csp_padding(len, var.width, fd);
	}
	else
	{
		print_csp_padding(len, var.width, fd);
		ft_putstr_constrain_fd((char *)var.value, var.precision, fd);
	}
	if (nullstr)
		free(nullstr);
	return (var.width > len ? var.width : len);
}

int		printpercent(t_format var, int fd)
{
	overwrite_flags(&var);
	if (var.flags & MINUS)
	{
		write(fd, (char *)var.value, 1);
		print_hex_padding(var, 1, fd);
	}
	else
	{
		print_hex_padding(var, 1, fd);
		write(fd, (char *)var.value, 1);
	}
	return (var.width ? var.width : 1);
}

int		printc(t_format var, int fd)
{
	if (var.flags & MINUS)
	{
		write(fd, (char *)var.value, 1);
		print_csp_padding(1, var.width, fd);
	}
	else
	{
		print_csp_padding(1, var.width, fd);
		write(fd, (char *)var.value, 1);
	}
	return (var.width ? var.width : 1);
}

int		printp(t_format var, int fd)
{
	int		length;

	length = 0;
	print_hex_ulong_length((unsigned long)var.value, &length);
	if (var.flags & MINUS)
	{
		write(fd, "0x", 2);
		print_hex_ulong_fd((unsigned long)var.value, fd);
		print_csp_padding(length + 2, var.width, fd);
	}
	else
	{
		print_csp_padding(length + 2, var.width, fd);
		write(fd, "0x", 2);
		print_hex_ulong_fd((unsigned long)var.value, fd);
	}
	return (var.width > length + 2 ? var.width : length + 2);
}
