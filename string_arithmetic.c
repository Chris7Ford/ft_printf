/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_arithmetic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:53:49 by chford            #+#    #+#             */
/*   Updated: 2019/05/10 09:27:49 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	multiply_string_cm_insert(char **str, int length, int *num)
{
	char	*temp;

	if (*num > 9)
	{
		(*str)[length] = (*num % 10) + '0';
		if (length == 0)
		{
			temp = ft_itoa(*num / 10);
			*str = ft_strjoin_free(&temp, str, 1, 1);
		}
	}
	else
		(*str)[length] = *num + '0';
}

char	*multiply_string_cm(int mult, char *input)
{
	char	*str;
	int		length;
	int		carry;
	int		num;

	str = ft_strdup(input);
	while (--mult >= 0)
	{
		carry = 0;
		length = ft_strlen(str);
		while (--length >= 0)
		{
			num = ((str[length] - '0') * 2) + carry;
			multiply_string_cm_insert(&str, length, &num);
			carry = num / 10;
		}
	}
	free(input);
	return (str);
}

char	*ft_str_swap_length(char *str1, char *large, int *len_lg, int *len_sm)
{
	char	*tmp;
	int		temp;

	if (*len_sm > *len_lg)
	{
		temp = *len_lg;
		*len_lg = *len_sm;
		*len_sm = temp;
	}
	tmp = (char *)malloc(sizeof(char) * (*len_lg + 1));
	if (ft_strlen(str1) > ft_strlen(large))
		ft_strcpy(tmp, str1);
	else
		ft_strcpy(tmp, large);
	return (tmp);
}

char	*add_string_cm(char *str1, char *str2,
		int length_large, int length_str1)
{
	char	*large;
	char	*small;
	char	*temp;
	int		carry;
	int		num;

	large = ft_str_swap_length(str1, str2, &length_large, &length_str1);
	small = ft_strcmp(large, str1) ? str1 : str2;
	carry = 0;
	while (--length_large >= 0 && --length_str1 >= 0)
	{
		num = (large[length_large] - '0') + (small[length_str1] - '0') + carry;
		large[length_large] = num > 9 ? (num % 10) + '0' : num + '0';
		carry = num / 10;
	}
	while (carry > 0 && length_large >= 0)
	{
		num = (large[length_large] - '0') + carry;
		large[length_large--] = num > 9 ? (num % 10) + '0' : num + '0';
		carry = num / 10;
	}
	if (carry > 0 && length_large == -1 && (temp = ft_itoa(carry)))
		return (ft_strjoin_free(&temp, &large, 1, 1));
	return (large);
}
