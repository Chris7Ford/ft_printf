/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:46:13 by chford            #+#    #+#             */
/*   Updated: 2019/05/11 10:27:57 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const	t_dispatch	g_table[] = {
	{C, printc},
	{S, prints},
	{P, printp},
	{D, printd},
	{O, printo},
	{U, printu},
	{X, printxx},
	{CX, printxx},
	{F, print_floats},
	{PERCENT, printpercent}
};

int		ft_printf_dispatch(t_format variable, int fd)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (i < 10)
	{
		if (g_table[i].c & variable.spec)
		{
			size = g_table[i].function(variable, fd);
			break ;
		}
		i++;
	}
	return (size);
}
