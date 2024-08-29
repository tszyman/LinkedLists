/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:22:09 by tszymans          #+#    #+#             */
/*   Updated: 2024/08/29 22:57:04 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

void	insert_end(t_node **root, int value)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit (1);
	new_node->next = NULL;
	new_node->x = value;
	if (*root == NULL)
	{
		*root = new_node;
		exit (2);
	}
	curr = *root;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;
}

void	deallocate(t_node **root)
{
	t_node	*curr;
	t_node	*aux;

	curr = *root;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	*root = NULL;
}

void	insert_beg(t_node **root, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit (3);
	new_node->x = value;
	new_node->next = *root;
	*root = new_node;
}

void	insert_after(t_node *node, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit (4);
	new_node->x = value;
	new_node->next = node->next;
	node->next = new_node;
}

void	insert_sorted(t_node **root, int value)
{
	t_node	*curr;

	if (*root == NULL || (*root)->x >= value) // if list is empty or value is less than root value - add at the beginning
	{
		insert_beg(root, value);
		return ;
	}
	curr = *root;
	while (curr->next != NULL)	//iterate 
	{
		if (curr->next->x >= value)
		{
			insert_after(curr, value);
			return ;
		}
		curr = curr->next;
	}
	insert_after(curr, value);
}

int	main(int argc, char **argv)
{
	t_node	*root;
	t_node	*curr;

	root = malloc(sizeof(t_node));
	if (!root)
		return (1);
	root = NULL;
	insert_sorted(&root, 5);
	insert_sorted(&root, 3);
	insert_sorted(&root, 4);
	insert_sorted(&root, 6);
	//root->x = 15;
	//root->next = NULL;
	// insert_after(root, 16);
	// insert_end(&root, -2);
	// insert_end(&root, 11);
	// insert_beg(&root, 7);
	// insert_after(root, 8);
	// insert_after(root->next->next->next->next->next, 99);
	curr = root;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}
	deallocate(&root);
	return (0);
}
