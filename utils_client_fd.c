/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:28:44 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/14 15:19:35 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	printf_shell(int compteur)
{
	if (compteur == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (compteur < 0)
		{
			ft_putchar('-');
			compteur *= -1;
		}
		if (compteur >= 10)
		{
			printf_shell(compteur / 10);
			printf_shell(compteur % 10);
		}
		else
			ft_putchar(compteur + '0');
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}