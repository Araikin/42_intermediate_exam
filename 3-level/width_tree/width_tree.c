/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 09:54:31 by exam              #+#    #+#             */
/*   Updated: 2020/02/04 10:57:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	max_wid(struct s_node *n, int *maxwid)
{
	int	curwid;
	int	leftwid;
	int	rightwid;

	if (!n) return 0;
	leftwid = max_wid(n->left, maxwid);
	rightwid = max_wid(n->right, maxwid);
	curwid = 1 + leftwid + rightwid;	
	*maxwid = curwid > *maxwid ? curwid : *maxwid;
	return (leftwid > rightwid ? leftwid + 1 : rightwid + 1);
}

int	width_tree(struct s_node *n)
{
	int	maxwid = 0;		
	max_wid(n, &maxwid);
	return (maxwid);
}
