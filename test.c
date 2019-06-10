#include <stdio.h>
#include <stdlib.h>

void	get_hex_length(int n, int *length);
void	print_bits(int fd, int n);
double  get_printable_double(int num);
void	print_mantissa(int fd, int n);
int		get_zeros(long double decimal);



int		main(void)
{
	double	cf;
	double	ok;
	cf = 2249823789472983981757290384578934597298347057384570918345709283475253427509834564.352;
	ok = 9056.6345;
//	while (cf > 1)
//	{
//		cf = cf - (long long)cf;
//		printf("%f\n", cf);
//	}
//	printf("%lld\n", (unsigned long long)cf);
/*	while (cf > 9223372036854775807)
	{
		cf = cf - 9223372036854775807;
		printf("%f\n", cf);
	}
*/
	printf("%f\n", cf / 10);
	printf("%f\n", cf);
	if (cf == cf / 10)
		printf("It don't do nothing");
	/*long double	f = 7.000000000000006;
//					0.0000000000000000000
	double		decimal;
	unsigned int		num;
	int		length = 0;
	int		exponent;

	length = (int)f;
	decimal = f - length;
	printf("%d\n", length);
	printf("%.14lf\n", decimal);
	zeros = get_zeros(decimal);
	printf("We need to pad with %d zeros\n", zeros);
*/
	
/*	union unholy_t	unholy;
	int		zeros;
//	unholy.f = 0.000000000000000000000009;
	unholy.f = 7.00000000009809806;
//	print_bits(1, unholy.i);
//	printf("%d\n", unholy.i);
	print_mantissa(1, unholy.i);
	double	printable;
	printable = get_printable_double(unholy.i);
	zeros = get_zeros(unholy.f - (int)unholy.f);
	long long decint;
	decint = printable * 10000000000000000;
	printf("raw is       %.16lf\n", unholy.f);
	printf("printable is %.16lf\n", printable);
	printf("decint = %lld\n", decint);
	printf("final decimal result:\n");
	printf("There should be %d zeros\n", zeros);
	while (zeros)
	{
		printf("0");
		zeros--;
	}
	while (decint % 10 == 0)
		decint /= 10;
	printf("decint = %lld\n", decint);
*/
//	printf("%#f\n", tester);
//	printf("%#15.1f\n", tester);




/*//	exponent = (unholy.i & 4278190080) >> 24;
//	printf("%d\n", exponent);
//	print_bits(1, exponent);
	//f = (2.0/4.0/4.0/4.0/4.0) + (2.0/4.0/4.0/4.0/4.0/4.0/4.0/4.0/4.0);
//	f = (1.0/2/2/2/2) + (1.0/4/4/4/4/4/4/4/4);
//	printf("%.80f\n", f);
*/	/*	length = printf("%-.5X\n", num);
//	length = printf("%-.5X\n", num * -1);
	length = printf("%-.55X\n", num);
	length = printf("%#-.55X\n", num);
	length = printf("%-10.55X\n", num);
	length = printf("%#-10.55X\n", num);
	printf("look");
	length = printf("%-20.1X\n", num);
	length = printf("%#-20.1X\n", num);
	length = printf("%020.15X\n", num);
	length = printf("%#020.15X\n", num);
*///printf("%f\n", f);
//	num = *((int *)&f);
//	print_bits(1, num);
//	printf("%d\n", num);
//	printf("%f\n", *((float *)&num));
/*	//	length = printf("%-70.55X\n", num);
//	length = printf("%#-70.55X\n", num);
//	length = printf("%-X\n", num);
//	printf("%d\n", length - 1);
//	printf("%-10X\n", num);
//	get_hex_length(num, &length);
//	printf("length = %d\n", length);
*/}
