/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:06:50 by spatel            #+#    #+#             */
/*   Updated: 2022/08/11 15:38:53 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*	Prints the memory address of a pointer
	written in hexadecimal lowercase format '0x7ff68'
*/

void	ft_print_ptr_address(unsigned long n)
{
	if (n >= 16)
	{
		ft_print_ptr_address(n / 16);
		ft_print_ptr_address(n % 16);
	}
	if (n < 16)
	{
		if (n > 9)
			ft_putchar(n % 16 + 87);
		else
			ft_putchar(n + '0');
	}
}

/*	Returns the number of bytes printed for a 
	pointer address written in hexadecimal
*/

int	ft_ptr_address(unsigned long n)
{
	int	printed_bytes;

	printed_bytes = 2;
	write(1, "0x", 2);
	ft_print_ptr_address(n);
	if (n == 0)
		printed_bytes++;
	while (n != 0)
	{
		n /= 16;
		printed_bytes++;
	}
	return (printed_bytes);
}
