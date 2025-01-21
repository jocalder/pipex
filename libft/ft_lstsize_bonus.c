/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:44:29 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/08 21:16:20 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
/*
int main(void)
{
	t_list *first = ft_lstnew("first node");
	t_list *second = ft_lstnew("second node");
	t_list *third = ft_lstnew("third node");

	first->next = second;
	second->next = third;
	third->next = NULL;

	int size = ft_lstsize(first);
	printf("%d", size);
	return (0);
}*/
