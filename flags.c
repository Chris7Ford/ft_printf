/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 10:05:44 by chford            #+#    #+#             */
/*   Updated: 2019/05/10 10:40:14 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	return (c == '#' || c == '0' || c == ' ' || c == '-' || c == '+');
}

int		is_length(char c)
{
	return (c == 'h' || c == 'l' || c == 'L' || c == 'f');
}

void	get_flags(char **str, t_format *variable)
{
	int		i;

	i = PLUS;
	while (is_flag(**str))
	{
		if (**str == '#')
			variable->flags |= ALTERNATE;
		else if (**str == '0')
			variable->flags |= ZERO;
		else if (**str == ' ')
			variable->flags |= SPACE;
		else if (**str == '-')
			variable->flags |= MINUS;
		else if (**str == '+')
			variable->flags |= PLUS;
		(*str)++;
	}
}

void	get_length(char **str, t_format *variable)
{
	if (check_l_ll(str, variable) || check_h_hh(str, variable) ||
			check_cl(str, variable))
		return ;
	return ;
}
