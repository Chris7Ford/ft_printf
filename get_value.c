/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:46:43 by chford            #+#    #+#             */
/*   Updated: 2019/05/16 12:45:15 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_c(va_list list, t_format *variable)
{
	char	*c;

	c = (char *)malloc(sizeof(char));
	*c = va_arg(list, int);
	variable->value = (void *)(c);
}

void	get_sp(va_list list, t_format *variable)
{
	void	*ptr;

	ptr = (void *)(va_arg(list, void *));
	variable->value = ptr;
}

void	get_diouxx2(va_list list, t_format *variable)
{
	long long		*ll;
	long			*l;
	int				*i;

	if (variable->length & LL)
	{
		ll = (long long *)malloc(sizeof(long long));
		*ll = va_arg(list, long long);
		variable->value = (void *)(ll);
	}
	else if (variable->length & L)
	{
		l = (long *)malloc(sizeof(long));
		*l = va_arg(list, long);
		variable->value = (void *)(l);
	}
	else
	{
		i = (int *)malloc(sizeof(int));
		*i = va_arg(list, int);
		variable->value = (void *)(i);
	}
}

void	get_diouxx(va_list list, t_format *variable)
{
	unsigned short	*s;
	unsigned char	*c;

	if (variable->length & HH)
	{
		c = (unsigned char *)malloc(sizeof(char));
		*c = va_arg(list, int);
		variable->value = (void *)(c);
	}
	else if (variable->length & H)
	{
		s = (unsigned short *)malloc(sizeof(short));
		*s = va_arg(list, int);
		variable->value = (void *)(s);
	}
	else
		get_diouxx2(list, variable);
}

void	get_f(va_list list, t_format *variable)
{
	long double	*ld;
	double		*df;

	if (variable->length & L)
	{
		df = (double *)malloc(sizeof(double));
		*df = va_arg(list, double);
		variable->value = (void *)(df);
	}
	else if (variable->length & CL)
	{
		ld = (long double *)malloc(sizeof(long double));
		*ld = va_arg(list, long double);
		variable->value = (void *)(ld);
	}
	else
	{
		df = (double *)malloc(sizeof(double));
		*df = va_arg(list, double);
		variable->value = (void *)(df);
	}
}
