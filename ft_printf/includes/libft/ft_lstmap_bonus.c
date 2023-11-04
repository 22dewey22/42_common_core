/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:23:19 by dwayenbo          #+#    #+#             */
/*   Updated: 2023/10/16 09:47:22 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current_lst;
	t_list	*current_new_lst;
	t_list	*first_new_node;

	if (!lst)
		return (0);
	first_new_node = ft_lstnew(f(lst->content));
	if (!first_new_node)
		return (0);
	current_lst = lst;
	current_new_lst = first_new_node;
	while (current_lst->next)
	{
		current_lst = current_lst->next;
		ft_lstadd_back(&first_new_node, ft_lstnew(f(current_lst->content)));
		if (!current_new_lst->next)
		{
			ft_lstclear(&first_new_node, del);
			return (0);
		}
		current_new_lst = current_new_lst->next;
	}
	return (first_new_node);
}
