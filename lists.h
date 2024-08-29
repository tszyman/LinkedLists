/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:24:48 by tszymans          #+#    #+#             */
/*   Updated: 2024/08/29 23:12:23 by tomek            ###   ########.fr       */
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

#endif
