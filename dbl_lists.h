/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lists.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:24:48 by tszymans          #+#    #+#             */
/*   Updated: 2024/09/01 00:18:21 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBL_LISTS_H
# define DBL_LISTS_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				x;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void	deallocate(t_node **tail, t_node **head);
void	insert_beg(t_node **tail, int value);
void	init(t_node **tail, t_node **head, int value);
void	insert_end(t_node **head, int value);
void	insert_after(t_node *node, int value);
void	remove_node(t_node *node);

#endif
