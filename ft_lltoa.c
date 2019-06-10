/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:18:27 by chford            #+#    #+#             */
/*   Updated: 2019/05/07 15:23:18 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	get_size(long n)
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

static int	check_negative(long long *n, char **string, int *i)
{
	int		is_negative;
	int		size;

	is_negative = 0;
	if (*n < 0)
	{
		*n = *n * -1;
		*i = *i + 1;
		is_negative = 1;
	}
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

char		*ft_lltoa(long long n)
{
	long long	copy;
	char		*string;
	long		multiplier;
	int			size;
	int			i;

	size = 1;
	i = 0;
	copy = n;
	size = check_negative(&copy, &string, &i);
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
