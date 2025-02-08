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
/*
//void	ft_putnbr_base(unsigned long nbr, char *base)
int	ft_putnbr_base(unsigned long nbr, char *base, int *digit_count)
{
	size_t	counter;
	unsigned long	num;
	int	add;

	num = nbr;
	add = 0;
	counter = ft_strlen(base);
	if (num > 0)
	{
		//add++;
		ft_putnbr_base(num / counter, base, digit_count);
		(*digit_count)++;
		//add = add + ft_putchar_fd(base[num % counter], 1);
		ft_putchar_fd((base[num % counter]), 1);
		//n++;
	}
	return (*digit_count);
}

int	main(void)
{
	int	n = 0;
	int	*d = &n;
	//This is for decimal
	//ft_putnbr_base(40, "0123456789");
	//This is for binary
	//ft_putnbr_base(40, "01");
	//This is for hexadecimal
	printf("%d\n", ft_putnbr_base(40350, "0123456789ABCDEF", d));
	//This is for octal
	//ft_putnbr_base(40, "poneyvif");
	return (0);
}

int    main(void)
{
    //This is for decimal
    //ft_putnbr_base(40, "0123456789");
    //This is for binary
    //ft_putnbr_base(40, "01");
    //This is for hexadecimal
    int n = 0;
    int *digit_counter = &n;
    printf("\n%d\n", ft_putnbr_base(40350, "0123456789ABCDEF", digit_counter));
    //This is for octal
    //ft_putnbr_base(40, "poneyvif");
    return (0);
}

int    ft_putchar(char c, int fd)
{
    //printf("%p\n", &c);
    write(fd, &c, 1);
    //n++;
    return (1);
}
*/

int    ft_putnbr_base(unsigned long nbr, char *base, int *digit_count)
{
    size_t    counter;
    unsigned long    num;
    //int    add;

    num = nbr;
    //add = 0;
    //a = a + a;
    counter = strlen(base);
    if (num > 0)
    {
        //add++;
        ft_putnbr_base(num / counter, base, digit_count);
        //add = add + ft_putchar_fd(base[num % counter], 1);
        (*digit_count)++;
        ft_putchar_fd((base[num % counter]), 1);
        //n++;
    }
    return ((*digit_count));
}
