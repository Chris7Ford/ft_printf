/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:07:24 by chford            #+#    #+#             */
/*   Updated: 2019/05/10 10:47:56 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(char *str, va_list list, int fd)
{
	int		count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			count += handle_variable(&str, fd, list);
		else
			count += write(fd, str++, 1);
	}
	return (count);
}
