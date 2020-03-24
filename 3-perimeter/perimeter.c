/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:04:46 by asultanb          #+#    #+#             */
/*   Updated: 2020/02/05 18:01:47 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void print_left(struct s_node *root, int *space)
{
	if (root && (root->left || root->right))
	{
		if (*space > 0)
			printf(" ");
		printf("%d", root->value);
		*space = *space + 1;
		print_left(root->left, space);
	}
}

void print_mid(struct s_node *root, int *space)
{
	if (root)
	{
		print_mid(root->left, space);
		if (!root->left && !root->right)
		{
			if (*space > 0)
				printf(" ");
			printf("%d", root->value);
			*space = *space + 1;
		}
		print_mid(root->right, space);
	}
}

void print_right(struct s_node *root, int *space)
{
	if (root && (root->left || root->right))
	{
		print_right(root->right, space);
		if (*space > 0)
			printf(" ");
		printf("%d", root->value);
		*space = *space + 1;
	}
}

void perimeter(struct s_node *root)
{
	int	space = 0;

	print_left(root, &space);
	print_mid(root, &space);
	print_right(root->right, &space);
	printf("\n");
}


// testing part:

/*
#include <stdlib.h>

struct s_node *init(int value)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int		main()
{
	struct s_node *s1 = init(92);	
	struct s_node *s2 = init(85);	

	struct s_node *s8 = init(26);	
	struct s_node *s3 = init(79);	
	struct s_node *s4 = init(10);
	struct s_node *s5 = init(39);
	struct s_node *s6 = init(35);
	struct s_node *s7 = init(96);

	struct s_node *s9 = init(64);	
	struct s_node *s10 = init(40);	

	struct s_node *s11 = init(88);	
	struct s_node *s12 = init(12);	
	struct s_node *s13 = init(58);	
	struct s_node *s14 = init(55);	
	struct s_node *s15 = init(58);	
	struct s_node *s16 = init(41);	

	struct s_node *s17 = init(10);	
	struct s_node *s18 = init(52);	
	struct s_node *s19 = init(22);	
	struct s_node *s20 = init(35);	
	struct s_node *s21 = init(87);	
	struct s_node *s22 = init(31);	

	struct s_node *s23 = init(78);	
	struct s_node *s24 = init(2);	
	struct s_node *s25 = init(33);	
	struct s_node *s26 = init(55);	
	struct s_node *s27 = init(11);	
	struct s_node *s28 = init(99);	
	struct s_node *s29 = init(85);	
	struct s_node *s30 = init(51);	

	s1->left = s2;
	s1->right = s8;
	s2->left = s3;
	s3->right = s4;
	s4->left = s5;
	s5->left = s6;
	s6->left = s7;

	s8->right = s9;

	s9->left = s10;
	s10->left = s11;
	s11->left = s12;
	s11->right = s14;
	s12->left = s13;
	s14->left = s15;
	s14->right = s16;

	s10->right = s17;
	s17->left = s18;
	s18->left = s19;
	s18->right = s20;
	s17->right = s21;
	s21->right = s22;

	s9->right = s23;
	s23->left = s24;
	s23->right = s29;
	s29->right = s30;
	s24->left = s25;
	s25->right = s26;
	s24->right = s27;
	s27->left = s28;
	perimeter(s1);
}
*/
