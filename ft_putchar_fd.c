/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shaun <sng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:36:51 by shaun             #+#    #+#             */
/*   Updated: 2025/01/14 22:36:59 by shaun             ###   ########kl       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <fcntl.h>

// int	main(void)
// {
// 	int fd = open("./test.c", O_RDWR);
// 	ft_putchar_fd('c', fd);
// 	return (0);
// }
int	ft_putchar_fd(char c, int fd)
{
	//printf("%p\n", &c);
	write(fd, &c, 1);
	//n++;
	return (1);
}
