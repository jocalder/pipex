/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:12:23 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/08 20:42:55 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
int main(void)
{
	t_list *head = ft_lstnew("first node");
	t_list *new_node = ft_lstnew("new first node");

	ft_lstadd_front(&head, new_node);
	while (head != NULL)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
	return (0);
}*/
