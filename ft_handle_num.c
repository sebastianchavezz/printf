/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:26:33 by schavez           #+#    #+#             */
/*   Updated: 2023/12/28 18:26:36 by schavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_handle_int(long n, int *total)
{
	if (n < 0)
	{
		ft_put_chr('-', total);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_handle_int(n / 10, total);
		ft_handle_int(n % 10, total);
	}
	else
	{
		ft_put_chr(n + '0', total);
	}
}

void	ft_handle_u(unsigned int n, int *total)
{
	if (n > 9)
	{
		ft_handle_u(n / 10, total);
		ft_handle_u(n % 10, total);
	}
	else
		ft_put_chr(n + '0', total);
}
