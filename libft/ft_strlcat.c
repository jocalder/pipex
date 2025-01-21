/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:13:55 by jocalder          #+#    #+#             */
/*   Updated: 2024/09/23 15:39:30 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = 0;
	dstlen = 0;
	while (dst[dstlen] != '\0' && dstlen < size)
		dstlen++;
	while (src[srclen] != '\0')
		srclen++;
	if (dstlen == size)
		return (size + srclen);
	i = 0;
	while (src[i] != '\0' && (dstlen + i) < (size - 1))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*
int main(void)
{
	char d[] = "Hola carnal";
	char s[] = "la vaina esta dura";
	printf("%zu\n", ft_strlcat(d, s, 10));
	return (0);
}*/
