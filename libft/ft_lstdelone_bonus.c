/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:04:41 by jocalder          #+#    #+#             */
/*   Updated: 2024/10/09 18:43:45 by jocalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL && del != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
/*
void	delete(void *content)
{
	free(content);
}

int main(void)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return (1);
	node->content = malloc(20 * sizeof(char));
	if (!node->content)
	{
		free(node);
		return (1);
	}
	strcpy(node->content, "hello world puto");
	node->next = NULL;
	ft_lstdelone(node, delete);
	return (0);
}*/
