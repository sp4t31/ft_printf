/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:40:05 by spatel            #+#    #+#             */
/*   Updated: 2022/08/07 21:46:07 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*	prints string type
*/

int	ft_print_str(char *str)
{
	int	printed_bytes;

	printed_bytes = 0;
	if (!str)
	{
		ft_print_str("(null)");
		return (6);
	}
	while (*str)
	{
		ft_putchar(*str);
		str++;
		printed_bytes++;
	}
	return (printed_bytes);
}
