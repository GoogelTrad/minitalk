/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:28:44 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/13 16:33:57 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	printf_shell_mv(int compteur)
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
			printf_shell_mv(compteur / 10);
			printf_shell_mv(compteur % 10);
		}
		else
			ft_putchar(compteur + '0');
	}
}

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}