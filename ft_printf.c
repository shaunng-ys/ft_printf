/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:03:00 by shaun             #+#    #+#             */
/*   Updated: 2025/02/07 16:03:05 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
int	main(void) 
{	
	int		c = 'z';
	void		*ptr = &c;
	unsigned int	forty = 9475;
	int		placelder = -0;
	int		nbr_of_inputs;
	int		nbr_of_inputs1;

	nbr_of_inputs = ft_printf("This is Lar, %s, %c, %p, %d, %i, %u, %x, %X\n", NULL, 'c', ptr, -1234, -123, 4294967295u, forty, forty);
	//ft_printf("%d\n", nbr_of_inputs);
	//printf("%d\n", placelder);
	//nbr_of_inputs = ft_printf("%d\n", placelder);
	ft_printf("%d\n", nbr_of_inputs);
	//nbr_of_inputs1 = printf("%d\n", placelder);
	//nbr_of_inputs1 = printf("This is Lar, %s, %c, %p, %d, %i, %u, %x, %X\n", "Puppy", 'c', ptr, -1234, -123, 4294967295u, forty, forty);
	//ft_printf("%d\n%d\n", nbr_of_inputs, nbr_of_inputs1);
	//printf("This is Lar, %s, %c, %p, %d, %i, %u, %x, %X\n", "Puppy", 'c', ptr, -123, -123, 4294967295u, forty, forty);
	//printf("%d\n", LONG_MAX);
	return (0);
}
*/
int	ft_printf(const char *string, ...)
{
	size_t	i;
	int	n;
	va_list	arg_list;

	i = 0;
	n = 0;
	va_start(arg_list, string);
	while (string[i])
	{
		if (string[i] != '%')
			n = n + ft_putchar_fd(string[i++], 1);
		else if (string[i++] == '%')
		{
			n = ft_printf_util1(string, i, &arg_list, n);
			n = ft_printf_util2(string, i, &arg_list, n);
			i++;
		}
	}
	va_end(arg_list);
	return (n);
}
