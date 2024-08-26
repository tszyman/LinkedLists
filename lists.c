/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:22:09 by tszymans          #+#    #+#             */
/*   Updated: 2024/08/26 21:08:01 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	insert_end(t_node **root, int value)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->next = NULL;
	new_node->x = value;
	if (*root == NULL)
	{
		*root = new_node;
		return;
	}
	curr = *root;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}

int	main(int argc, char **argv)
{
	t_node	*root;
	t_node	*curr;

	root = malloc(sizeof(t_node));
	if (!root)
		exit(2);
	root->x = 15;
	root->next = NULL;
	insert_end(&root, -2);
	insert_end(&root, 11);
	curr = root;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
	return (0);
}
