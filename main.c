#include <stdio.h>
#include "./libft.h"

int		main(void)
{
	printf("system::%.*s::\n",-2,NULL);
	ft_printf("mine::%.*s",-2, NULL);
	return 1;
}
