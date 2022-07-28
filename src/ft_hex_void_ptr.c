/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_void_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spatel <spatel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:37:23 by spatel            #+#    #+#             */
/*   Updated: 2022/07/21 16:44:41 by spatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//	prints the memory address of the void pointer argument in hexadecimal format

int	ft_hex_void_ptr(void *ptr)
{
	int	printed_bytes;
	
	printed_bytes = 2;
	write(1, "0x", 2);
	printed_bytes += write(1, &ptr, ft_strlen(&ptr)); 
}
