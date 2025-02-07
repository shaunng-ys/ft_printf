/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:23:58 by shaun             #+#    #+#             */
/*   Updated: 2025/02/06 16:24:00 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_util2(const char *string, size_t index, va_list *args)
{
	int	int_placeholder;

	if (string[index] == 'd' || string[index] == 'i')
	{
		int_placeholder = va_arg(*args, int);
		if (int_placeholder < 0)
		{
			ft_putchar_fd('-', 1);
			int_placeholder = int_placeholder * -1;
		}
		ft_putnbr_base(int_placeholder, "0123456789");
	}
	else if (string[index] == 'x')
		ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (string[index] == 'X')
		ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (string[index] == '%')
		ft_putchar_fd('%', 1);
}
