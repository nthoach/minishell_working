/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:06:42 by nthoach           #+#    #+#             */
/*   Updated: 2023/11/05 16:06:42 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (new && lst)
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

// int main()
// {
// 	t_list *lst = {ft_lstnew("akakaka")};
// 	t_list *new;
// 	char str[] = "oif";
// 	new = ft_lstnew(&str);
// 	printf("\n\n > lst %p\n", (char *)lst);
// 	printf(" > lst %p\n", lst->next);
// 	printf(" > lst %p\n", new);
// 	ft_lstadd_back(&lst, new);
// 	printf("\n\n > lst %s\n", (char *)lst->content);
// 	printf("\n\n > lst %s\n", (char *)lst->next->content);
// }