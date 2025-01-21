/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:53:03 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/17 20:18:27 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p1;

	i = 0;
	p1 = (unsigned char *)s;
	while (i < n)
	{
		p1[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main(void)
{
	char str[] = "que onda carnal";
	ft_memset(str, 'c', 8);
	printf("%s\n", str);
	return 0;
}*/
