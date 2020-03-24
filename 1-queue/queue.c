/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:07:36 by asultanb          #+#    #+#             */
/*   Updated: 2020/02/05 16:46:01 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void 			*content;
	struct s_node	*next;
};

struct s_queue {
	struct s_node	*first;
	struct s_node	*last;
};

struct s_queue *init(void)
{
	struct s_queue	*queue;

	if (!(queue = malloc(sizeof(struct s_queue))))
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *tmp = NULL;
	if (!queue)	return;
	if (!(tmp = malloc(sizeof(struct s_node))))
		return;
	tmp->content = content;
	tmp->next = NULL;
	if (!queue->first)
		queue->first = tmp;
	else
		queue->last->next = tmp;
	queue->last = tmp;
}

void *dequeue(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (NULL);
	struct s_node *tmp = queue->first;
	void	*content = tmp->content;
	queue->first = tmp->next;
	if (tmp == queue->last)
		queue->last = NULL;
	free(tmp);
	return (content);
}

void *peek(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return	(NULL);
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return (1);
	return (0);
}


// testing part below. comment before push

/*
#include <stdio.h>

struct s_node *init_node(void *content)
{
	struct s_node *node = NULL;
	if (!(node = malloc(sizeof(struct s_node))))
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int		main()
{
	char a[] = "aa";
	char b[] = "bb";
	char c[] = "cc";
	char d[] = "dd";

	struct s_queue	*queue = init();	
	printf("is empty: %d\n", isEmpty(queue));
	printf("peek: %s\n", (char *)peek(queue));
	enqueue(queue, (void*)a);
	enqueue(queue, (void*)b);
	enqueue(queue, (void*)c);
	enqueue(queue, (void*)d);
	printf("peek: %s\n", (char *)peek(queue));
	printf("dequeue: %s\n", (char *)dequeue(queue));
	printf("peek: %s\n", (char *)peek(queue));
	printf("dequeue: %s\n", (char *)dequeue(queue));
	printf("peek: %s\n", (char *)peek(queue));
	printf("dequeue: %s\n", (char *)dequeue(queue));
	printf("peek: %s\n", (char *)peek(queue));
	printf("dequeue: %s\n", (char *)dequeue(queue));
	printf("peek: %s\n", (char *)peek(queue));
	printf("dequeue: %s\n", (char *)dequeue(queue));
	printf("peek: %s\n", (char *)peek(queue));
}
*/
