/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:35:59 by spatel            #+#    #+#             */
/*   Updated: 2022/07/21 16:37:03 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr(long int n)
{
	if (n < 0)
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
	return (ft_calculate_bytes(n, 10));
}
