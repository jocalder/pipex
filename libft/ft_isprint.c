/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:10:10 by jocalder          #+#    #+#             */
/*   Updated: 2024/09/19 16:04:24 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
/*
int main(void)
{
	printf("%d\n", ft_isprint(28));
	printf("%d\n", ft_isprint(33));
	printf("%d\n", ft_isprint(-2));
	return (0);
}*/
