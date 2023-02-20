/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_client_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:28:44 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/20 16:52:08 by cmichez          ###   ########.fr       */
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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_strlen(char *str)
{
	int	i;
	
	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char s2)
{
	char	*result;
	int		len_s1;
	int		n;

	n = 0;
	len_s1 = ft_strlen(s1);
	result = malloc(sizeof(char) * (len_s1 + 1) + 1);
	if (!result)
		return (NULL);
	while (n < len_s1)
	{
		result[n] = s1[n];
		n++;
	}
	result[n++] = s2;
	result[n] = '\0';
	return (result);
}
