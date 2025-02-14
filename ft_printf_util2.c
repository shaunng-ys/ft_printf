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
	char	*string_placeholder;
	int	*d;
	int	i;
	unsigned int	pl;
	size_t	cyc;

	i = 0;
	d = &i;
	if (string[index] == 'd' || string[index] == 'i')
	{
		string_placeholder = ft_itoa(va_arg(*args, int));
		while (string_placeholder[i])
			n = n + ft_putchar_fd(string_placeholder[i++], 1);
		free(string_placeholder);
	}
	else if (string[index] == 'x')
	{
		pl = va_arg(*args, unsigned int);
		cyc = itr(pl, "0123456789abcdef");
		n = n + ft_putnbr_base(pl, "0123456789abcdef", d, cyc);
		//n = n + ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef", d);
	}
	else if (string[index] == 'X')
	{
		pl = va_arg(*args, unsigned int);
		cyc = itr(pl, "0123456789ABCDEF");
		n = n + ft_putnbr_base(pl, "0123456789ABCDEF", d, cyc);
	}
	else if (string[index] == '%')
		n = n + ft_putchar_fd('%', 1);
	return (n);
}

