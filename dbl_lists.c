/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:22:09 by tszymans          #+#    #+#             */
/*   Updated: 2024/09/01 13:03:29 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbl_lists.h"

void	deallocate(t_node **tail, t_node **head)
{
	t_node	*curr;

	if (tail == NULL)
		return ;
	curr = *tail;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	*tail = NULL;
	*head = NULL;
}

void	insert_beg(t_node **tail, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->x = value;
	new_node->prev = NULL;
	new_node->next = *tail;
	(*tail)->prev = new_node;
	*tail = new_node;
}

void	init(t_node **tail, t_node **head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(2);
	new_node->x = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	*tail = new_node;
	*head = new_node;
}

void	insert_end(t_node **head, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(3);
	new_node->x = value;
	new_node->prev = *head;
	new_node->next = NULL;
	(*head)->next = new_node;
	*head = new_node;
}

void	insert_after(t_node *node, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(4);
	new_node->x = value;
	new_node->prev = node;
	new_node->next = node->next;
	if (node->next != NULL)
		node->next->prev = new_node;
	node->next = new_node;
}

void	remove_node(t_node *node)
{
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
	free(node);
}

t_node	*find_node(t_node *tail, int value)
{
	t_node	*curr;

	curr = tail;
	while (curr != NULL)
	{
		if (curr->x == value)
			return (curr);
		curr = curr->next;
	} 
	return (NULL);
}

t_node	*find_node_recursive(t_node *node, int value)
{
	if (!node)
		return (0);
	if (node->x == value)
		return (node);
	return (find_node_recursive(node->next, value));
}

int		count_rec(t_node *node)
{
	if (node == NULL)
		return (0);
	return(1 + count_rec(node->next));
}

int	main(int argc, char **argv)
{
	t_node	*tail;
	t_node	*head;
	t_node	*curr;
	t_node	*aux;
	t_node	*found;

	init(&tail, &head, 7);
	insert_beg(&tail, 3);
	insert_beg(&tail, 1);
	insert_end(&head, 9);
	insert_after(tail->next->next, 8);
	remove_node(tail->next->next);
	//if we want to remove tail (or head) we need to update tail (or head)
	aux = tail->next;
	remove_node(tail);
	tail = aux;

	curr = tail;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}

	found = find_node_recursive(tail, 8);
	if (!found)
		printf("No node found\n");
	else
		printf("Found value: %d, next: %p\n", found->x, found->next);
	
	printf("The list is %d elements long\n", count_rec(tail));
	//reversed
	printf("Reversed list\n");
	curr = head;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->prev;
	}
	deallocate(&tail, &head);
	return (0);
}
