/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:54:08 by jocalder          #+#    #+#             */
/*   Updated: 2024/09/23 18:19:20 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*
int main(void)
{
	char *str1 = "hola carnal";
	char *str2 = "chido carnal en la onda";
	printf("%d\n", ft_strncmp(str1, str2, 20));
	char *st1 = "hola carnal";
	char *st2 = "kuibo";
	printf("%d\n", ft_strncmp(st1, st2, 20));
	char *t1 = "panita";
	char *t2 = "panita";
	printf("%d\n", ft_strncmp(t1, t2, 20));
}*/
