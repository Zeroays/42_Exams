/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 09:09:10 by exam              #+#    #+#             */
/*   Updated: 2019/07/16 19:11:16 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int main(int ac, char *av[])
{
	int i = 0;

	if (ac == 2)
	{
		while (i < ft_strlen(av[1]))
		{
			if (av[1][i] >= 'a' && av[1][i] <= 'z') {
				av[1][i] = ('a' + 'z') - av[1][i];
			}
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z') {
				av[1][i] = ('A' + 'Z') - av[1][i];
			}
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
