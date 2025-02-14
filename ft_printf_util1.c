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
	unsigned int	pl;
	unsigned long	ul;
	size_t		cyc;

	hex_low = "0123456789abcdef";
	j = 0;
	a = 0;
	if (string[index] == 'c')
		n = n + ft_putchar_fd(va_arg(*args, int), 1);
	else if (string[index] == 's')
	{
		string_placeholder = va_arg(*args, char *);
		if (string_placeholder == NULL)
			return (n + write(1, "(null)", 6));
		while (string_placeholder[j])
			n = n + ft_putchar_fd(string_placeholder[j++], 1);
	}
	else if (string[index] == 'u')
	{
		pl = va_arg(*args, unsigned int);
		cyc = itr(pl, "0123456789");
		n = n + ft_putnbr_base(pl, "0123456789", d, cyc);
	}
	else if (string[index] == 'p')
	{
		write(1, "0x", 2);
		n = n + 2;
		ul = (unsigned long)va_arg(*args, void *);
		cyc = itr(ul, hex_low);
		n = n + ft_putnbr_base(ul, hex_low, d, cyc);
	}
	return (n);
}
