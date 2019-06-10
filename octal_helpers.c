/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 06:30:01 by chford            #+#    #+#             */
/*   Updated: 2019/04/29 06:39:50 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cast_octal_length(t_format variable, int *length)
{
	*length = 0;
	if (variable.length == 0)
		get_octal_length(*((unsigned int *)variable.value), length);
	else if (variable.length & HH)
		get_octal_length(*((unsigned char *)variable.value), length);
	else if (variable.length & H)
		get_octal_length(*((unsigned short *)variable.value), length);
	else if (variable.length & L)
		get_octal_length(*((unsigned long *)variable.value), length);
	else if (variable.length & LL)
		get_octal_length(*((unsigned long long *)variable.value), length);
}
