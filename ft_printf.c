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
	ft_printf("This is Lar, %s, %c", "Puppy", 'c');
	return (0);
}

int	ft_printf(const char *string, ...)
{
	char		char_placeholder;
	char		*string_placeholder;
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
				char_placeholder = va_arg(arg_list, int);
				ft_putchar_fd(char_placeholder, 1);
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
			else if (string[i] == 'p')
			{
				
			}
		}
	}
	// then look in the va_list for the next argument and run the function
	// that will print that argument
	return (nbr_of_inputs);
}
