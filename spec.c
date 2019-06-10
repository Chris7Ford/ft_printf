/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:06:39 by chford            #+#    #+#             */
/*   Updated: 2019/05/11 09:33:15 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_spec(char **str, t_format *variable)
{
	if (**str == 'c')
		variable->spec = C;
	else if (**str == 's')
		variable->spec = S;
	else if (**str == 'p')
		variable->spec = P;
	else if (**str == 'd' || **str == 'i')
		variable->spec = D;
	else if (**str == 'o')
		variable->spec = O;
	else if (**str == 'u')
		variable->spec = U;
	else if (**str == 'x')
		variable->spec = X;
	else if (**str == 'X')
		variable->spec = CX;
	else if (**str == 'f')
		variable->spec = F;
	else if (**str == '%')
		variable->spec = PERCENT;
	else
		return (0);
	(*str)++;
	return (1);
}
