/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_bytes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:18:22 by spatel            #+#    #+#             */
/*   Updated: 2022/07/25 16:18:22 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	calculates the bytes printed from a number in decimal 
	format (base 10) or hexadecimal format (base 16)
*/

int	ft_calculate_bytes(unsigned int x, int base)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (x == 0)
		printed_bytes++;
	while (x != 0)
	{
		x /= base;
		printed_bytes++;
	}
	return (printed_bytes);
}
