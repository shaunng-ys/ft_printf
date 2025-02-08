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

int	ft_printf_util2(const char *string, size_t index, va_list *args, int n)
{
	int	int_placeholder;
	int	a;
	int	*d;

	a = 0;
	d = &a;
	if (string[index] == 'd' || string[index] == 'i')
	{
		int_placeholder = va_arg(*args, int);
		if (int_placeholder < 0)
		{
			n = n + ft_putchar_fd('-', 1);
			//n++;
			int_placeholder = int_placeholder * -1;
		}
		n = n + ft_putnbr_base(int_placeholder, "0123456789", d);
	}
	else if (string[index] == 'x')
		n = n + ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef", d);
	else if (string[index] == 'X')
		n = n + ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF", d);
	else if (string[index] == '%')
	{
		n = n + ft_putchar_fd('%', 1);
		//n++;
	}
	//printf("This is the output of util2: %d\n", n);
	return (n);
}
