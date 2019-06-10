/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:07:59 by chford            #+#    #+#             */
/*   Updated: 2019/05/11 18:33:32 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_num(char c)
{
	return (c >= '0' && c <= '9');
}

void		pass_num(char **str)
{
	while (is_num(**str))
		(*str)++;
}

void		get_variable_value(t_format *variable, va_list list)
{
	char	*c;

	if (variable->spec & C)
		get_c(list, variable);
	else if (variable->spec & S || variable->spec & P)
		get_sp(list, variable);
	else if (variable->spec % 8 == 0 &&
			variable->spec != 32 && variable->spec <= 256)
		get_diouxx(list, variable);
	else if (variable->spec & F)
		get_f(list, variable);
	else if (variable->spec & PERCENT)
	{
		c = (char *)malloc(sizeof(char) * 2);
		ft_strcpy(c, "%");
		variable->value = (void *)c;
	}
}

int			get_all_var_info(char **str, va_list list, t_format *variable)
{
	variable->flags = 0;
	variable->length = 0;
	variable->precision = -1;
	variable->spec = 0;
	variable->value = 0;
	++(*str);
	get_flags(str, variable);
	variable->width = ft_atoi(*str);
	pass_num(str);
	if (**str == '.')
	{
		variable->precision = 0;
		(*str)++;
	}
	if (is_num(**str))
		variable->precision = ft_atoi(*str);
	pass_num(str);
	get_length(str, variable);
	if (!(get_spec(str, variable)))
		return (0);
	get_variable_value(variable, list);
	return (1);
}

int			handle_variable(char **str, int fd, va_list list)
{
	t_format	variable;
	int			length;

	variable.fd = fd;
	if (!(get_all_var_info(str, list, &variable)))
		return (0);
	length = ft_printf_dispatch(variable, fd);
	if (variable.spec != S && variable.spec != P)
		free(variable.value);
	return (length);
}
