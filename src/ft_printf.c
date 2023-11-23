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

#include "../include/ft_printf.h"


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

void	ft_handle_p(unsigned long n, int *total, int i)
{
	if (!n)
	{
		ft_handle_s("(nil)", total);
		return ;
	}
	else
	{
		if (n < 16)
		{
			ft_handle_s("0x", total);
			ft_put_chr(HEX_LOWER[n % 16], total);
		}
		ft_handle_p(n / 16, total, ++i);
		ft_put_chr(HEX_LOWER[n % 16], total);
	}
}

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
void	ft_handle_x(unsigned int n, int *total, int isLower)
{
	if (n >= 16)
		ft_handle_x(n / 16, total, isLower);
	if (isLower == 1)
		ft_put_chr(HEX_LOWER[n % 16], total);
	else	
		ft_put_chr(HEX_UPPER[n % 16], total);
}

void	all_possible(char *fmt,va_list args, int i, int *total)
{
	if (fmt[i] == 'c')
		ft_put_chr(va_arg(args, int), total);
	else if (fmt[i] == 's')
		ft_handle_s(va_arg(args, char *), total);
	else if (fmt[i] == 'p')
		ft_handle_p(va_arg(args, unsigned long int), total, 0);
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
	int	i;
	int	total;

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