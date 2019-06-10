/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:01:29 by chford            #+#    #+#             */
/*   Updated: 2019/05/16 17:51:46 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

void	initialize_format(t_format *var)
{
	var->value = 0;
	var->precision = -1;
	var->width = 0;
	var->length = 0;
	var->flags = 0;
	var->spec = 0;
}

void	test_get_variable_value(t_format *get_variable_value_struct, ...)
{
	va_list		list;
	va_start(list, get_variable_value_struct);
	get_variable_value(get_variable_value_struct, list);
	va_end(list);
}

t_format	test_get_all_var_info(char **str, ...)
{
	va_list		list;
	t_format	result;
	va_start(list, str);
	result = get_all_var_info(str, list);
	return (result);
}

int		main(void)
{

	int		sum;
	
	// is_flag unit tests ~
	if (!is_flag('#'))
		printf("is_flag failed with test of '#' (This should pass)\n");
	if (!is_flag('0'))
		printf("is_flag failed with test of '0' (This should pass)\n");
	if (!is_flag(' '))
		printf("is_flag failed with test of ' ' (This should pass)\n");
	if (!is_flag('-'))
		printf("is_flag failed with test of '-' (This should pass)\n");
	if (!is_flag('+'))
		printf("is_flag failed with test of '+' (This should pass)\n");
	if (is_flag(':'))
		printf("is_flag passed with test of ':' (This should fail)\n");
	if (is_flag('>'))
		printf("is_flag passed with test of '>' (This should fail)\n");
	if (is_flag('h'))
		printf("is_flag passed with test of 'h' (This should fail)\n");
//	~ is_length unit tests ~
	if (!is_length('h'))
		printf("is_length failed with test of 'h' (This should pass)\n");
	if (!is_length('l'))
		printf("is_length failed with test of 'l' (This should pass)\n");
	if (!is_length('L'))
		printf("is_length failed with test of 'L' (This should pass)\n");
	if (!is_length('f'))
		printf("is_length failed with test of 'f' (This should pass)\n");
	if (is_length('F'))
		printf("is_length passed with test of 'F' (This should fail)\n");
	if (is_length('>'))
		printf("is_length passed with test of '>' (This should fail)\n");
	if (is_length('#'))
		printf("is_length passed with test of '#' (This should fail)\n");
// ~ get_flags unit tests ~
	t_format	get_flags_struct;
	char		*get_flags_string;


	initialize_format(&get_flags_struct);
	get_flags_string ="#d";
	get_flags(&get_flags_string, &get_flags_struct);
	if (get_flags_struct.flags != ALTERNATE)
		printf("get flags failed: flag value is %d and should be %d (ALTERNATE)\n", get_flags_struct.flags, ALTERNATE);

	initialize_format(&get_flags_struct);
	get_flags_string ="0d";
	get_flags(&get_flags_string, &get_flags_struct);
	if (get_flags_struct.flags != ZERO)
		printf("get flags failed: flag value is %d and should be %d (ZERO)\n", get_flags_struct.flags, ZERO);

	initialize_format(&get_flags_struct);
	get_flags_string =" d";
	get_flags(&get_flags_string, &get_flags_struct);
	if (get_flags_struct.flags != SPACE)
		printf("get flags failed: flag value is %d and should be %d (SPACE)\n", get_flags_struct.flags, SPACE);

	initialize_format(&get_flags_struct);
	get_flags_string ="-d";
	get_flags(&get_flags_string, &get_flags_struct);
	if (get_flags_struct.flags != MINUS)
		printf("get flags failed: flag value is %d and should be (MINUS)%d\n", get_flags_struct.flags, MINUS);

	initialize_format(&get_flags_struct);
	get_flags_string ="+d";
	get_flags(&get_flags_string, &get_flags_struct);
	if (get_flags_struct.flags != PLUS)
		printf("get flags failed: flag value is %d and should be %d (PLUS)\n", get_flags_struct.flags, PLUS);

	initialize_format(&get_flags_struct);
	sum = PLUS + ALTERNATE + ZERO + SPACE + MINUS;
	get_flags_string ="#0 -+d";
	get_flags(&get_flags_string, &get_flags_struct);
	if (get_flags_struct.flags != sum)
		printf("get flags failed: flag value is %d and should be %d (ALL)\n", get_flags_struct.flags, sum);
	if (get_flags_string[0] != 'd')
		printf("String not truncated! Next character should be 'd' and is '%c'\n", get_flags_string[0]);

	initialize_format(&get_flags_struct);
	get_flags_string ="#0-+-+++--###      -+d";
	get_flags(&get_flags_string, &get_flags_struct);
	if (get_flags_struct.flags != sum)
		printf("get flags failed: flag value is %d and should be %d (HARD TEST)\n", get_flags_struct.flags, sum);
	if (get_flags_string[0] != 'd')
		printf("String not truncated! Next character should be 'd' and is '%c'\n", get_flags_string[0]);
	
//	~ ft_atoi unit testing ~
	sum = ft_atoi("50");
	if (sum != 50)
		printf("ft_atoi failing with a test of 50. Value is: %d\n", sum);
	sum = ft_atoi("-50");
	if (sum != -50)
		printf("ft_atoi failing with a test of -50. Value is: %d\n", sum);
	sum = ft_atoi("654654");
	if (sum != 654654)
		printf("ft_atoi failing with a test of 654654. Value is: %d\n", sum);
	sum = ft_atoi("-654654");
	if (sum != -654654)
		printf("ft_atoi failing with a test of -654654. Value is: %d\n", sum);
	sum = ft_atoi("2147483647");
	if (sum != 2147483647)
		printf("ft_atoi failing with a test of 2147483647. Value is: %d\n", sum);
	sum = ft_atoi("-2147483648");
	if (sum != -2147483648)
		printf("ft_atoi failing with a test of -2147483647. Value is: %d\n", sum);
	sum = ft_atoi("0");
	if (sum != 0)
		printf("ft_atoi failing with a test of 0. Value is: %d\n", sum);
	sum = ft_atoi("15602.845");
	if (sum != 15602)
		printf("ft_atoi failing with a test of 15602.845. Value is: %d and should be 15602\n", sum);
	sum = ft_atoi("300h465");
	if (sum != 300)
		printf("ft_atoi failing with a test of 300h465. Value is: %d and should be 300\n", sum);

//	~ pass_num unit testing ~
	char *pass_num_string = "123h";
	char *pass_num_result = "h";
	pass_num(&pass_num_string);
	if (ft_strcmp(pass_num_string, pass_num_result))
		printf("pass_num failed with string of 123h. result: %s, Should end like %s\n", pass_num_string, pass_num_result);
	char *pass_num_string2 = "1010100100020304h023040";
	char *pass_num_result2 = "h023040";
	pass_num(&pass_num_string2);
	if (ft_strcmp(pass_num_string2, pass_num_result2))
		printf("pass_num failed with string of 1010100100020304h023040. result: %s, Should end like %s\n", pass_num_string2, pass_num_result2);
	char *pass_num_string3 = "0000999.2";
	char *pass_num_result3 = ".2";
	pass_num(&pass_num_string3);
	if (ft_strcmp(pass_num_string3, pass_num_result3))
		printf("pass_num failed with string of 0000999.2. result: %s, Should end like %s\n", pass_num_string3, pass_num_result3);
	char *pass_num_string4 = ".2";
	char *pass_num_result4 = ".2";
	pass_num(&pass_num_string3);
	if (ft_strcmp(pass_num_string4, pass_num_result4))
		printf("pass_num failed with string of .2. result: %s, Should end like %s\n", pass_num_string4, pass_num_result4);

// ~ check_l_ll unit testing ~
	int			result;
	t_format	check_l_ll_struct;

	char 		*check_l_ll_string = "lld";
	char 		*check_l_ll_result = "d";
	initialize_format(&check_l_ll_struct);
	result = check_l_ll(&check_l_ll_string, &check_l_ll_struct);
	if (result != 1)
		printf("The return value for check_l_ll is incorrect. Expected 1 and got %d\n", result);
	if (check_l_ll_struct.length != LL)
		printf("The value of length in the resulting variable structure is incorrect. Expected %d and got %d from test of 'lld'\n", LL, check_l_ll_struct.length);
	if (ft_strcmp(check_l_ll_string, check_l_ll_result))
		printf("String not truncated in check_l_ll.  String is now '%s' and expected 'd' from test 'lld'\n", check_l_ll_string);
	
	char 		*check_l_ll_string2 = "ld";
	char 		*check_l_ll_result2 = "d";
	initialize_format(&check_l_ll_struct);
	result = check_l_ll(&check_l_ll_string2, &check_l_ll_struct);
	if (result != 1)
		printf("The return value for check_l_ll is incorrect. Expected 1 and got %d\n", result);
	if (check_l_ll_struct.length != L)
		printf("The value of length in the resulting variable structure is incorrect. Expected %d and got %d from test of 'ld'\n", L, check_l_ll_struct.length);
	if (ft_strcmp(check_l_ll_string, check_l_ll_result))
		printf("String not truncated in check_l_ll.  String is now '%s' and expected 'd' from test 'ld'\n", check_l_ll_string2);
	
	char 		*check_l_ll_string3 = "lrd";
	char 		*check_l_ll_result3 = "rd";
	initialize_format(&check_l_ll_struct);
	result = check_l_ll(&check_l_ll_string3, &check_l_ll_struct);
	if (result != 1)
		printf("The return value for check_l_ll is incorrect. Expected 1 and got %d\n", result);
	if (check_l_ll_struct.length != L)
		printf("The value of length in the resulting variable structure is incorrect. Expected %d and got %d from test of 'ld'\n", L, check_l_ll_struct.length);
	if (ft_strcmp(check_l_ll_string, check_l_ll_result))
		printf("String not truncated in check_l_ll.  String is now '%s' and expected 'd' from test 'ld'\n", check_l_ll_string3);

	char 		*check_l_ll_string4 = "rd";
	char 		*check_l_ll_result4 = "rd";
	initialize_format(&check_l_ll_struct);
	result = check_l_ll(&check_l_ll_string4, &check_l_ll_struct);
	if (result != 0)
		printf("The return value for check_l_ll is incorrect. Expected 0 and got %d\n", result);
	if (check_l_ll_struct.length != 0)
		printf("The value of length in the resulting variable structure is incorrect. Expected %d and got %d from test of 'rd'\n", 0, check_l_ll_struct.length);

// ~ check_h_hh unit testing ~
	t_format	check_h_hh_struct;

	char 		*check_h_hh_string = "hhd";
	char 		*check_h_hh_result = "d";
	initialize_format(&check_h_hh_struct);
	result = check_h_hh(&check_h_hh_string, &check_h_hh_struct);
	if (result != 1)
		printf("The return value for check_h_hh is incorrect. Expected 1 and got %d\n", result);
	if (check_h_hh_struct.length != HH)
		printf("The value of length in the resulting variable structure is incorrect. Expected %d and got %d from test of 'hhd'\n", HH, check_h_hh_struct.length);
	if (ft_strcmp(check_h_hh_string, check_h_hh_result))
		printf("String not truncated in check_h_hh.  String is now '%s' and expected 'd' from test 'lld'\n", check_h_hh_string);
	
	char 		*check_h_hh_string2 = "hd";
	char 		*check_h_hh_result2 = "d";
	initialize_format(&check_h_hh_struct);
	result = check_h_hh(&check_h_hh_string2, &check_h_hh_struct);
	if (result != 1)
		printf("The return value for check_h_hh is incorrect. Expected 1 and got %d\n", result);
	if (check_h_hh_struct.length != H)
		printf("The value of length in the resulting variable structure is incorrect. Expected %d and got %d from test of 'hd'\n", H, check_h_hh_struct.length);
	if (ft_strcmp(check_h_hh_string2, check_h_hh_result2))
		printf("String not truncated in check_h_hh.  String is now '%s' and expected 'd' from test 'hd'\n", check_h_hh_string2);
	
	char 		*check_h_hh_string3 = "hrd";
	char 		*check_h_hh_result3 = "rd";
	initialize_format(&check_h_hh_struct);
	result = check_h_hh(&check_h_hh_string3, &check_h_hh_struct);
	if (result != 1)
		printf("The return value for check_h_hh is incorrect. Expected 1 and got %d\n", result);
	if (check_h_hh_struct.length != H)
		printf("The value of length in the resulting variable structure is incorrect. Expected %d and got %d from test of 'hrd'\n", H, check_h_hh_struct.length);
	if (ft_strcmp(check_h_hh_string3, check_h_hh_result3))
		printf("String not truncated in check_h_hh.  String is now '%s' and expected 'rd' from test 'hrd'\n", check_h_hh_string3);

	char 		*check_h_hh_string4 = "rd";
	char 		*check_h_hh_result4 = "rd";
	initialize_format(&check_h_hh_struct);
	result = check_h_hh(&check_h_hh_string4, &check_h_hh_struct);
	if (result != 0)
		printf("The return value for check_h_hh is incorrect. Expected 0 and got %d\n", result);
	if (check_h_hh_struct.length != 0)
		printf("The value of length in the resulting variable structure is incorrect. Expected %d and got %d from test of 'rd'\n", 0, check_h_hh_struct.length);

//	~ check cl untit tests ~
	char		*check_cl_string = "Ld";
	char		*check_cl_result = "d";
	t_format	check_cl_struct;

	initialize_format(&check_cl_struct);
	result = check_cl(&check_cl_string, &check_cl_struct);
	if (result != 1)
		printf("The return value for check_cl_is incorrect. Expected 1 and got %d\n", result);
	if (check_cl_struct.length != CL)
		printf("The value of length in the resulting variable structure is incorrect. Expected %d and got %d from test of 'Ld'\n", CL, check_cl_struct.length);
	if (ft_strcmp(check_cl_string, check_cl_result))
		printf("String not truncated properly in check_cl. String is now '%s' and expected 'd' from test 'Ld'\n", check_cl_string);

	char		*check_cl_string2 = "ld";
	char		*check_cl_result2 = "d";

	initialize_format(&check_cl_struct);
	result = check_cl(&check_cl_string2, &check_cl_struct);
	if (result != 0)
		printf("The return value for check_cl_is incorrect. Expected 0 and got %d\n", result);
	if (check_cl_struct.length != 0)
		printf("The value of length in the resulting variable structure is incorrect. Expected %d and got %d from test of 'Ld'\n", 0, check_cl_struct.length);
	if (ft_strcmp(check_cl_string, check_cl_result))
		printf("String should not be truncated in check_cl. String is now '%s' and expected 'ld' from test 'ld'\n", check_cl_string);

	char		*check_f_string = "fd";
	char		*check_f_result = "d";
	t_format	check_f_struct;

	initialize_format(&check_f_struct);
	result = check_f(&check_f_string, &check_f_struct);
	if (result != 1)
		printf("The return value for check_f_is incorrect. Expected 1 and got %d\n", result);
	if (check_f_struct.length != F)
		printf("The value of length in the resulting variable structure is incorrect. Expected %d and got %d from test of 'fd'\n", F, check_f_struct.length);
	if (ft_strcmp(check_f_string, check_f_result))
		printf("String not truncated properly in check_f. String is now '%s' and expected 'd' from test 'fd'\n", check_f_string);

	char		*check_f_string2 = "ld";
	char		*check_f_result2 = "d";

	initialize_format(&check_f_struct);
	result = check_f(&check_f_string2, &check_f_struct);
	if (result != 0)
		printf("The return value for check_f_is incorrect. Expected 0 and got %d\n", result);
	if (check_f_struct.length != 0)
		printf("The value of length in the resulting variable structure is incorrect. Expected %d and got %d from test of 'ld'\n", 0, check_f_struct.length);
	if (ft_strcmp(check_f_string, check_f_result))
		printf("String should not be truncated in check_f. String is now '%s' and expected 'ld' from test 'ld'\n", check_f_string);

//	~get_length unit tests~

	char	*get_length_string = "lld";
	char	*get_length_result = "d";
	t_format	get_length_struct;

	initialize_format(&get_length_struct);
	get_length(&get_length_string, &get_length_struct);
	if (get_length_struct.length != LL)
		printf("The value of length in the resulting varialb structure is incorrect from get_length. Expteced %d and got %d from a test of 'lld'\n", LL, get_length_struct.length);
	if (ft_strcmp(get_length_string, get_length_result))
		printf("The string was not properly concatenated in get_length.  The string should be '%s' and is currently '%s'", get_length_result, get_length_string);
	
	char	*get_length_string2 = "fd";
	char	*get_length_result2 = "d";

	initialize_format(&get_length_struct);
	get_length(&get_length_string2, &get_length_struct);
	if (get_length_struct.length != F)
		printf("The value of length in the resulting variable structure is incorrect from get_length. Expteced %d and got %d from a test of 'lld'\n", F, get_length_struct.length);
	if (ft_strcmp(get_length_string2, get_length_result2))
		printf("The string was not properly concatenated in get_length.  The string should be '%s' and is currently '%s'", get_length_result2, get_length_string2);
	
	char	*get_length_string3 = "d";
	char	*get_length_result3 = "d";

	initialize_format(&get_length_struct);
	get_length(&get_length_string3, &get_length_struct);
	if (get_length_struct.length != 0)
		printf("The value of length in the resulting variable structure is incorrect from get_length. Expteced %d and got %d from a test of 'lld'\n", 0, get_length_struct.length);
	if (ft_strcmp(get_length_string3, get_length_result3))
		printf("The string should not be concatenated in get_length with a test of 'd'.  The string should be '%s' and is currently '%s'", get_length_result3, get_length_string3);


//	~ get_spec unit tests ~
	char	*get_spec_string = "i ";
	char	*get_spec_result = " ";

	t_format get_spec_struct;
	initialize_format(&get_spec_struct);
	get_spec(&get_spec_string, &get_spec_struct);
	if (get_spec_struct.spec != D)
		printf("The spec value from get_spec is incorrect with a test of 'i '.  Expected %d and got %d\n", D, get_spec_struct.spec);
	if (ft_strcmp(get_spec_string, get_spec_result))
		printf("String not concatenated properly from get_spec with test of 'i '. Result is %s and exptected is %s\n", get_spec_string, get_spec_result);

	char	*get_spec_string2 = "f ";
	char	*get_spec_result2 = " ";

	initialize_format(&get_spec_struct);
	get_spec(&get_spec_string2, &get_spec_struct);
	if (get_spec_struct.spec != F)
		printf("The spec value from get_spec is incorrect with a test of 'f '.  Expected %d and got %d\n", F, get_spec_struct.spec);
	if (ft_strcmp(get_spec_string2, get_spec_result2))
		printf("String not concatenated properly from get_spec with test of 'f '. Result is %s and exptected is %s\n", get_spec_string2, get_spec_result2);
	
	char	*get_spec_string4 = "# ";
	char	*get_spec_result4 = " ";

	initialize_format(&get_spec_struct);
	get_spec(&get_spec_string4, &get_spec_struct);
	if (get_spec_struct.spec != HASH)
		printf("The spec value from get_spec is incorrect with a test of 'f '.  Expected %d and got %d\n", HASH, get_spec_struct.spec);
	if (ft_strcmp(get_spec_string4, get_spec_result4))
		printf("String not concatenated properly from get_spec with test of 'f '. Result is %s and exptected is %s\n", get_spec_string4, get_spec_result4);

	char	*get_spec_string3 = "z ";
	char	*get_spec_result3 = " ";

	initialize_format(&get_spec_struct);
	get_spec(&get_spec_string3, &get_spec_struct);
	if (get_spec_struct.spec != 0)
		printf("The spec value from get_spec is incorrect with a test of 'z '.  Expected %d and got %d\n", -1, get_spec_struct.spec);

//	~ get_variable_value unit testing (will need a function call) ~
//	~ this include all of the 'get' functions (get_value.c)
	t_format get_variable_value_struct;
	initialize_format(&get_variable_value_struct);
	
	get_variable_value_struct.spec = C;
	char	test_char_get_var;

	test_char_get_var = 'c';
	test_get_variable_value(&get_variable_value_struct, test_char_get_var);
	if (((*((char *)get_variable_value_struct.value)) != test_char_get_var))
		printf("get_variable_value does not set character to value appropriately. Expected %c and got %c\n", test_char_get_var, ((*((char *)get_variable_value_struct.value))));

	initialize_format(&get_variable_value_struct);	
	get_variable_value_struct.spec = D;
	get_variable_value_struct.length = HH;
	unsigned char	test_uchar_get_var;

	test_uchar_get_var = 'c';
	test_get_variable_value(&get_variable_value_struct, test_uchar_get_var);
	if (((*((char *)get_variable_value_struct.value)) != test_uchar_get_var))
		printf("get_variable_value does not set unsigned character (hhd) to value appropriately. Expected %c and got %c\n", test_char_get_var, ((*((char *)get_variable_value_struct.value))));

	initialize_format(&get_variable_value_struct);
	get_variable_value_struct.spec = F;
	get_variable_value_struct.length = CL;
	long double	test_ld_get_var;


	test_ld_get_var = 5.5654562816666666789;
	test_get_variable_value(&get_variable_value_struct, test_ld_get_var);
	if (((*((long double *)get_variable_value_struct.value)) != test_ld_get_var))
		printf("get_variable_value does not set long double to value appropriately. Expected %Lf and got %Lf\n", test_ld_get_var, ((*((long double *)get_variable_value_struct.value))));

	initialize_format(&get_variable_value_struct);
	get_variable_value_struct.spec = F;
	get_variable_value_struct.length = L;
	double	test_d_get_var;

	test_d_get_var = 5.5654562816;
	test_get_variable_value(&get_variable_value_struct, test_d_get_var);
	if (((*((double *)get_variable_value_struct.value)) != test_d_get_var))
		printf("get_variable_value does not set double to value appropriately. Expected %lf and got %lf\n", test_d_get_var, ((*((double *)get_variable_value_struct.value))));

	initialize_format(&get_variable_value_struct);
	get_variable_value_struct.spec = F;
	float	test_f_get_var;

	test_f_get_var = 5.66789;
	test_get_variable_value(&get_variable_value_struct, test_f_get_var);
	if (((*((float *)get_variable_value_struct.value)) != test_f_get_var))
		printf("get_variable_value does not set float to value appropriately. Expected %f and got %f\n", test_f_get_var, ((*((float *)get_variable_value_struct.value))));

	initialize_format(&get_variable_value_struct);
	get_variable_value_struct.spec = P;
	void	*test_vp_get_var;

	test_vp_get_var = (void *)(&test_ld_get_var);
	test_get_variable_value(&get_variable_value_struct, test_vp_get_var);
	if (get_variable_value_struct.value != test_vp_get_var)
		printf("get_variable_value does not set pointer to value appropriately. Expected %p and got %p\n", test_vp_get_var, get_variable_value_struct.value);

	initialize_format(&get_variable_value_struct);
	get_variable_value_struct.spec = D;
	int		test_di_get_var;

	test_di_get_var = 50;
	test_get_variable_value(&get_variable_value_struct, test_di_get_var);
	if (((*((int *)get_variable_value_struct.value)) != test_di_get_var))
		printf("get_variable_value does not set int(d) to value appropriately. Expected %d and got %d\n", test_di_get_var, ((*((int *)get_variable_value_struct.value))));

	initialize_format(&get_variable_value_struct);
	get_variable_value_struct.spec = D;
	get_variable_value_struct.length = HH;
	unsigned char	test_hh_get_var;

	test_hh_get_var = 'F';
	test_get_variable_value(&get_variable_value_struct, test_hh_get_var);
	if (((*((unsigned char *)get_variable_value_struct.value)) != test_hh_get_var))
		printf("get_variable_value does not set unsigned char(HH) to value appropriately. Expected %hhd and got %hhd\n", test_hh_get_var, ((*((unsigned char *)get_variable_value_struct.value))));

	initialize_format(&get_variable_value_struct);
	get_variable_value_struct.spec = D;
	get_variable_value_struct.length = H;
	unsigned short	test_h_get_var;

	test_h_get_var = 65535;
	test_get_variable_value(&get_variable_value_struct, test_h_get_var);
	if (((*((unsigned short *)get_variable_value_struct.value)) != test_h_get_var))
		printf("get_variable_value does not set unsigned short(HH) to value appropriately. Expected %hd and got %hd\n", test_h_get_var, ((*((unsigned short *)get_variable_value_struct.value))));

	initialize_format(&get_variable_value_struct);
	get_variable_value_struct.spec = D;
	get_variable_value_struct.length = L;
	long  test_dl_get_var;

	test_dl_get_var = 9223372036854775807;
	test_get_variable_value(&get_variable_value_struct, test_dl_get_var);
	if (((*((long *)get_variable_value_struct.value)) != test_dl_get_var))
		 printf("get_variable_value does not set long(l) to value appropriately. Expected %ld and got %ld\n", test_dl_get_var, ((*((long *)get_variable_value_struct.value))));

	initialize_format(&get_variable_value_struct);
	get_variable_value_struct.spec = D;
	get_variable_value_struct.length = LL;
	long long  test_dll_get_var;

	test_dll_get_var = 9223372036854775807;
	test_get_variable_value(&get_variable_value_struct, test_dll_get_var);
	if (((*((long long*)get_variable_value_struct.value)) != test_dll_get_var))
		 printf("get_variable_value does not set long long(ll) to value appropriately. Expected %lld and got %lld\n", test_dll_get_var, ((*((long long *)get_variable_value_struct.value))));

	// ~ The big one - get_all_var_info unit testing! ~
	t_format	var_result;
	char	*str;
	str = (char *)malloc(sizeof(char) * 7);
	str[0] = '%';
	str[1] = '-';
	str[2] = ' ';
	str[3] = '5';
	str[4] = '.';
	str[5] = '2';
	str[6] = 'd';
	str[7] = '\0';
	var_result = test_get_all_var_info(&str, 15);
	if (var_result.flags != (SPACE + MINUS))
		printf("Flags not detected properly for '%%- 5.2d'.  Flags should be set to %d and we received %d\n", (SPACE + MINUS), var_result.flags);
	if (var_result.length != 0)
		printf("length not set appropriately for '%%- 5.2d'. Length should be set to %d and we received %d\n", 0, var_result.length);
	if (var_result.spec != D)
		printf("Spec not set appropriately for '%%- 5.2d'. Spec should be set to %d and it is %d\n", D, var_result.spec);
	if (var_result.width != 5)
		printf("Width does not match for '%%- 5.2d'. Should be 5 and it is set to %d\n", var_result.width);
	if (var_result.precision != 2)
		printf("Precision does not match for '%%- 5.2d'. Should be 2 and it is set to %d\n", var_result.precision);
	if ((*(int *)var_result.value) != 15)
		printf("The value of the variable is incorrect.  It should be set to 15 and it is currently %d\n", (*(int *)var_result.value));
	if (*str != '\0')
		printf("The input string was left off at an incorrect positioni for test '%%- 5.2d'.  We expect to be at the end of the string and the current value is %c\n", *str);

	// Test 2
	char	*str2;
	str2 = (char *)malloc(sizeof(char) * 25);
	str2[0] = '%';
	str2[1] = '-';
	str2[2] = ' ';
	str2[3] = '-';
	str2[4] = ' ';
	str2[5] = '-';
	str2[6] = ' ';
	str2[7] = '-';
	str2[8] = ' ';
	str2[9] = '-';
	str2[10] = ' ';
	str2[11] = '-';
	str2[12] = ' ';
	str2[13] = '-';
	str2[14] = '-';
	str2[15] = '-';
	str2[16] = '-';
	str2[17] = ' ';
	str2[18] = ' ';
	str2[19] = ' ';
	str2[20] = '5';
	str2[21] = '.';
	str2[22] = '2';
	str2[23] = 'd';
	str2[24] = '\0';
	var_result = test_get_all_var_info(&str2, -2147483648);
	if (var_result.flags != (SPACE + MINUS))
		printf("Flags not detected properly for '%%- - - - - - ----   5.2d'.  Flags should be set to %d and we received %d\n", (SPACE + MINUS), var_result.flags);
	if (var_result.length != 0)
		printf("length not set appropriately for '%%- - - - - - ----   5.2d'. Length should be set to %d and we received %d\n", 0, var_result.length);
	if (var_result.spec != D)
		printf("Spec not set appropriately for '%%- - - - - - ----   5.2d'. Spec should be set to %d and it is %d\n", D, var_result.spec);
	if (var_result.width != 5)
		printf("Width does not match for '%%- - - - - - ----   5.2d'. Should be 5 and it is set to %d\n", var_result.width);
	if (var_result.precision != 2)
		printf("Precision does not match for '%%- - - - - - ----   5.2d'. Should be 2 and it is set to %d\n", var_result.precision);
	if ((*(int *)var_result.value) != -2147483648)
		printf("The value of the variable is incorrect.  It should be set to -2147483648 and it is currently %d\n", (*(int *)var_result.value));
	if (*str != '\0')
		printf("The input string was left off at an incorrect positioni for test '%%- - - - - - ----   5.2d'.  We expect to be at the end of the string and the current value is %c\n", *str);
// That's the end for detection functions.... for now

// ~ get_hex_length unit tests ~
	int	hex_length = 0;
	long long hex_lnum = 2552345;
	get_hex_length(hex_lnum, &hex_length);
	if (hex_length != 6)
		printf("length should be %d and it returned as %d from get_hex_length\n", 6, hex_length);
	
	hex_length = 0;
	char hex_cnum = 'a';
	get_hex_length(hex_cnum, &hex_length);
	if (hex_length != 2)
		printf("length should be %d and it returned as %d from get_hex_length\n", 2, hex_length);

	//	~ print_xx_var tests ~
	printf(" ~ HEX OUTPUT UNIT TESTS ~\n\n\n");
	t_format	print_xx_var;
	int			real_length_print_xx;
	int			my_length_print_xx;
	int			print_xx_varval;
	printf("\n'%%-5X':\n");
	initialize_format(&print_xx_var);
	print_xx_varval = 2552345;
	printf("printf:\n");
	real_length_print_xx =  printf("%-5X", print_xx_varval);
	printf("\n");
	print_xx_var.value = (void *)(&print_xx_varval);
	print_xx_var.flags = MINUS;
	print_xx_var.width = 5;
	print_xx_var.spec = CX;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
		printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%-5X'\n", my_length_print_xx, real_length_print_xx);



	printf("\n'%%#50':\n");
	initialize_format(&print_xx_var);
	print_xx_varval = 4535962;
	printf("printf:\n");
	real_length_print_xx =  printf("%#50x", print_xx_varval);
	printf("\n");
	print_xx_var.value = (void *)(&print_xx_varval);
	print_xx_var.flags = ALTERNATE;
	print_xx_var.width = 50;
	print_xx_var.spec = X;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
		printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%#50x'\n", my_length_print_xx, real_length_print_xx);



	printf("\n'%%015hhx':\n");
	initialize_format(&print_xx_var);
	unsigned char print_xx_charval = 'A';
	printf("printf:\n");
	real_length_print_xx =  printf("%015hhX", print_xx_charval);
	printf("\n");
	print_xx_var.value = (void *)(&print_xx_charval);
	print_xx_var.flags = ZERO;
	print_xx_var.width = 15;
	print_xx_var.spec = CX;
	print_xx_var.length = HH;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
		printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%015hhx'\n", my_length_print_xx, real_length_print_xx);

	
	
	printf("\n'%%-.25hx':\n");
	initialize_format(&print_xx_var);
	unsigned short print_xx_shortval = 'z';
	printf("printf:\n");
	real_length_print_xx =  printf("%-.25hx", print_xx_shortval);
	printf("\n");
	print_xx_var.value = (void *)(&print_xx_shortval);
	print_xx_var.flags = MINUS;
	print_xx_var.width = 0;
	print_xx_var.precision = 25;
	print_xx_var.spec = X;
	print_xx_var.length = HH;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
		printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%-.15hx'\n", my_length_print_xx, real_length_print_xx);



	printf("\n'%%0.15x' with a negative integer:\n");
	initialize_format(&print_xx_var);
	print_xx_varval = -42;
	printf("printf:\n");
	real_length_print_xx =  printf("%0.15x", print_xx_varval);
	printf("\n");
	print_xx_var.value = (void *)(&print_xx_varval);
	print_xx_var.flags = ZERO;
	print_xx_var.width = 0;
	print_xx_var.precision = 15;
	print_xx_var.spec = X;
	print_xx_var.length = 0;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
		printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%0.15xx'\n", my_length_print_xx, real_length_print_xx);



	printf("\n'%%#X', 0xff7744\n");
	initialize_format(&print_xx_var);
	print_xx_varval = 0xff7744;
	printf("printf:\n");
	real_length_print_xx =  printf("%#X", print_xx_varval);
	printf("\n");
	print_xx_var.value = (void *)(&print_xx_varval);
	print_xx_var.flags = ALTERNATE;
	print_xx_var.width = 0;
	print_xx_var.precision = -1;
	print_xx_var.spec = CX;
	print_xx_var.length = 0;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
	printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%#X'\n", my_length_print_xx, real_length_print_xx);



	printf("\n'%%hhx' with a negative unsigned char:\n");
	initialize_format(&print_xx_var);
	print_xx_varval = 10;
	unsigned char lol  = -10;
	printf("printf:\n");
	real_length_print_xx =  printf("%hhx", lol);
	printf("\n");
	print_xx_var.value = (void *)(&lol);
	print_xx_var.flags = ZERO;
	print_xx_var.width = 0;
	print_xx_var.precision = 0;
	print_xx_var.spec = X;
	print_xx_var.length = HH;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
		printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%hhx with a negative unsigned char'\n", my_length_print_xx, real_length_print_xx);



	printf("\n'%%lx, 30000001245258745' :\n");
	initialize_format(&print_xx_var);
	print_xx_varval = 10;

	printf("printf:\n");
	unsigned long lol2 = 30000001245258745;
	real_length_print_xx =  printf("%lx", lol2);
	printf("\n");
	print_xx_var.value = (void *)(&lol2);
	print_xx_var.flags = ZERO;
	print_xx_var.width = 0;
	print_xx_var.precision = -1;
	print_xx_var.spec = X;
	print_xx_var.length = L;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
		printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%lx, 30000001245258745'\n", my_length_print_xx, real_length_print_xx);



	printf("\n'%%.0X, 0xaabbcc' :\n");
	initialize_format(&print_xx_var);
	print_xx_varval = 0xaabbcc;

	printf("printf:\n");
	real_length_print_xx =  printf("%.0X", print_xx_varval);
	printf("\n");
	print_xx_var.value = (void *)(&print_xx_varval);
	print_xx_var.flags = 0;
	print_xx_var.width = 0;
	print_xx_var.precision = 0;
	print_xx_var.spec = CX;
	print_xx_var.length = 0;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
		printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%.0X, 0xaabbcc'\n", my_length_print_xx, real_length_print_xx);



	printf("\n'%%.7X, 0xaa' :\n");
	initialize_format(&print_xx_var);
	print_xx_varval = 0xaa;

	printf("printf:\n");
	real_length_print_xx =  printf("%.7X", print_xx_varval);
	printf("\n");
	print_xx_var.value = (void *)(&print_xx_varval);
	print_xx_var.flags = 0;
	print_xx_var.width = 0;
	print_xx_var.precision = 7;
	print_xx_var.spec = CX;
	print_xx_var.length = 0;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
		printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%.7X, 0xaa'\n", my_length_print_xx, real_length_print_xx);

	
	
	printf("\n'%%-6x, 0xdd66' :\n");
	initialize_format(&print_xx_var);
	print_xx_varval = 0xdd66;

	printf("printf:\n");
	real_length_print_xx =  printf("%-6x", print_xx_varval);
	printf("\n");
	print_xx_var.value = (void *)(&print_xx_varval);
	print_xx_var.flags = MINUS;
	print_xx_var.width = 6;
	print_xx_var.precision = 0;
	print_xx_var.spec = X;
	print_xx_var.length = 0;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
		printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%-6x, 0xdd66'\n", my_length_print_xx, real_length_print_xx);

	
	
	printf("\n'%%20x, 0x123456bc' :\n");
	initialize_format(&print_xx_var);
	print_xx_varval = 0x123456bc;

	printf("printf:\n");
	real_length_print_xx =  printf("%20x", print_xx_varval);
	printf("\n");
	print_xx_var.value = (void *)(&print_xx_varval);
	print_xx_var.flags = 0;
	print_xx_var.width = 20;
	print_xx_var.precision = 0;
	print_xx_var.spec = X;
	print_xx_var.length = 0;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
		printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%20x, 0x123456bc'\n", my_length_print_xx, real_length_print_xx);


	printf("\n'%%10.7x, 1234566' :\n");
	initialize_format(&print_xx_var);
	print_xx_varval = 1234566;

	printf("printf:\n");
	real_length_print_xx =  printf("%10.7x", print_xx_varval);
	printf("\n");
	print_xx_var.value = (void *)(&print_xx_varval);
	print_xx_var.flags = 0;
	print_xx_var.width = 10;
	print_xx_var.precision = 7;
	print_xx_var.spec = X;
	print_xx_var.length = 0;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
		printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%10.7x, 1234566'\n", my_length_print_xx, real_length_print_xx);

	printf("\n'%%10.2x, 1234566' :\n");
	initialize_format(&print_xx_var);
	print_xx_varval = 1234566;

	printf("printf:\n");
	real_length_print_xx =  printf("%10.2x", print_xx_varval);
	printf("\n");
	print_xx_var.value = (void *)(&print_xx_varval);
	print_xx_var.flags = 0;
	print_xx_var.width = 10;
	print_xx_var.precision = 2;
	print_xx_var.spec = X;
	print_xx_var.length = 0;
	printf("My printf:\n");
	my_length_print_xx = printxx(print_xx_var, 1);
	printf("\n\n\n");
	if (my_length_print_xx != real_length_print_xx)
		printf("The lengths for print hex don't match.  Mine is %d and the real printf id %d for '%%10.2x, 1234566'\n", my_length_print_xx, real_length_print_xx);


//	length = printf("printf:\n%-.55X\n", num);
//	length = printf("printf:\n%-10.55X\n", num);
//	length = printf("printf:\n%-70.55X\n", num);
//	length = printf("printf:\n%-X\n", num);


	long long decimal1 = 9645;
	long long round_dec_result;

	round_dec_result = round_decimal(decimal1, 3);
	if (round_dec_result != 965)
		printf("round decimal result is incorrect for 9645. Expected 965 and got %lld\n", round_dec_result);

	decimal1 = 26361657423;
	round_dec_result = round_decimal(decimal1, 5);
	if (round_dec_result != 26362)
		printf("round decimal result is incorrect for 26361657423. Expected 26362 and got %lld\n", round_dec_result);

	decimal1 = 26361657423;
	round_dec_result = round_decimal(decimal1, 8);
	if (round_dec_result != 26361657)
		printf("round decimal result is incorrect for 26361657423. Expected 26361657 and got %lld\n", round_dec_result);

	decimal1 = 26361657423;
	round_dec_result = round_decimal(decimal1, 11);
	if (round_dec_result != 26361657423)
		printf("round decimal result is incorrect for 26361657423. Expected 26361657423 and got %lld\n", round_dec_result);

	decimal1 = 9223372036854775807;
	round_dec_result = round_decimal(decimal1, 19);
	if (round_dec_result != 9223372036854775807)
		printf("round decimal result is incorrect for 9223372036854775807 (long long max). Expected 9223372036854775807 and got %lld\n", round_dec_result);

	//Zero is protected from the parent function.  I am not going to account for it.


	
	//	~ Float unit tests ~
	double d1;
	int	my_float_length;
	int real_float_length;
	t_format float_tests_struct;
	initialize_format(&float_tests_struct);
	d1 = 55.3;
	printf("printf:\n");
	real_float_length =  printf("%lf", d1);
	float_tests_struct.value = (void *)(&d1);
	float_tests_struct.spec = F;
	float_tests_struct.length = L;
	printf("\n");
	printf("My printf:\n");
	my_float_length = print_floats(float_tests_struct), 1;
	printf("\n\n\n");
	if (my_float_length != real_float_length)
		printf("The lengths for print floats don't match.  Mine is %d and the real printf is %d for '%%lf'\n", my_float_length, real_float_length);

	initialize_format(&float_tests_struct);
	d1 = 55.3;
	printf("printf:\n");
	real_float_length =  printf("%25.10lf", d1);
	float_tests_struct.value = (void *)(&d1);
	float_tests_struct.spec = F;
	float_tests_struct.length = L;
	float_tests_struct.precision = 10;
	float_tests_struct.width = 25;
	printf("\n");
	printf("My printf:\n");
	my_float_length = print_floats(float_tests_struct, 1);
	printf("\n\n\n");
	if (my_float_length != real_float_length)
		printf("The lengths for print floats don't match.  Mine is %d and the real printf is %d for '%%25.10lf'\n", my_float_length, real_float_length);

	initialize_format(&float_tests_struct);
	d1 = -987.0;
	printf("printf:\n");
	real_float_length =  printf("%lf", d1);
	double *ptr;
	ptr = &d1;
	float_tests_struct.value = (void *)(ptr);
	float_tests_struct.spec = F;
	float_tests_struct.length = L;
	float_tests_struct.precision = -1;
	float_tests_struct.width = 0;
	printf("\n");
	printf("My printf:\n");
	my_float_length = print_floats(float_tests_struct, 1);
	printf("\n\n\n");
	if (my_float_length != real_float_length)
		printf("The lengths for print floats don't match.  Mine is %d and the real printf is %d for '%%lf'\n", my_float_length, real_float_length);


	initialize_format(&float_tests_struct);
	d1 = 922337203685477580.9862452;
	printf("printf:\n");
	real_float_length =  printf("%lf", d1);
	ptr = &d1;
	float_tests_struct.value = (void *)(ptr);
	float_tests_struct.spec = F;
	float_tests_struct.length = L;
	float_tests_struct.precision = -1;
	float_tests_struct.width = 0;
	printf("\n");
	printf("My printf:\n");
	my_float_length = print_floats(float_tests_struct, 1);
	printf("\n\n\n");
	if (my_float_length != real_float_length)
		printf("The lengths for print floats don't match.  Mine is %d and the real printf is %d for '%%lf'\n", my_float_length, real_float_length);

	initialize_format(&float_tests_struct);
	d1 = 922337203685478.9;
	printf("printf:\n");
	real_float_length =  printf("%lf", d1);
	ptr = &d1;
	float_tests_struct.value = (void *)(ptr);
	float_tests_struct.spec = D;
	float_tests_struct.length = L;
	float_tests_struct.precision = -1;
	float_tests_struct.width = 0;
	printf("\n");
	printf("My printf:\n");
	my_float_length = print_floats(float_tests_struct, 1);
	printf("\n\n\n");
	if (my_float_length != real_float_length)
		printf("The lengths for print floats don't match.  Mine is %d and the real printf is %d for '%%lf'\n", my_float_length, real_float_length);

	initialize_format(&float_tests_struct);
	d1 = -9226.666545409;
	printf("printf:\n");
	real_float_length =  printf("%25.15lf", d1);
	ptr = &d1;
	float_tests_struct.value = (void *)(ptr);
	float_tests_struct.spec = D;
	float_tests_struct.length = L;
	float_tests_struct.width = 25;
	float_tests_struct.precision = 15;
	printf("\n");
	printf("My printf:\n");
	my_float_length = print_floats(float_tests_struct, 1);
	printf("\n\n\n");
	if (my_float_length != real_float_length)
		printf("The lengths for print floats don't match.  Mine is %d and the real printf is %d for '%%lf'\n", my_float_length, real_float_length);

	float f1;
	initialize_format(&float_tests_struct);
	f1 = -92234.62345665;
	printf("printf:\n");
	real_float_length =  printf("%25.15f", f1);
	float_tests_struct.value = (void *)(&f1);
	float_tests_struct.spec = D;
	float_tests_struct.length = 0;
	float_tests_struct.width = 25;
	float_tests_struct.precision = 15;
	printf("\n");
	printf("My printf:\n");
	my_float_length = print_floats(float_tests_struct, 1);
	printf("\n\n\n");
	if (my_float_length != real_float_length)
		printf("The lengths for print floats don't match.  Mine is %d and the real printf is %d for '%%lf'\n", my_float_length, real_float_length);




	long double get_mantissa_test;
long double get_mantissa_ld(long double num);
	

	get_mantissa_test = 9.5;
	get_mantissa_ld(get_mantissa_test);
//	printf("%Lf\n", get_mantissa_ld(get_mantissa_test));

	float	float_get_mantissa_test;
	float_get_mantissa_test = 9.5;

	float	get_mantissa_f(float num);

	printf("%f\n", get_mantissa_f(float_get_mantissa_test));

////////////////////OCTAL

	int			my_oct_length;
	int			real_oct_length;
	t_format	octal_struct;
	initialize_format(&octal_struct);
	unsigned int	octal_int;

	octal_int = 65446;
	octal_struct.value = (void *)(&octal_int);
	printf("My printf:\n");
	my_oct_length = printo(octal_struct, 1);
	printf("\n");
	printf("The real printf:\n");
	real_oct_length = printf("%o", octal_int);
	printf("\n");
	if (real_oct_length != my_oct_length)
		printf("Return vals for octal dont match for a basic test.  The real printf is %d and mine is %d\n", real_oct_length, my_oct_length);

	octal_int = 123456;
	octal_struct.value = (void *)(&octal_int);
	octal_struct.width = 10;
	octal_struct.precision = 7;
	printf("My printf:\n");
	my_oct_length = printo(octal_struct, 1);
	printf("\n");
	printf("The real printf:\n");
	real_oct_length = printf("%10.7o", octal_int);
	printf("\n");
	if (real_oct_length != my_oct_length)
		printf("Return vals for octal dont match for a basic test.  The real printf is %d and mine is %d\n", real_oct_length, my_oct_length);


	octal_int = -34152124;
	octal_struct.value = (void *)(&octal_int);
	octal_struct.width = 5;
	octal_struct.precision = 5;
	printf("My printf:\n");
	my_oct_length = printo(octal_struct, 1);
	printf("\n");
	printf("The real printf:\n");
	real_oct_length = printf("%5.5o", octal_int);
	printf("\n");
	if (real_oct_length != my_oct_length)
		printf("Return vals for octal dont match for a basic test.  The real printf is %d and mine is %d\n", real_oct_length, my_oct_length);

	
	t_format	get_mantissa_struct;

	double f = 9.5;
	get_mantissa_struct.value = (void *)(&f);
	if (strcmp(get_mantissa_d(get_mantissa_struct), "844424930131968"))
		printf("The get_mantissa test is not working properly.  Expected was '844424930131968' and output was '%s'\n", get_mantissa_d(get_mantissa_struct));

	char *num_mult;
	char *answer_mult;

	num_mult = (char *)malloc(sizeof(char) * (4 + 1));
	strcpy(num_mult, "9999");
	answer_mult = multiply_string_cm(15, num_mult);
	if (strcmp(answer_mult, "327647232"))
		printf("multiply string not working properly. expected '327647232' and got '%s'\n", answer_mult);

	char *num_add;
	char *answer_add;
	
	answer_add = add_string_cm("99999", "999999999", strlen("99999"), strlen("999999999"));
	if (strcmp(answer_add, "1000099998"))
		printf("add_string not working properly. 99999 + 999999999 = 1000099998 not %s\n", answer_add);

	answer_add = add_string_cm("190812874", "4890198127834134", strlen("190812874"), strlen("4890198127834134"));
	if (strcmp(answer_add, "4890198318647008"))
		printf("add_string not working properly. 190812874 + 4890198127834134 = 4890198318647008 not %s\n", answer_add);

	answer_add = add_string_cm("293847018234109750982459867", "908127304712734812340987", strlen("293847018234109750982459867"), strlen("908127304712734812340987"));
	if (strcmp(answer_add, "294755145538822485794800854"))
		printf("add_string not working properly. 293847018234109750982459867 + 908127304712734812340987 = 294755145538822485794800854 not %s\n", answer_add);


	char *answer_div;
	answer_div = (char *)malloc(sizeof(char) * (8));
	strcpy(answer_div, "9.113"); 
	answer_div = divide_string_cm(1, &answer_div);
	if (strcmp("4.5565", answer_div))
		printf("divide_string_cm does not work properly.  9.113 * (2 ^ -1) = 4.5565 not %s\n", answer_div);

	strcpy(answer_div, "9.513"); 

	answer_div = (char *)malloc(sizeof(char) * (8));
	strcpy(answer_div, "9.113"); 
	answer_div = divide_string_cm(2, &answer_div);
	if (strcmp("2.27825", answer_div))
		printf("divide_string_cm does not work properly.  9.113 * (2 ^ -2) = 2.27825 not %s\n", answer_div);

	strcpy(answer_div, "9.513"); 

	answer_div = (char *)malloc(sizeof(char) * (8));
	strcpy(answer_div, "9.113"); 
	answer_div = divide_string_cm(5, &answer_div);
	if (strcmp("0.28478125", answer_div))
		printf("divide_string_cm does not work properly.  9.113 * (2 ^ -5) = 0.28478125 not %s\n", answer_div);

	strcpy(answer_div, "9.513"); 

	answer_div = (char *)malloc(sizeof(char) * (8));
	strcpy(answer_div, "9.113"); 
	answer_div = divide_string_cm(10, &answer_div);
	if (strcmp("0.0088994140625", answer_div))
		printf("divide_string_cm does not work properly.  9.113 * (2 ^ -10) = 0.0088994140625 not %s\n", answer_div);

	answer_div = (char *)malloc(sizeof(char) * (8));
	strcpy(answer_div, "9.113"); 
	answer_div = divide_string_cm(15, &answer_div);
	if (strcmp("0.000278106689453125", answer_div))
		printf("divide_string_cm does not work properly.  9.113 * (2 ^ -15) = 0.000278106689453125 not %s\n", answer_div);

	answer_div = (char *)malloc(sizeof(char) * (8));
	strcpy(answer_div, "9.113"); 
	answer_div = divide_string_cm(200, &answer_div);
	if (strcmp("0.00000000000000000000000000000000000000000000000000000000000567103382271485843772038557220982722044989680135559960839504757105785254745644492995092891731446281913288365306158311796025373041629791259765625", answer_div))
		printf("divide_string_cm does not work properly.  9.113 * (2 ^ -200) = 0.00000000000000000000000000000000000000000000000000000000000567103382271485843772038557220982722044989680135559960839504757105785254745644492995092891731446281913288365306158311796025373041629791259765625 not %s\n", answer_div);

	strcpy(answer_div, "9.513"); 
	answer_div = divide_string_cm(1, &answer_div);
	if (strcmp("4.75665", answer_div))
		printf("divide_string_cm does not work properly.  9.5133 * (2 ^ -1) = 4.75665 not %s\n", answer_div);

	strcpy(answer_div, "9.513"); 

	strcpy(answer_div, "9.513"); 
	answer_div = divide_string_cm(2, &answer_div);
	if (strcmp("2.378325", answer_div))
		printf("divide_string_cm does not work properly.  9.5133 * (2 ^ -2) = 2.378325 not %s\n", answer_div);

	strcpy(answer_div, "9.513"); 

	strcpy(answer_div, "9.513"); 
	answer_div = divide_string_cm(5, &answer_div);
	if (strcmp("0.297290625", answer_div))
		printf("divide_string_cm does not work properly.  9.5133 * (2 ^ -5) = 0.297290625 not %s\n", answer_div);

	strcpy(answer_div, "9.513"); 
	answer_div = divide_string_cm(10, &answer_div);
	if (strcmp("0.00929033203125", answer_div))
		printf("divide_string_cm does not work properly.  9.5133 * (2 ^ -10) = 0.00929033203125 not %s\n", answer_div);

	strcpy(answer_div, "9.513"); 
	answer_div = divide_string_cm(55, &answer_div);
	if (strcmp("0.00000000000000026404711750416254290030337870121002197265625", answer_div))
		printf("divide_string_cm does not work properly.  9.5133 * (2 ^ -55) = 0.00000000000000026404711750416254290030337870121002197265625 not %s\n", answer_div);

	
	
	free(answer_div);
	answer_div = (char *)malloc(sizeof(char) * (ft_strlen("976543456545654567898765") + 1));




	strcpy(answer_div, "976543456545654567898765");
	answer_div = divide_string_cm(1, &answer_div);	
	if (strcmp("488271728272827283949382.5", answer_div))
		printf("divide_string_cm does not work properly.  976543456545654567898765 * (2 ^ -1) =  488271728272827283949382.5 not %s\n", answer_div);


	strcpy(answer_div, "976543456545654567898765");
	answer_div = divide_string_cm(2, &answer_div);	
	if (strcmp("244135864136413641974691.25", answer_div))
		printf("divide_string_cm does not work properly.  976543456545654567898765 * (2 ^ -2) =  244135864136413641974691.25 not %s\n", answer_div);


	strcpy(answer_div, "976543456545654567898765");
	answer_div = divide_string_cm(5, &answer_div);	
	if (strcmp("30516983017051705246836.40625", answer_div))
		printf("divide_string_cm does not work properly.  976543456545654567898765 * (2 ^ -5) =  30516983017051705246836.40625 not %s\n", answer_div);


	strcpy(answer_div, "976543456545654567898765");
	answer_div = divide_string_cm(10, &answer_div);	
	if (strcmp("953655719282865788963.6376953125", answer_div))
		printf("divide_string_cm does not work properly.  976543456545654567898765 * (2 ^ -10) = 953655719282865788963.6376953125 not %s\n", answer_div);


	strcpy(answer_div, "976543456545654567898765");
	answer_div = divide_string_cm(15, &answer_div);	
	if (strcmp("29801741227589555905.113677978515625", answer_div))
		printf("divide_string_cm does not work properly.  976543456545654567898765 * (2 ^ -15) =  29801741227589555905.113677978515625 not %s\n", answer_div);


	strcpy(answer_div, "976543456545654567898765");
	answer_div = divide_string_cm(25, &answer_div);	
	if (strcmp("29103262917567925.6885875761508941650390625", answer_div))
		printf("divide_string_cm does not work properly.  976543456545654567898765 * (2 ^ -25) =  29103262917567925.6885875761508941650390625 not %s\n", answer_div);


	strcpy(answer_div, "976543456545654567898765");
	answer_div = divide_string_cm(50, &answer_div);	
	if (strcmp("867344824.00321738983951735946220651385374367237091064453125", answer_div))
		printf("divide_string_cm does not work properly.  976543456545654567898765 * (2 ^ -50) =  867344824.00321738983951735946220651385374367237091064453125 not %s\n", answer_div);


	t_format print_floats_test;
	double	print_floats_double;

	print_floats_double = 15.565;
	print_floats_test.value = (void *)(&print_floats_double);
	print_floats_test.precision = 25;
	print_floats_test.width = 0;
	print_floats_test.flags = 0;
	print_floats_test.length = 0;
	printf("%.25f\n", print_floats_double);
	printf("\n");
	print_floats(print_floats_test, 1);
	
	print_floats_double = 15.56511111111;
	print_floats_test.value = (void *)(&print_floats_double);
	print_floats_test.precision = -1;
	print_floats_test.width = 15;
	print_floats_test.length = 0;
	print_floats_test.flags = MINUS;
	print_floats(print_floats_test, 1);
	printf("\n");
	printf("%-15f\n", print_floats_double);

	print_floats_double = 15.56511111111;
	print_floats_test.value = (void *)(&print_floats_double);
	print_floats_test.precision = -1;
	print_floats_test.width = 15;
	print_floats_test.length = 0;
	print_floats_test.flags = ZERO;
	printf("\n");
	printf("%015f\n", print_floats_double);
	print_floats(print_floats_test, 1);

	print_floats_double = 15.56511111111;
	print_floats_test.value = (void *)(&print_floats_double);
	print_floats_test.precision = -1;
	print_floats_test.width = 15;
	print_floats_test.flags = 0;
	print_floats_test.length = 0;
	printf("\n");
	printf("%15f\n", print_floats_double);
	print_floats(print_floats_test, 1);

	print_floats_double = 15.56599999999999;
	print_floats_test.value = (void *)(&print_floats_double);
	print_floats_test.precision = -1;
	print_floats_test.width = 0;
	print_floats_test.flags = 0;
	print_floats_test.length = 0;
	printf("\n");
	printf("%f\n", print_floats_double);
	print_floats(print_floats_test, 1);

	print_floats_double = -999.99999999991;
	print_floats_test.value = (void *)(&print_floats_double);
	print_floats_test.precision = -1;
	print_floats_test.width = 0;
	print_floats_test.flags = 0;
	print_floats_test.length = 0;
	printf("\n");
	printf("%f\n", print_floats_double);
	print_floats(print_floats_test, 1);


	print_floats_double = 123412345134.5234634567456745623458907342587902345890;
	print_floats_test.value = (void *)(&print_floats_double);
	print_floats_test.precision = 55;
	print_floats_test.width = 0;
	print_floats_test.flags = 0;
	print_floats_test.length = 0;
	printf("\n");
	printf("%.55f\n", print_floats_double);
	print_floats(print_floats_test, 1);

	double NAN = 0.0/0.0;
	double POS_INF = 1.0 /0.0;
	double NEG_INF = -1.0/0.0;

	print_floats_double = 999.99999999991;
	print_floats_test.value = (void *)(&NAN);
	print_floats_test.precision = -1;
	print_floats_test.width = 0;
	print_floats_test.flags = 0;
	print_floats_test.length = 0;
	printf("\n");
	printf("%f\n", NAN);
	print_floats(print_floats_test, 1);


	print_floats_double = 999.99999999991;
	print_floats_test.value = (void *)(&POS_INF);
	print_floats_test.precision = -1;
	print_floats_test.width = 0;
	print_floats_test.flags = 0;
	print_floats_test.length = 0;
	printf("\n");
	printf("%f\n", POS_INF);
	print_floats(print_floats_test, 1);


	print_floats_double = 999.99999999991;
	print_floats_test.value = (void *)(&NEG_INF);
	print_floats_test.precision = -1;
	print_floats_test.width = 0;
	print_floats_test.flags = 0;
	print_floats_test.length = 0;
	printf("\n");
	printf("%f\n", NEG_INF);
	print_floats(print_floats_test, 1);

	//Getting an access after free error on this test. I have no idea why.
	print_floats_double = 1.1;
	print_floats_test.value = (void *)(&print_floats_double);
	print_floats_test.precision = -1;
	print_floats_test.width = 0;
	print_floats_test.flags = 0;
	print_floats_test.length = 0;
	printf("\n");
	printf("%f\n", print_floats_double);
	print_floats(print_floats_test, 1);

	long double	print_floats_ld;

	printf("The size of this is %lu\n", sizeof(t_unholy_l));

	printf("\n\nLong double tests:\n\n");
	print_floats_ld = 1.1;
	print_floats_test.value = (void *)(&print_floats_ld);
	print_floats_test.precision = -1;
	print_floats_test.width = 0;
	print_floats_test.flags = 0;
	print_floats_test.length = CL;
	printf("\n");
	printf("%Lf\n", print_floats_ld);
	print_floats(print_floats_test, 1);

	printf("\n\nLong double tests:\n\n");
	print_floats_ld = 65465.465465;
	print_floats_test.value = (void *)(&print_floats_ld);
	print_floats_test.precision = -1;
	print_floats_test.width = 0;
	print_floats_test.flags = 0;
	print_floats_test.length = CL;
	printf("\n");
	printf("%Lf\n", print_floats_ld);
	print_floats(print_floats_test, 1);

	// ~ Print unsigned unit tests
	printf("\n\nUnsigned tests:\n\n");
	unsigned int	unsigned_int;
	t_format		unsigned_struct;

	unsigned_int = 50;
	initialize_format(&unsigned_struct);
	unsigned_struct.value = (void *)(&unsigned_int);
	printf("\n");
	printf("%u\n", unsigned_int);
	printu(unsigned_struct, 1);
	printf("\n");

	unsigned_int = -50;
	initialize_format(&unsigned_struct);
	unsigned_struct.value = (void *)(&unsigned_int);
	printf("\n");
	printf("%u\n", unsigned_int);
	printu(unsigned_struct, 1);
	printf("\n");



	// ~ Print d/i unit tests
	printf("\n\nd/i tests:\n\n");
	int				_int;
	int				retm;
	int				retp;
	int				d_count;
	t_format		_struct;

	d_count = 1;

	printf("\n");
	printf("test of 50:\n");
	_int = 50;
	initialize_format(&_struct);
	_struct.value = (void *)(&_int);
	retp = printf("%u", _int);
	printf("\n");
	retm = printd(_struct, 1);
	if (retm != retp)
		printf("return values don't match for printf.  I expect %d retp and got %d for test %d\n", retp, retm, d_count++);
	printf("\n");

	printf("\n");
	printf("test of -50:\n");
	_int = -50;
	initialize_format(&_struct);
	_struct.value = (void *)(&_int);
	retp = printf("%d", _int);
	printf("\n");
	retm = printd(_struct, 1);
	if (retm != retp)
		printf("return values don't match for printf.  I expect %d retp and got %d for test %d\n", retp, retm, d_count++);
	printf("\n");

	printf("\n");
	printf("test of -2147483648:\n");
	_int = -2147483648;
	initialize_format(&_struct);
	_struct.value = (void *)(&_int);
	retp = printf("%d", _int);
	printf("\n");
	retm = printd(_struct, 1);
	if (retm != retp)
		printf("return values don't match for printf.  I expect %d retp and got %d for test %d\n", retp, retm, d_count++);
	printf("\n");

	printf("\n");
	printf("test of 0:\n");
	_int = 0;
	initialize_format(&_struct);
	_struct.value = (void *)(&_int);
	retp = printf("%d", _int);
	printf("\n");
	retm = printd(_struct, 1);
	if (retm != retp)
		printf("return values don't match for printf.  I expect %d retp and got %d for test %d\n", retp, retm, d_count++);
	printf("\n");

	printf("\n");
	printf("test of %%10.7d, 155:\n");
	_int = 155;
	initialize_format(&_struct);
	_struct.value = (void *)(&_int);
	_struct.precision = 7;
	_struct.width = 10;
	retp = printf("%10.7d", _int);
	printf("\n");
	retm = printd(_struct, 1);
	if (retm != retp)
		printf("return values don't match for printf.  I expect %d retp and got %d for test %d\n", retp, retm, d_count++);
	printf("\n");

	char	d_char;
	d_char = 127;
	printf("test of 140 for hh (signed char:\n");
	initialize_format(&_struct);
	_struct.value = (void *)(&d_char);
	_struct.length = HH;
	retp = printf("%hhd", d_char);
	printf("\n");
	retm = printd(_struct, 1);
	if (retm != retp)
		printf("return values don't match for printf.  I expect %d retp and got %d for test %d\n", retp, retm, d_count++);
	printf("\n");

	d_char = 0;
	printf("test of 0 for hh (signed char:\n");
	initialize_format(&_struct);
	_struct.value = (void *)(&d_char);
	_struct.length = HH;
	retp = printf("%hhd", d_char);
	printf("\n");
	retm = printd(_struct, 1);
	if (retm != retp)
		printf("return values don't match for printf.  I expect %d retp and got %d for test %d\n", retp, retm, d_count++);
	printf("\n");


	printf("\n\np unit tests\n\n");
	char * some_string;
	some_string = malloc(sizeof(char) * 2);
	_struct.value = (void *)some_string;
	retp = printf("%p", _struct.value);
	printf("\n");
	retm = printp(_struct, 1);
	printf("\n");
	if (retm != retp)
		printf("return values don't match for p.  I expect %d retp and got %d\n", retp, retm);
	printf("\n");
	free(some_string);

	some_string = malloc(sizeof(char) * 2);
	_struct.value = (void *)some_string;
	_struct.width = 10;
	retp = printf("%10p", _struct.value);
	printf("\n");
	retm = printp(_struct, 1);
	printf("\n");
	if (retm != retp)
		printf("return values don't match for p.  I expect %d retp and got %d\n", retp, retm);
	printf("\n");
	free(some_string);

	some_string = malloc(sizeof(char) * 2);
	_struct.value = (void *)some_string;
	_struct.width = 35;
	retp = printf("%35p", _struct.value);
	printf("\n");
	retm = printp(_struct, 1);
	printf("\n");
	if (retm != retp)
		printf("return values don't match for p.  I expect %d retp and got %d\n", retp, retm);
	printf("\n");
	free(some_string);

	some_string = malloc(sizeof(char) * 2);
	_struct.value = (void *)some_string;
	_struct.width = 35;
	_struct.flags = MINUS;
	retp = printf("%-35p", _struct.value);
	printf("\n");
	retm = printp(_struct, 1);
	printf("\n");
	if (retm != retp)
		printf("return values don't match for p.  I expect %d retp and got %d\n", retp, retm);
	printf("\n");
	free(some_string);

	some_string = 0;
	_struct.value = (void *)some_string;
	_struct.width = 0;
	retp = printf("%p", _struct.value);
	printf("\n");
	retm = printp(_struct, 1);
	printf("\n");
	if (retm != retp)
		printf("return values don't match for p.  I expect %d retp and got %d\n", retp, retm);
	printf("\n");

}
