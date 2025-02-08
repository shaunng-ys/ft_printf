/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:23:47 by shaun             #+#    #+#             */
/*   Updated: 2025/02/06 16:23:50 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_util1(const char *string, size_t index, va_list *args, int n)
{
	char		*string_placeholder;
	char		*hex_low;
	size_t		j;
	int		a;
	int		*d = &a;

	hex_low = "0123456789abcdef";
	j = 0;
	a = 0;
	if (string[index] == 'c')
	{
		n = n + ft_putchar_fd(va_arg(*args, int), 1);
		//n++;
	}
	else if (string[index] == 's')
	{
		string_placeholder = va_arg(*args, char *);
		while (string_placeholder[j])
		{
			n = n + ft_putchar_fd(string_placeholder[j++], 1);
			//n++;
		}
	}
	else if (string[index] == 'u')
		n = n + ft_putnbr_base(va_arg(*args, unsigned int), "0123456789", d);
	else if (string[index] == 'p')
	{
		write(1, "0x", 2);
		n = n + 2;
		n = n + ft_putnbr_base(((unsigned long)va_arg(*args, void *)), hex_low, d);
	}
	
	//printf("This is the output of util1: %d\n", n);
	return (n);
}
