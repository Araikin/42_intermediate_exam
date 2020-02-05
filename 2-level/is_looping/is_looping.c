/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 09:40:56 by exam              #+#    #+#             */
/*   Updated: 2020/02/04 09:51:57 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int value;
	struct s_node *next;
};

int		is_looping(struct s_node *node)
{
	struct s_node *slow = node, *fast = node;
	if (!node || !node->next)
		return (0);
	while (slow && fast && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
