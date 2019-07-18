/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 09:55:21 by exam              #+#    #+#             */
/*   Updated: 2019/07/16 19:38:12 by vrabaib          ###   ########.fr       */
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

int ft_isspace(char c)
{
	return (c == ' ' || c == '\v' || c == '\t');
}

void write_word(char *str, int i)
{
	while (str[i] && !ft_isspace(str[i]))
	{
		write(1, &str[i], 1);
		i++;
	}
}

void rev_wstr(char *str)
{
	int i = 0;
	int stop = ft_strlen(str) - 1;

	while (str[stop])
	{
		if (ft_isspace(str[stop]))
		{
			i = stop + 1;
			write_word(str, i);
			write(1, " ", 1);
		}
		else if (!str[stop - 1])
		{
			i = stop;
			write_word(str, i);
		}
		stop--;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
		rev_wstr(av[1]);
	write(1, "\n", 1);
}
