/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:26:14 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/04 16:06:56 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void     *func(unsigned int i, char *c)
{
        if (i >= 0)
                *c = toupper(*c);
}
int     main(void)
{
        char string[] = "hello carnal";
        ft_striteri(string, func);
        printf("%s\n", string);
        return (0);
}*/
