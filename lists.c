/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:22:09 by tszymans          #+#    #+#             */
/*   Updated: 2024/08/26 20:35:43 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

int	main(int argc, char **argv)
{
	t_node	root;
	t_node	elem2;

	root.x = 15;
	root.next = malloc(sizeof(t_node));
	root.next->x = 29;
	root.next->next = NULL;

	printf("First element: %d\n", root.x);
	printf("Second element: %d\n", root.next->x);

	free(root.next);
	return (0);
}
