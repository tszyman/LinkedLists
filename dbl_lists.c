/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:22:09 by tszymans          #+#    #+#             */
/*   Updated: 2024/08/31 15:47:06 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbl_lists.h"

int	main(int argc, char **argv)
{
	t_node	*tail;
	t_node	*head;
	t_node	*curr;


	tail = malloc(sizeof(t_node));
	if (!tail)
		exit(0);
	tail->x = 1;
	tail->prev = NULL;
	tail->next = malloc(sizeof(t_node));
	if (!tail->next)
		exit(1);
	tail->next->x = 3;
	tail->next->prev = tail;
	tail->next->next = malloc(sizeof(t_node));
	if (!tail->next->next)
		exit(2);
	tail->next->next->x = 7;
	tail->next->next->prev = tail->next;
	tail->next->next->next = NULL;

	head = tail->next->next;

	curr = tail;
	while (curr != NULL)
	{
		printf("%d\n", curr->x);
		curr = curr->next;
	}

	return (0);
}
