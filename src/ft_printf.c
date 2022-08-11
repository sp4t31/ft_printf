/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:03:04 by spatel            #+#    #+#             */
/*   Updated: 2022/08/11 15:22:22 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
-- error checking
-- hex void pointer
-- write return
-- write percentage error
-- can convert char to *char? double on them
-- passing & to not create duplicate variables?
-- *i -1
-- % without something following it  (return (-1))?
*/

int	ft_indexer(char a, va_list ap, int *i)
{
	if (a == '%')
		return (ft_putchar('%'));
	else if (a == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (a == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (a == 'd' || a == 'i')
		return (ft_int(va_arg(ap, int)));
	else if (a == 'p')
		return (ft_ptr_address(va_arg(ap, unsigned long)));
	else if (a == 'u' || a == 'x' || a == 'X')
		return (ft_unsigned_int(va_arg(ap, unsigned int), a));
	else
		*i = *i - 1;
	return (0);
}

/*	writes a string in the console with the option to add 
	multiple data types through variadic arguments and returns
	the number of bytes printed
*/

int	ft_printf(const char *str, ...)
{
	int		i;
	int		printed_bytes;
	va_list	ap;

	i = 0;
	printed_bytes = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			printed_bytes += ft_indexer(str[++i], ap, &i);
		else if (str[i])
			printed_bytes += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (printed_bytes);
}
/*
int	main(void)
{
	printf("\n%i\n", ft_printf("%i %u %d", -10, -10, -10));
	printf("\n%i\n", printf("%i %u %d", -10, -10, -10));
	ft_printf("%% %\n");
}*/
