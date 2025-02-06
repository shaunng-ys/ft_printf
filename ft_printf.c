/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:50:03 by shaun             #+#    #+#             */
/*   Updated: 2025/01/26 21:50:05 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	int		c = 'z';
	void		*ptr = &c;
	unsigned int	forty = 9475982;
	ft_printf("This is Lar, %s, %c, %p, %d, %i, %u, %x, %X\n", "Puppy", 'c', ptr, 123, 123, 4294967295u, forty, forty);
	printf("This is Lar, %s, %c, %p, %d, %i, %u, %x, %X\n", "Puppy", 'c', ptr, 123, 123, 4294967295u, forty, forty);
	//printf("%d\n", LONG_MAX);
	return (0);
}

int	ft_printf(const char *string, ...)
{
	//char		char_placeholder;
	char		*string_placeholder;
	//unsigned int	hex_placeholder;
	int		nbr_of_inputs;
	size_t		i;
	size_t		j;
	va_list		arg_list;

	nbr_of_inputs = 0;
	i = 0;
	j = 0;
	va_start(arg_list, string);
	while (string[i])
	{
    		if (string[i] != '%')
			ft_putchar_fd(string[i++], 1);
		else if (string[i] == '%')
		{
			nbr_of_inputs++;
			i++;
			if (string[i] == 'c')
			{
				//char_placeholder = va_arg(arg_list, int);
				ft_putchar_fd(va_arg(arg_list, int), 1);
				i++;
			}
			else if (string[i] == 's')
			{
				string_placeholder = va_arg(arg_list, char *);
				while (string_placeholder[j])
					ft_putchar_fd(string_placeholder[j++], 1);
				i++;
				j = 0;
			}
			else if (string[i] == 'u')
			{
				ft_putnbr_base(va_arg(arg_list, unsigned int), "0123456789");
				i++;
			}
			else if (string[i] == 'p')
			{
				write(1, "0x", 2);
				ft_putnbr_base(((unsigned long)va_arg(arg_list, void *)), "0123456789abcdef");
				i++;
			}
			else if (string[i] == 'X')
			{
				//hex_placeholder = va_arg(arg_list, unsigned int);
				ft_putnbr_base(va_arg(arg_list, unsigned int), "0123456789ABCDEF");
				i++;
			}
			else if (string[i] == 'd' || string[i] == 'i')
			{
				//string_placeholder = ft_itoa(va_arg(arg_list, int));
				ft_putnbr_base(va_arg(arg_list, int), "0123456789");
				//while (string_placeholder[j])
				//	ft_putchar_fd(string_placeholder[j++], 1);
				i++;
				//j = 0;
			}	
			//else if (string[i] == 'u')
			else if (string[i++] == 'x')
	    		{
				//hex_placeholder = va_arg(arg_list, unsigned int);
				ft_putnbr_base(va_arg(arg_list, unsigned int), "0123456789abcdef");
				//i++;
			}
			else if (string[i++] == '%')
			{
				ft_putchar_fd('%', 1);
				//i++;
			}
		}
	}
	return (nbr_of_inputs);
}
