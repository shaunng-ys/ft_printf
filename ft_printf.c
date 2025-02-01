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
	char		*string_copy;
	int		nbr_of_inputs;
	size_t		i;
	va_list		arg_list;

	string_copy = string;
	nbr_of_inputs = 0;
	i = 0;
	va_start(arg_list, string_copy);
	while (string_copy[i])
	{
    		if (string_copy[i] != '%')
			ft_putchar(string_copy[i++], 1);
		else if (string_copy[i] == '%')
		{
			nbr_of_inputs++;
			i++;
			if (string_copy[i] == c)
				ft_putchar(va_arg(arg_list, char), 1);
			else if (string_copy[i] == s)
				while (va_arg(arg_list, char *))[j], 1)
					ft_putchar(va_arg(arg_list, char *)[j++], 1);
			i++;
		}
	}
}
	// then look in the va_list for the next argument and run the function
	// that will print that argument
	return (nbr_of_inputs);
}
