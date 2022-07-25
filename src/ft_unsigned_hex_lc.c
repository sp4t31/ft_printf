/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_hex_lc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:33:26 by spatel            #+#    #+#             */
/*   Updated: 2022/07/25 13:17:32 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr(int n)
{
	int n;

	if (n > 15)
	{
		ft_putnbr(n / 16);
		if (n % 16 > 9)
			write(1, n % 16 + 87, 1);
		else
			write(1, n % 16 + '0', 1);
	}
	else
	{
		if (n % 16 > 9)
			write(1, n % 16 + 87, 1);
		else
			write(1, n % 16 + '0', 1);
	}
}



int	ft_unsigned_hex_lc(unsigned int x);
{
	int	printed_bytes;
	
	//write unsigned int x
	if (x)
		ft_putnbr(x);
	//calculate no.bytes printed

}