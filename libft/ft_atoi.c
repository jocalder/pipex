/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:48:23 by jocalder          #+#    #+#             */
/*   Updated: 2024/09/24 17:11:43 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
	{
		nptr++;
	}
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
		{
			sign = -1;
		}
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
	{
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	return (result * sign);
}
/*
int main(void)
{
	printf("%d\n", ft_atoi("4890+--"));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi(""));
	printf("%d\n", ft_atoi("-37  "));
	printf("%d\n", ft_atoi("--37"));
	printf("%d\n", ft_atoi(" "));
	printf("%d\n", ft_atoi("++38"));
	printf("%d\n", ft_atoi("    +85"));
	printf("%d\n", ft_atoi("  -86   "));
	return (0);
}*/
