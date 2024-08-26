/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:22:09 by tszymans          #+#    #+#             */
/*   Updated: 2024/08/26 20:46:03 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

int	main(int argc, char **argv)
{
	t_node	root;
	t_node	elem2;
	t_node	*curr;

	root.x = 15;
	root.next = malloc(sizeof(t_node));
	root.next->x = 29;
	root.next->next = malloc(sizeof(t_node));
	root.next->next->x = 35;
	root.next->next->next = NULL;
	curr = &root;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}

	free(root.next->next);
	free(root.next);
	return (0);
}
