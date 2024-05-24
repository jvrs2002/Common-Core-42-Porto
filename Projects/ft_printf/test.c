#include "libftprintf.h"

int	main(void)
{
	size_t	count;
	char *str = "teste 123%da";
	count = 0;

	while (*str) {
		if (*str == '%' && *(str + 1) == '%')
		{
			write(1, "%", 1);
			str += 2;
			count++;
		}
		else if (*str == '%' && *(str + 1) != '%')
			str += 2;
		else
		{
			count += ft_putchar_pf(*str);
			str++;
		}
	}
	printf("\n\n%zu", count);
}
