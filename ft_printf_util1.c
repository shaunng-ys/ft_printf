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

void	ft_printf_util1(const char *string, size_t index, va_list *args)
{
	char		*string_placeholder;
	char		*hex_low;
	size_t		j;

	hex_low = "0123456789abcdef";
	j = 0;
	if (string[index] == 'c')
		ft_putchar_fd(va_arg(*args, int), 1);
	else if (string[index] == 's')
	{
		string_placeholder = va_arg(*args, char *);
		while (string_placeholder[j])
			ft_putchar_fd(string_placeholder[j++], 1);
	}
	else if (string[index] == 'u')
		ft_putnbr_base(va_arg(*args, unsigned int), "0123456789");
	else if (string[index] == 'p')
	{
		write(1, "0x", 2);
		ft_putnbr_base(((unsigned long)va_arg(*args, void *)), hex_low);
	}
}
