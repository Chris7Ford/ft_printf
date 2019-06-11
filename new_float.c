/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:58:14 by chford            #+#    #+#             */
/*   Updated: 2019/06/11 09:47:52 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*chop_float_precision(char **answer, t_format var, int i)
{
	char	*new;
	int		j;

	j = 0;
	if (!(var.flags & ALTERNATE) && var.precision == 0)
	{
		new = (char *)malloc(sizeof(char) * (i + 1));
		ft_strncpy(new, *answer, i + 1);
		new[i] = '\0';
	}
	else
	{
		new = (char *)malloc(sizeof(char) * (i + 1 + var.precision + 1));
		ft_strncpy(new, *answer, i + 1 + var.precision + 1);
		new[i + 1 + var.precision] = '\0';
	}
	free(*answer);
	return (new);
}

char	*handle_float_precision(char **answer, t_format var)
{
	int		length;
	int		i;

	if (var.precision == -1)
		var.precision = 6;
	length = get_decimal_length(*answer);
	if (length == 0 && (*answer)[ft_strlen(*answer) - 1] != '.')
		*answer = ft_strjoin_char(answer, '.');
	while (var.precision >= length)
	{
		*answer = ft_strjoin_char(answer, '0');
		length++;
	}
	i = 0;
	while ((*answer)[i] != '.' && (*answer)[i])
		i++;
	if (length > var.precision)
		*answer = round_precision(answer, var.precision, &i, 0);
	*answer = chop_float_precision(answer, var, i);
	return (*answer);
}

void	meet_min_width_floats(char **answer, t_format var, int length)
{
	if (var.flags & MINUS)
	{
		while (length < var.width)
		{
			if (var.flags & ZERO)
				*answer = ft_strjoin_char(answer, '0');
			else
				*answer = ft_strjoin_char(answer, ' ');
			length++;
		}
	}
	else
	{
		while (length < var.width)
		{
			if (var.flags & ZERO)
				*answer = ft_prepend_char('0', answer);
			else
				*answer = ft_prepend_char(' ', answer);
			length++;
		}
	}
}

int		print_float_string(t_format var, char **answer, int fd)
{
	int		length;
	int		i;

	rearrange_float_prefix(var, *answer);
	length = 0;
	if (var.precision == 0 && !(var.flags & ALTERNATE))
	{
		i = 0;
		if (!(var.flags & MINUS) && ft_strlen(*answer) < (size_t)var.width &&
				((!(var.flags & ZERO) && write(fd, " ", 1)) ||
				(var.flags & ZERO && write(fd, "0", 1))))
			length = 1;
		while ((*answer)[i] && (*answer)[i] != '.')
			write(fd, &((*answer)[i++]), 1);
		if (var.flags & MINUS && ft_strlen(*answer) < (size_t)var.width &&
				((!(var.flags & ZERO) && write(fd, " ", 1)) ||
				(var.flags & ZERO && write(fd, "0", 1))))
			length = 1;
		free(*answer);
		return (i + length);
	}
	ft_putstr_fd(*answer, fd);
	length = ft_strlen(*answer);
	free(*answer);
	return (length);
}

int		print_floats(t_format var, int fd)
{
	char	*mantissa;
	char	*answer;
	char	*temp;
	int		exponent;
	int		length[2];

	overwrite_flags(&var);
	init_floats(&mantissa, &exponent, &var, &temp);
	if ((length[0] = check_f_edge(var, exponent, mantissa, fd)))
		return (length[0]);
	length[1] = var.length & CL ? 63 : D_MANTISSA_LEN;
	answer = multiply_string_cm(length[1] - 1, temp);
	temp = ft_strdup(answer);
	free(answer);
	answer = add_string_cm(temp, mantissa,
			ft_strlen(temp), ft_strlen(mantissa));
	free(temp);
	free(mantissa);
	answer = divide_string_cm(length[1] - exponent, &answer, var);
	answer = handle_float_precision(&answer, var);
	check_negative_floats(&answer, var);
	meet_min_width_floats(&answer, var, ft_strlen(answer));
	return (print_float_string(var, &answer, fd));
}
