/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:22:19 by schavez           #+#    #+#             */
/*   Updated: 2023/12/28 18:22:25 by schavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_print_pointer(uintptr_t num, int *total)
{
	if (num >= 16)
	{
		ft_print_pointer(num / 16, total);
		ft_print_pointer(num % 16, total);
	}
	else
	{
		ft_put_chr(HEX_LOWER[num], total);
	}
}

void	ft_handle_p(unsigned long n, int *total)
{
	if (!n)
	{
		ft_handle_s("(nil)", total);
		return ;
	}
	else
	{
		ft_handle_s("0x", total);
		ft_print_pointer(n, total);
	}
}

void	ft_handle_x(unsigned int n, int *total, int isLower)
{
	if (n >= 16)
		ft_handle_x(n / 16, total, isLower);
	if (isLower == 1)
		ft_put_chr(HEX_LOWER[n % 16], total);
	else
		ft_put_chr(HEX_UPPER[n % 16], total);
}
