/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:42:11 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/20 16:22:38 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char *free_buff(char *str, char c)
{
    char    *temp;

    if (c)
    {
        temp = ft_strjoin(str, c);
        free(str);
        return (temp);
    }
    else
    {
        free(str);
        return (NULL);
    }
}

void	print_pid(void)
{
	ft_putstr("Server start !\n");
	ft_putstr("PID : ");
	printf_shell(getpid());
	ft_putstr("\n");
}

void	recu(int s, siginfo_t *action, void *param)
{
	static char *stock;
	static char	res = 0;
	static int	i = 0;

	(void)param;
	res |= s == SIGUSR1;
	i++;
	if (i < 8)
		res <<= 1;
	if (i == 8)
    {
        if (res == '\0')
        {
            ft_putstr(stock);
            ft_putstr("\n");
        }
        stock = free_buff(stock, res);
        i = 0;
        res = 0;
    }
	usleep(200);
	kill(action->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;

	print_pid();
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = recu;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		pause();
	return (0);
}
