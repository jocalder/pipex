/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:18:05 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/08 21:39:52 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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

	t_list *last = ft_lstlast(first);
	printf("%s", (char *)last->content);
	return (0);
}*/
