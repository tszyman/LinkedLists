/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:22:09 by tszymans          #+#    #+#             */
/*   Updated: 2024/08/31 12:55:20 by tomek            ###   ########.fr       */
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
void	remove_element(t_node **root, int value)
{
	t_node	*curr;
	t_node	*to_remove;

	if (*root == NULL)
		return ;
	if ((*root)->x == value)
	{
		to_remove = *root;
		*root = (*root)->next;
		free(to_remove);
		return ;
	}
	curr = *root;
	while (curr->next != NULL)
	{
		if (curr->next->x == value)
		{
			to_remove = curr->next;
			curr->next = curr->next->next;
			free(to_remove);
			return ;
		}
		curr = curr->next;
	}
}
void	reverse_list(t_node **root)
{
	t_node	*pre; //previous
	t_node	*cur; //current
	t_node	*nex; //next

	pre = NULL;
	cur = *root;
	
	while (cur != NULL)
	{
		nex = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nex;
	}
	*root = pre;
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
	insert_sorted(&root, 7);
	remove_element(&root, 3);
	reverse_list(&root);
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
