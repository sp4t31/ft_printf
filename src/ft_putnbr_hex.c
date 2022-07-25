/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:16:33 by spatel            #+#    #+#             */
/*   Updated: 2022/07/25 16:16:33 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	print unsigned int (decimal) converted to hexadecimal 
	format (lowercase if case = 0, uppercase if case = 1)
*/

void	ft_putnbr_hex(unsigned int n, int case)
{
	if (n > 15)
	{
		ft_putnbr(n / 16);
		ft_putnbr(n % 16);
	}
	else
	{
		if (n > 9 && case == 0)
			write(1, n % 16 + 87, 1);
		if (n > 9 && case == 1)
			write(1, n % 16 + 55, 1);
		else if (n <= 9)
			write(1, n + '0', 1);
	}
	return (ft_calculate_bytes(n, 16));
}
