/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:07:15 by nthoach           #+#    #+#             */
/*   Updated: 2023/11/05 16:07:15 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*next_node;

	next_node = (t_list *)malloc(sizeof(t_list));
	if (!next_node)
		return (NULL);
	next_node->content = content;
	next_node->next = NULL;
	return (next_node);
}

// int main()
// {
// 	printf("\n\n ...Started...\n\n\n");
// 	t_list *newguy = NULL;
// 	void *content = "fhhhj";
// 	newguy = ft_lstnew(content);
// 	printf("\n > newguy < --> %p", newguy);
// 	printf("\n > newguy age < --> %s",(char *)newguy->content);
// 	printf("\n > newguy next < --> %p", newguy->next);
// 	free(newguy);
// 	newguy = NULL;
// 	printf("\n > newguy < --> %p\n", newguy);
// }