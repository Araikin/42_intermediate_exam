/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:47:16 by asultanb          #+#    #+#             */
/*   Updated: 2020/02/05 16:55:11 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node)
{
	if (!node || !node->next)
		return (0);
	struct s_node *slow = node, *fast = node;
	while (slow && fast && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}

// testing part. comment or delete before push

/*
#include <stdlib.h>
#include <stdio.h>

int	main()
{
	struct s_node *s1, *s2, *s3, *s4, *s5, *s6;	
	s1 = malloc(sizeof(struct s_node));
	s2 = malloc(sizeof(struct s_node));
	s3 = malloc(sizeof(struct s_node));
	s4 = malloc(sizeof(struct s_node));
	s5 = malloc(sizeof(struct s_node));
	s6 = malloc(sizeof(struct s_node));

	s1->next = s2;
	s2->next = s3;
	s3->next = s4;
	s4->next = s5;
	s5->next = s6;
	s6->next = NULL;
	
	printf("is looping: %d\n", is_looping(s1));
	return 0;
}
*/
