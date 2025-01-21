/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:23:58 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/16 19:52:39 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*
int main(void)
{
	char *str = "hello carnal";
	char *result = ft_substr(str, 4, 3);
	printf("%s\n", result);
	free(result);
	result = ft_substr(str, 0, 20);
	printf("%s\n", result);
	free(result);
	result = ft_substr(str, 13, 4);
	printf("%s\n", result);
	free(result);
	char *str1 = NULL;
	char *res = ft_substr(str1, 4, 8);
	printf("%s\n", res);
	free(res);
	return 0;
}*/
