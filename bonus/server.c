/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:42:11 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/16 21:00:52 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_pid()
{
    ft_putstr("Server start !\n");
    ft_putstr("PID : ");
    printf_shell(getpid());
    ft_putstr("\n");
}

void recu(int s, siginfo_t *action, void *param)
{
    static char res = 0;
    static int i = 0;

    (void)param;
    res |= (s == SIGUSR1);
    i++;
    if (i < 8)
        res <<= 1;
    if(i == 8)
    {
        ft_putchar(res);
        i = 0;
        res = 0;
    }
    kill(action->si_pid, SIGUSR2);
}

int main(void)
{   
    struct sigaction action;

    print_pid();
    action.sa_flags = SA_SIGINFO;
    action.sa_sigaction = recu;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    while (1)
        pause();
    return (0);
}