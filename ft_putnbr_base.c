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
	char	*dec_str;
	char	*bin_str;
	char	*hex_str;
	char	*oct_str;
	size_t	i;
	size_t	switch;

	dec_str = "0123456789";
	bin_str = "01";
	hex_str = "0123456789ABCDEF";
	oct_str = "poneyvif";
	i = 0;
	switch = 0;
	while (base[i] == dec_str[i])
		i++;
	if (base[i])
		i = 0;
	while (base[i] == bin_str[i])
		i++;
	if (base[i])
		i = 0;
	while (base[i] == hex_str[i])
		i++;
	if (base[i])
		i = 0;
	while (base[i] == oct_str[i])
		i++;
	if (base[i])
		i = 0;
	if (base[i])
		switch = 1;

}

int	main(void)
{
	//This is for decimal
	ft_putnbr_base(40, "0123456789");
	//This is for binary
	ft_putnbr_base(40, "01");
	//This is for hexadecimal
	ft_putnbr_base(40, "0123456789ABCDEF");
	//This is for octal
	ft_putnbr_base(40, "poneyvif");
	return (0);
}
