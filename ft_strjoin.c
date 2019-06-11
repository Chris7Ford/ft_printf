/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:53:43 by chford            #+#    #+#             */
/*   Updated: 2019/06/11 10:10:07 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_free(char **s1, char **s2, int free1, int free2)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	string = (char *)malloc(sizeof(char) *
			(ft_strlen(*s1) + ft_strlen(*s2) + 1));
	if (!string)
		return (0);
	while ((*s1)[i] != '\0')
	{
		string[i] = (*s1)[i];
		i++;
	}
	while ((*s2)[j] != '\0')
		string[i++] = (*s2)[j++];
	string[i] = '\0';
	if (free1)
		free(*s1);
	if (free2)
		free(*s2);
	return (string);
}

char	*ft_strjoin_char(char **s1, char c)
{
	char	*string;
	int		i;

	i = 0;
	string = (char *)malloc(sizeof(char) * (ft_strlen(*s1) + 2));
	if (!string)
		return (0);
	while ((*s1)[i] != '\0')
	{
		string[i] = (*s1)[i];
		i++;
	}
	free(*s1);
	string[i] = c;
	string[i + 1] = '\0';
	return (string);
}

char	*ft_prepend_char(char c, char **s1)
{
	char	*string;
	int		i;

	i = 0;
	string = (char *)malloc(sizeof(char) * (ft_strlen(*s1) + 2));
	if (!string)
		return (0);
	string[i++] = c;
	while ((*s1)[i - 1] != '\0')
	{
		string[i] = (*s1)[i - 1];
		i++;
	}
	free(*s1);
	string[i] = '\0';
	return (string);
}
