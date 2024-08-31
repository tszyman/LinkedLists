/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:24:48 by tszymans          #+#    #+#             */
/*   Updated: 2024/08/31 14:59:37 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				x;
	struct s_node	*next;
}	t_node;

void	insert_end(t_node **root, int value);
void	deallocate(t_node **root);
void	insert_beg(t_node **root, int value);
void	insert_after(t_node *node, int value);
void	insert_sorted(t_node **root, int value);
void	remove_element(t_node **root, int value);
void	reverse_list(t_node **root);
int		has_loops(t_node *root);

#endif
