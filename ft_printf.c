/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:05:48 by chford            #+#    #+#             */
/*   Updated: 2019/05/15 16:41:38 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		list;
	int			count;

	if (str == 0)
		return (0);
	va_start(list, str);
	count = print_string((char *)str, list, 1);
	va_end(list);
	return (count);
}

int		ft_printf_fd(int fd, const char *str, ...)
{
	va_list		list;
	int			count;

	if (str == 0)
		return (0);
	va_start(list, str);
	count = print_string((char *)str, list, fd);
	va_end(list);
	return (count);
}
