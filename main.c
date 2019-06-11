/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 10:20:04 by chford            #+#    #+#             */
/*   Updated: 2019/06/11 09:52:42 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int		lenm;
	int		lenp;

//	printf("real:\n");
//	lenp = printf("%.0i", 0);
/*
 *	
 *	The following commented section are undefined tests and do not need to be accounted for
 *
 *	lenp = printf("%.p, %.0p", 0, 0);
	printf("\n");
	lenm = ft_printf("%.p, %.0p", 0, 0);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%010s is a string", "this");
	printf("\n");
	lenm = ft_printf("%010s is a string", "this");
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%ll#x", 9223372036854775807);
	printf("\n");
	lenm = ft_printf("%ll#x", 9223372036854775807);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%05c", 42);
	printf("\n");
	lenm = ft_printf("%05c", 42);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("% u", 4294967295);
	printf("\n");
	lenm = ft_printf("% u", 4294967295);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");
*/
	lenp = printf("%f", (double)0);
	printf("\n");
	lenm = ft_printf("%f", (double)0);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%f", (double)-0);
	printf("\n");
	lenm = ft_printf("%f", (double)-0);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	long long llm = 18446744073709551615;
	lenp = printf("%llu", (unsigned long long)llm);
	printf("\n");
	lenm = ft_printf("%llu", (unsigned long long)llm);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("Kashim a %f histoires Ã  raconter", (double)1001);
	printf("\n");
	lenm = ft_printf("Kashim a %f histoires Ã  raconter", (double)1001);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("this %.8f float", (float)0);
	printf("\n");
	lenm = ft_printf("this %.8f float", (float)0);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("this %.8f float", 95.7544564);
	printf("\n");
	lenm = ft_printf("this %.8f float", 95.7544564);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("this %f float", 1.5);
	printf("\n");
	lenm = ft_printf("this %f float", 1.5);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("this %.8Lf float", 95.7544564l);
	printf("\n");
	lenm = ft_printf("this %.8Lf float", 95.7544564l);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("this %Lf float", 1.5l);
	printf("\n");
	lenm = ft_printf("this %Lf float", 1.5l);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("% 10.5d", 4242);
	printf("\n");
	lenm = ft_printf("% 10.5d", 4242);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%f", 0.375);
	printf("\n");
	lenm = ft_printf("%f", 0.375);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%-5.0f", 7.3);
	printf("\n");
	lenm = ft_printf("%-5.0f", 7.3);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%+05.1f", 7.3);
	printf("\n");
	lenm = ft_printf("%+05.1f", 7.3);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%05.0f", -7.3);
	printf("\n");
	lenm = ft_printf("%05.0f", -7.3);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%5.0f", -7.3);
	printf("\n");
	lenm = ft_printf("%5.0f", -7.3);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%05.0f", -7.3);
	printf("\n");
	lenm = ft_printf("%05.0f", -7.3);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%05.0f", 7.3);
	printf("\n");
	lenm = ft_printf("%05.0f", 7.3);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%5.1f", -7.3);
	printf("\n");
	lenm = ft_printf("%5.1f", -7.3);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%5.0f", 7.3);
	printf("\n");
	lenm = ft_printf("%5.0f", 7.3);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%#.0f", 7.4);
	printf("\n");
	lenm = ft_printf("%#.0f", 7.4);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("this %.0f float", 1.6);
	printf("\n");
	lenm = ft_printf("this %.0f float", 1.6);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%f", 1.0);
	printf("\n");
	lenm = ft_printf("%f", 1.0);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%08.5i", 0);
	printf("\n");
	lenm = ft_printf("%08.5i", 0);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%#.0o", 0);
	printf("\n");
	lenm = ft_printf("%#.0o", 0);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%#8.5o", 34);
	printf("\n");
	lenm = ft_printf("%#8.5o", 34);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%#0-8.5o", 34);
	printf("\n");
	lenm = ft_printf("%#0-8.5o", 34);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%#.3o", 0);
	printf("\n");
	lenm = ft_printf("%#.3o", 0);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%#.5o", 21);
	printf("\n");
	lenm = ft_printf("%#.5o", 21);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("this %#x number", 17);
	printf("\n");
	lenm = ft_printf("this %#x number", 17);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%#8.5x", 34);
	printf("\n");
	lenm = ft_printf("%#8.5x", 34);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%#.3x", 0);
	printf("\n");
	lenm = ft_printf("%#.3x", 0);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%#-2.7x", 3267);
	printf("\n");
	lenm = ft_printf("%#-2.7x", 3267);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%x", 4294967295);
	printf("\n");
	lenm = ft_printf("%x", 4294967295);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%x", 3);
	printf("\n");
	lenm = ft_printf("%x", 3);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%u", 4294967295);
	printf("\n");
	lenm = ft_printf("%u", 4294967295);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%+.0i", 0);
	printf("\n");
	lenm = ft_printf("%+.0i", 0);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%.0i", 0);
	printf("\n");
	lenm = ft_printf("%.0i", 0);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%i", 0);
	printf("\n");
	lenm = ft_printf("%i", 0);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("% .4i", 5263);
	printf("\n");
	lenm = ft_printf("% .4i", 5263);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%+8.5i", 34);
	printf("\n");
	lenm = ft_printf("%+8.5i", 34);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%+10.5i", -216);
	printf("\n");
	lenm = ft_printf("%+10.5i", -216);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%-10.5i", -216);
	printf("\n");
	lenm = ft_printf("%-10.5i", -216);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%3.7i", -2375);
	printf("\n");
	lenm = ft_printf("%3.7i", -2375);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%8.3i", -8473);
	printf("\n");
	lenm = ft_printf("%8.3i", -8473);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%.6i", 3);
	printf("\n");
	lenm = ft_printf("%.6i", 3);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%.6i", -3);
	printf("\n");
	lenm = ft_printf("%.6i", -3);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%10.5i", 216);
	printf("\n");
	lenm = ft_printf("%10.5i", 216);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%6.5i", -216);
	printf("\n");
	lenm = ft_printf("%6.5i", -216);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%10.5i", -216);
	printf("\n");
	lenm = ft_printf("%10.5i", -216);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%+.3i", 3723);
	printf("\n");
	lenm = ft_printf("%+.3i", 3723);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%.5i",-23646);
	printf("\n");
	lenm = ft_printf("%.5i",-23646);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%.3i",-23646);
	printf("\n");
	lenm = ft_printf("%.3i",-23646);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%.3i", 13862);
	printf("\n");
	lenm = ft_printf("%.3i", 13862);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%+8.8i", 8473);
	printf("\n");
	lenm = ft_printf("%+8.8i", 8473);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	lenp = printf("%8.3i", 8473);
	printf("\n");
	lenm = ft_printf("%8.3i", 8473);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	printf("\n");
	lenp = printf("%8.10i", 8473);
	printf("\n");
	lenm = ft_printf("%8.10i", 8473);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	printf("\n");
	lenp = printf("%.8i", 8473);
	printf("\n");
	lenm = ft_printf("%.8i", 8473);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	printf("\n");
	lenp = printf("%08i", -8473);
	printf("\n");
	lenm = ft_printf("%08i", -8473);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	printf("\n");
	lenp = printf("% 8.3i", 8473);
	printf("\n");
	lenm = ft_printf("% 8.3i", 8473);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	printf("\n");
//	lenp = printf("%-8.3i", 8473);
//	printf("\n");
	lenp = printf("%8.3i", 8473);
	printf("\n");
	lenm = ft_printf("%8.3i", 8473);
	printf("\n");
	if(lenm != lenp)
		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	printf("\n");
	printf("\n");

	printf("\n");
//	printf("\n");
//	printf("mine:\n");
//	lenm = ft_printf("%8.3i", -8473);
//	if(lenm != lenp)
//		printf("LEngths don't match. Mine is %d and the real printf is %d\n", lenm, lenp);
	return (0);
}
