/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 23:59:12 by shaun             #+#    #+#             */
/*   Updated: 2025/02/02 23:59:15 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int nbr, char *base)
{
	size_t	counter;
	int	num;

	num = nbr;
	counter = ft_strlen(base);
	if (num > 0)
	{
		ft_putnbr_base(num / counter, base);
		ft_putchar_fd(num % counter + 48, 1);
	}
}
/*
int	main(void)
{
	//This is for decimal
	//ft_putnbr_base(40, "0123456789");
	//This is for binary
	//ft_putnbr_base(40, "01");
	//This is for hexadecimal
	ft_putnbr_base(40, "0123456789ABCDEF");
	//This is for octal
	//ft_putnbr_base(40, "poneyvif");
	return (0);
}
*/
