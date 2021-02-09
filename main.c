#include <stdio.h>
#include "ft_printf.c"

int	main(void)
{
	/*
		int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
	*/
	// int num = 123;
	ft_printf("%0*p::\n", 14, "abcd");
	//ft_printf("%16p::\n", &num);

	printf("%016p::\n", 2036854705807);
	printf("1234567890\n");
	printf("%4.3%::");

//		float	fn = 123;
//	int num = -12345;
//	char *buff = "d";b //"abcde";
//	int	digit;
//	int	temp;
	//ft_printf("::%-5.2d::\n", -123);
//ft_printf("%20s","abcde");
////char	*o = "abc";
////	ft_printf("%c::\n", "abc");
	//ft_printf("1234567890123456789\n");
	//ft_printf("%-5c::\n", 'c');
	//ft_printf("%*d::", -2, 4);
	//while (1)
	//;

//	printf("%-.d::\n",-);
/*
//	printf("::%id::", 0);
	printf("123456789012345\n");
	printf("%8.10d%n\n",num, &temp);
	printf("%01d%n\n",num, &temp);
	printf("::::%d\n", temp);
*/
//	printf("----------\n");
//	printf("%05.10d%n\n", num, &temp);
//	printf("::::%d\n", temp);
}
/*
int		main(void)
{
	int num = 12345;

	printf("::%0-10d::\n",num);
	ft_printf("::%0-10d::\n",num);
	ft_printf("%s%s%s\n", "hello:", "",":tstst");
//	printf("%s%s\n", "hello", "world");

	int num = -54321;
	printf("      1234567890123456789\n");
	printf("sys ::%-10.7d::\n",num);
	ft_printf("mine::%-10.7d::\n", num);
	printf("      1234567890123456789\n");
	printf("sys ::% 1.7d::\n",num);
	ft_printf("mine::% 1.7d::\n", num);
	printf("      1234567890123456789\n");
	printf("sys ::% 10.7d::\n",num);
	ft_printf("mine::% 10.7d::\n", num);
		printf("      1234567890123456789\n");
	printf("sys ::% 1.1d::\n",num);
	ft_printf("mine::% 1.1d::\n", num);
		printf("      1234567890123456789\n");
	printf("sys ::% -10.7d::\n",num);
	ft_printf("mine::% -10.7d::\n", num);

//%s
	char ch;

	ch = 'a';
	ft_printf("%-10.*s::\n", 4,"-abcde");
	printf("1234567890123456789\n");
	printf("%-10.*s::\n",4, "-abcde");


//
//%d
	int	digit;
	int num = 12345;
	int	temp;


	digit = ft_printf("%%%-1.8d:%d::\n%n", num, num, &temp);
	ft_printf("nop=>%d\n",temp);
	ft_printf("digit=>%d\n",digit);
	printf("1234567890123456789\n");
	digit = printf("%%%-1.8d:%d::\n%n", num, num, &temp);
	printf("nop=>%d\n",temp);
	printf("digit=>%d\n",digit);
//%p
	//int	temp;
	char ddd;
	ft_printf("hex:::%-*p", 20, &ddd);
	printf("///\n");
	printf("hex:::%-*p", 20, &ddd);
	printf("///\n");


	int num2;
	int temp;
	int digit;

	num2 = 12345;

	digit = printf("%%% +012.20d:%d::\n%n", num2, num2, &temp);
	printf("nop=>%d\n",temp);
	printf("digit=>%d\n",digit);
		printf("1234567890123456789\n");
	digit = ft_printf("%%% +012.20d:%d::\n%n", num2, num2, &temp);
	ft_printf("nop=>%d\n",temp);
	ft_printf("digit=>%d\n",digit);
	printf("1234567890123456789\n");

}
*/
