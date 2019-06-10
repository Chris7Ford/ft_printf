/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:43:14 by chford            #+#    #+#             */
/*   Updated: 2019/05/09 11:01:38 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void    print_hex_ulong_fd(unsigned long n, int fd);
void	print_hex_ulong_length(unsigned long n, int *length);

int main (void)
{
	int		length;

	length = 0;
	print_hex_ulong_length(4298113424, &length);
	printf("%d\n", length);
	return (0);
}
