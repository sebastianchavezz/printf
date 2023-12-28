/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:04:45 by schavez           #+#    #+#             */
/*   Updated: 2023/12/28 19:05:38 by schavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_put_chr(char c, int *total)
{
	*total += write(1, &c, 1);
}

void	ft_handle_s(char *str, int *total)
{
	int	i;

	i = -1;
	if (!str)
	{
		ft_handle_s("(null)", total);
		return ;
	}
	while (str[++i])
	{
		ft_put_chr(str[i], total);
	}
}
