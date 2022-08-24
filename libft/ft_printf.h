/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 04:55:50 by vde-vasc          #+#    #+#             */
/*   Updated: 2022/08/23 23:53:21 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"
# include <unistd.h>

int	ft_printf(const char *text, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int num);
int	ft_puthexa_case(unsigned long num, char flags);
int	ft_puthexa(unsigned long num, char flags);
int	argument_case(char c, va_list arguments);
int	ft_putunbr(unsigned int number);
#endif
