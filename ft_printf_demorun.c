/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_demorun.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:49:30 by shaun             #+#    #+#             */
/*   Updated: 2025/02/06 19:49:32 by shaun             ###   ########kl       */
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
	int		nbr_of_inputs;
	size_t		i;
	va_list		arg_list;

	nbr_of_inputs = 0;
	i = 0;
	va_start(arg_list, string);
	while (string[i])
	{
		if (string[i] != '%')
			ft_putchar_fd(string[i++], 1);
		else if (string[i++] == '%')
		{
			nbr_of_inputs++;
			ft_printf_util1(string, i, arg_list);
			ft_printf_util2(string, i, arg_list);
			i++;
		}
	}
	//int	ft_printf_util1(const char *string, size_t index, int inputs, va_list);
	//int	ft_printf_util1(const char *string, size_t index, int inputs, va_list)
	//int	ft_printf_util2(const char *string, size_t index, int inputs, va_list);
	//int	ft_printf_util2(const char *string, size_t index, int inputs, va_list)
	va_end(arg_list);
	return (nbr_of_inputs);
}
