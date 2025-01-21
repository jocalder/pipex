/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:04:50 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/01 14:47:33 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
int	main(void)
{
	ft_putendl_fd("Hello World", 1);
	int fd = open("test.txt", O_WRONLY | O_CREAT, 0666);
	if (fd == -1)
		return(1);
	ft_putendl_fd("Hello world", fd);
	close(fd);
	return (0);
}*/
