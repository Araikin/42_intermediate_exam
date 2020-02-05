/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 09:15:53 by exam              #+#    #+#             */
/*   Updated: 2020/02/04 09:35:30 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	count_alpha(char *s)
{
	int	hash[26] = {0};	
	int	first = 1;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			hash[s[i] - 'a']++;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			hash[s[i] - 'A']++;
	}
	for (int i = 0; s[i]; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z' && hash[s[i] - 'a'] > 0)
		{
			!first ? printf(", ") : 0;
			printf("%d%c", hash[s[i] - 'a'], s[i]);
			hash[s[i] - 'a'] = 0;
			first = 0;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z' && hash[s[i] - 'A'] > 0)
		{
			!first ? printf(", ") : 0;
			printf("%d%c", hash[s[i] - 'A'], s[i] + 32);
			hash[s[i] - 'A'] = 0;
			first = 0;
		}
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		count_alpha(av[1]);
	printf("\n");
	return (0);
}
