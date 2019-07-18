/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 09:17:44 by exam              #+#    #+#             */
/*   Updated: 2019/07/16 09:51:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int ft_isspace(char c)
{
	return (c == ' ' || c == '\v' || c == '\t');
}

void rstr_capitalizer(char *str)
{
	int i = 0;
	
	while (str[i])
	{
		if (ft_isalpha(str[i]) && ((ft_isspace(str[i + 1]) && str[i + 1]) || !str[i + 1])) {
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 'a' + 'A';
		}
		else if (ft_isalpha(str[i]) && !ft_isspace(str[i + 1]) && str[i + 1]) {
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] - 'A' + 'a';
		}
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char *av[])
{
	int i = 1;

	if (ac >= 2)
	{
		while (av[i])
		{
			rstr_capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}
