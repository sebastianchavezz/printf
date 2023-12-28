/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:06:29 by schavez           #+#    #+#             */
/*   Updated: 2023/10/24 19:06:53 by schavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	all_possible(char *fmt, va_list args, int i, int *total)
{
	if (fmt[i] == 'c')
		ft_put_chr(va_arg(args, int), total);
	else if (fmt[i] == 's')
		ft_handle_s(va_arg(args, char *), total);
	else if (fmt[i] == 'p')
		ft_handle_p(va_arg(args, unsigned long int), total);
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		ft_handle_int(va_arg(args, int), total);
	else if (fmt[i] == 'u')
		ft_handle_u(va_arg(args, unsigned int), total);
	else if (fmt[i] == 'x')
		ft_handle_x(va_arg(args, unsigned int), total, 1);
	else if (fmt[i] == 'X')
		ft_handle_x(va_arg(args, unsigned int), total, 0);
	else if (fmt[i] == '%')
		ft_put_chr('%', total);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			all_possible((char *)format, args, ++i, &total);
		else
			ft_put_chr(format[i], &total);
		i++;
	}
	va_end(args);
	return (total);
}
