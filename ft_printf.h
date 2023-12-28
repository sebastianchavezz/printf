/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schavez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:28:02 by schavez           #+#    #+#             */
/*   Updated: 2023/12/28 19:10:19 by schavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

void	ft_put_chr(char c, int *total);
void	ft_handle_s(char *str, int *total);
void	ft_handle_p(unsigned long n, int *total);
void	ft_handle_int(long n, int *total);
void	ft_handle_u(unsigned int n, int *total);
void	ft_handle_x(unsigned int n, int *total, int isLower);
void	ft_put_chr(char c, int *total);
int		ft_printf(const char *format, ...);
#endif
