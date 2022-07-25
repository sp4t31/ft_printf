/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_hex_lc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:33:26 by spatel            #+#    #+#             */
/*   Updated: 2022/07/22 17:44:06 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_hex(unsigned int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 12);
	else if (n < 0)
	{
		write(1, '-', 1);
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		write(1, n % 10 + '0', 1);
	}
	else
		write(1, n + '0', 1);
}

int	ft_unsigned_hex_lc(unsigned int x);
{
	//write unsigned int x
	ft_unsigned_dec(x);
	//calculate no.bytes printed

}