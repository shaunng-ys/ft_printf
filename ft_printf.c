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
	ft_printf("This is Lar");
	return (0);
}

// 1. The printf function will write each character of the intial string, one by
// one, until it finds a %.

// 2. When it finds a %, it will look at the element in the next index/position.
// It will find the character that will define the type of the first variable
// argument.

// 3. Depending on what it finds, it will call a method that will display the
// argument of the particular type at output.
// -> if there is a "s" after the %, then you will need a function that displays
// strings.
// -> if there is a "d" after the %, then you will need a function that displays
// numbers. etc.

// 4. Once the first variable argument has been written, you go back to step 1,
// until the string is finished (aka, until you find a null character (\0)).

int ft_printf(const char *string, ...) {
  int nbr_of_inputs;
  size_t i;

  nbr_of_inputs = 0;
  i = 0;
  while (string[i]) {
    if (string[i] == '%')
      // then look in the va_list for the next argument and run the function
      // that will print that argument
      else {
        ft_putchar(string[i++], 1);
      }
  }
  return (nbr_of_inputs);
}
