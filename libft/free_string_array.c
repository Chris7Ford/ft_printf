/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_string_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:21:34 by chford            #+#    #+#             */
/*   Updated: 2019/06/10 16:27:49 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_string_array(char ***array)
{
	int		i;

	i = 0;
	while ((*array)[i])
	{
		free((*array)[i]);
		(*array)[i++] = 0;
	}
	free(*array);
	*array = 0;
}
