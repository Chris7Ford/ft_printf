/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:19:35 by chford            #+#    #+#             */
/*   Updated: 2019/06/10 15:40:28 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	remove_prefix_zeros(char **answer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = *answer;
	while ((*answer)[i] == '0')
		i++;
	*answer = (char *)malloc(sizeof(char) * (ft_strlen(*answer) - i + 1));
	while (temp[i])
		(*answer)[j++] = temp[i++];
	(*answer)[j] = '\0';
	free(temp);
}

char	*divide_string_cm(int mult, char **input, t_format var)
{
	char	*answer;
	char	*temp;
	int		is_zero;

	is_zero = check_zero(var);
	if (is_zero)
	{
		free(*input);
		return (ft_strdup("0"));
	}
	answer = ft_strdup(*input);
	while (--mult >= 0)
	{
		remove_prefix_zeros(&answer);
		temp = answer;
		answer = divide_by_two(answer, 0);
		free(temp);
	}
	free(*input);
	if (answer[0] == '.')
	{
		temp = ft_itoa(0);
		answer = ft_strjoin_free(&temp, &answer, 1, 1);
	}
	return (answer);
}

void	divide_get_num(int *num, char **input, int *i, char **answer)
{
	char	*temp;

	*num = (*num % 2) * 10 + (*input)[*i] - '0';
	temp = ft_itoa(*num / 2);
	*answer = ft_strjoin_free(answer, &temp, 1, 1);
	*i += 1;
}

void	end_division(char *input, int num, char **answer, int decimal)
{
	char	*temp;

	if (decimal && *(input - 2) == '1' && *(input - 3) != '1')
	{
		temp = ft_itoa(num / 2);
		*answer = ft_strjoin_free(answer, &temp, 1, 1);
	}
	if (num % 2)
	{
		if (!decimal)
			*answer = ft_strjoin_char(answer, '.');
		*answer = ft_strjoin_char(answer, '5');
	}
}

char	*divide_by_two(char *input, char *temp)
{
	char	*answer;
	int		decimal;
	int		num;
	int		i;

	answer = ft_strnew(0);
	decimal = 0;
	num = 0;
	i = 0;
	while (num < 2 && input[i] != '.')
		num = (num * 10) + (input[i++] - '0');
	temp = ft_itoa(num / 2);
	answer = ft_strjoin_free(&answer, &temp, 1, 1);
	while (input[i] && input[i] != '.')
		divide_get_num(&num, &input, &i, &answer);
	if (input[i] == '.' && (decimal = 1))
		answer = ft_strjoin_char(&answer, input[i++]);
	while (input[i])
		divide_get_num(&num, &input, &i, &answer);
	end_division(&(input[i]), num, &answer, decimal);
	return (answer);
}
