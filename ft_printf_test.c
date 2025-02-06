/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:47:48 by shaun             #+#    #+#             */
/*   Updated: 2025/02/06 15:47:52 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	int		c = 'z';
	void		*ptr = &c;
	unsigned int	forty = 9475982;
	int		nbr_of_inputs;

	nbr_of_inputs = ft_printf("This is Lar, %s, %c, %p, %d, %i, %u, %x, %X\n", "Puppy", 'c', ptr, -123, -123, 4294967295u, forty, forty);
	ft_printf("%d\n", nbr_of_inputs);
	printf("This is Lar, %s, %c, %p, %d, %i, %u, %x, %X\n", "Puppy", 'c', ptr, -123, -123, 4294967295u, forty, forty);
	//printf("%d\n", LONG_MAX);
	return (0);
}

int	ft_printf(const char *string, ...)
{
	char		*string_placeholder;
	int			int_placeholder;
	int			nbr_of_inputs;
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
		else if(string[i++] == '%')
		{
			nbr_of_inputs++;
			if (string[i] == 'c')
				ft_putchar_fd(va_arg(arg_list, int), 1);
			else if (string[i] == 's')
			{
				string_placeholder = va_arg(arg_list, char *);
				while (string_placeholder[j])
					ft_putchar_fd(string_placeholder[j++], 1);
			}
			else if (string[i] == 'u')
				ft_putnbr_base(va_arg(arg_list, unsigned int), "0123456789");
			else if (string[i] == 'p')
			{
				write(1, "0x", 2);
				ft_putnbr_base(((unsigned long)va_arg(arg_list, void *)), "0123456789abcdef");
			}
			else if (string[i] == 'X')
				ft_putnbr_base(va_arg(arg_list, unsigned int), "0123456789ABCDEF");
			else if (string[i] == 'd' || string[i] == 'i')
			{
				int_placeholder = va_arg(arg_list, int);
				if (int_placeholder < 0)
				{
					ft_putchar_fd('-', 1);
					int_placeholder = int_placeholder * -1;
				}
				ft_putnbr_base(int_placeholder, "0123456789");
			}
			else if (string[i] == 'x')
				ft_putnbr_base(va_arg(arg_list, unsigned int), "0123456789abcdef");
			else if (string[i] == '%')
				ft_putchar_fd('%', 1);
			i++;	
		}
	}
	return (nbr_of_inputs);
}
