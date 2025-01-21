/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:06:03 by jocalder          #+#    #+#             */
/*   Updated: 2024/09/23 20:32:40 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}
/*
int main(void)
{
	char *str1 = "hola carnal";
	char *str2 = "chido carnal en la onda";
	printf("%d\n", ft_memcmp(str1, str2, 20));
	char *st1 = "hola carnal";
	char *st2 = "kuibo";
	printf("%d\n", ft_memcmp(st1, st2, 20));
	char *t1 = "panita";
	char *t2 = "panita";
	printf("%d\n", ft_memcmp(t1, t2, 20));
}*/
