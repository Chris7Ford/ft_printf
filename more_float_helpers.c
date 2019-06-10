/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_float_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 18:07:52 by chford            #+#    #+#             */
/*   Updated: 2019/06/10 15:40:46 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_zero(t_format var)
{
	if ((*(long long *)var.value) == 0)
		return (1);
	return (0);
}

void	init_floats(char **mantissa, int *exponent,
		t_format *var, char **temp)
{
	overwrite_flags(var);
	*mantissa = get_mantissa_d(*var);
	*exponent = get_exponent_d(*var);
	*temp = ft_strnew(1);
	(*temp)[0] = '2';
}
