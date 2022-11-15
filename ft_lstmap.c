/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrabajo <gtrabajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:30:22 by gtrabajo          #+#    #+#             */
/*   Updated: 2022/11/15 17:43:56 by gtrabajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nova;

	nova = NULL;
	if (lst == NULL || del == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		ft_lstadd_back(&nova, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	return (nova);
}
