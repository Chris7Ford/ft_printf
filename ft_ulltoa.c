/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:51:23 by chford            #+#    #+#             */
/*   Updated: 2019/05/10 09:48:11 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	get_size(unsigned long long n)
{
	int		size;

	size = 1;
	while (n > 9)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static long	get_multiplier(int size)
{
	long	mult;

	mult = 1;
	while (size > 1)
	{
		mult *= 10;
		size--;
	}
	return (mult);
}

static int	check_negative(unsigned long long *n, char **string)
{
	int		is_negative;
	int		size;

	is_negative = 0;
	size = get_size(*n);
	if (is_negative)
		size++;
	*string = (char *)malloc(sizeof(char) * (size + 1));
	if (!*string)
		return (0);
	if (is_negative)
	{
		*string[0] = '-';
		return (size - 1);
	}
	return (size);
}

char		*ft_ulltoa(unsigned long long n)
{
	char				*string;
	long				multiplier;
	unsigned long long	copy;
	int					size;
	int					i;

	size = 1;
	i = 0;
	copy = n;
	size = check_negative(&copy, &string);
	if (!string)
		return (0);
	while (size > 0)
	{
		multiplier = get_multiplier(size);
		string[i] = copy / multiplier + '0';
		copy = copy - (multiplier * (string[i] - '0'));
		size--;
		i++;
	}
	string[i] = '\0';
	return (string);
}
