/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:59:26 by asultanb          #+#    #+#             */
/*   Updated: 2020/02/05 16:06:09 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	equation(int n)
{
	for (int a = 0, b = n; a <= n; a++, b--)
		if (a < 100 && b < 100 && a / 10 == b % 10)
			printf("A = %d, B = %d, C = %d\n", a / 10, a % 10, b / 10);
}

// comment before push. testing below
/*
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 2)
		equation(atoi(av[1]));
	return (0);
}
*/
