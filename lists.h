/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:24:48 by tszymans          #+#    #+#             */
/*   Updated: 2024/08/26 20:49:20 by tszymans         ###   ########.fr       */
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

#endif
