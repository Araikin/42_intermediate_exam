/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:58:58 by exam              #+#    #+#             */
/*   Updated: 2020/02/04 11:08:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	struct s_node *a, *b;

	for (a = lst1; a; (a = a->next))
		for (b = lst2; b; (b = b->next))
			if (a == b)
				return (a);
	return (NULL);
}
