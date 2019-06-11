/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 10:05:11 by chford            #+#    #+#             */
/*   Updated: 2019/06/11 10:25:05 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_negative_floats(char **answer, t_format var)
{
	t_unholy_d	unholy_d;
	t_unholy_l	unholy_l;
	char		*temp;

	temp = *answer;
	if (!(var.length & CL))
	{
		unholy_d.d = *((double *)var.value);
		if (unholy_d.l >> 63)
			*answer = ft_prepend_char('-', answer);
		else if (var.flags & SPACE)
			*answer = ft_prepend_char(' ', answer);
		else if (var.flags & PLUS)
			*answer = ft_prepend_char('+', answer);
	}
	else
	{
		unholy_l.d = *((long double *)var.value);
		if (unholy_l.l[0] & 128)
			*answer = ft_prepend_char('-', answer);
		else if (var.flags & SPACE)
			*answer = ft_prepend_char(' ', answer);
		else if (var.flags & PLUS)
			*answer = ft_prepend_char('+', answer);
	}
}

void	rearrange_float_prefix(t_format var, char *answer)
{
	char	*pos;

	if (!(var.flags & MINUS) && var.flags & ZERO
			&& (pos = ft_strchr(answer, '-')))
	{
		*pos = '0';
		answer[0] = '-';
	}
	if (!(var.flags & MINUS) && var.flags & ZERO
			&& (pos = ft_strchr(answer, '+')))
	{
		*pos = '0';
		answer[0] = '+';
	}
	if (!(var.flags & MINUS) && var.flags & ZERO
			&& (pos = ft_strchr(answer, ' ')))
	{
		*pos = '0';
		answer[0] = ' ';
	}
}

int		get_decimal_length(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '.')
		i++;
	while (str[i++])
		j++;
	return (j);
}

int		round_number(char **answer, int *i, int *precision, int first)
{
	if ((*answer)[*i] == '.' && *precision == 0)
		*i -= 1;
	if ((*answer)[*i + *precision] != '9')
	{
		(*answer)[*i + *precision] += 1;
		return (1);
	}
	(*answer)[*i + *precision] = '0';
	if (first)
		*precision -= 1;
	else
		*i -= 1;
	return (0);
}

char	*round_precision(char **answer, int precision, int *num, char *temp)
{
	int		i;

	i = *num;
	if ((*answer)[i + precision + 1] >= '5' &&
			(*answer)[i + precision + 1] <= '9')
	{
		(*answer)[i + precision + 1] = '\0';
		while (precision >= 0 && i >= 0)
		{
			if (round_number(answer, &i, &precision, precision > 0 ? 1 : 0))
				break ;
		}
		if (i == -1 && precision == 0)
		{
			temp = ft_itoa(1);
			*answer = ft_strjoin_free(&temp, answer, 1, 1);
			*num += 1;
		}
	}
	else
		(*answer)[i + precision + 1] = '\0';
	temp = ft_strdup(*answer);
	free(*answer);
	return (temp);
}
