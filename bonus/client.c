/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:11:42 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/16 21:00:36 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int verif_pid(int pid)
{
    int i;

    i = 8;
    if (pid < 0)
        return (0);
    while (i--)
    {
        if (kill(pid, SIGUSR1 == -1))
        {
            ft_putstr("Invalid PID\n");
            return (0);
        }
    }
    return (1);
}

int main(int argc, char **argv)
{
    int j;
    
    j = 0;
    if (argc != 3)
        ft_putstr("Arguments invalide : ./client pid message\n");
    if (!(verif_pid(ft_atoi(argv[1]))))
        return (1);
    while (argv[2][j])
    {
        decal_bit(argv[2][j], ft_atoi(argv[1]));
        j++;
    }
    return (0);
}

void decal_bit(char c, int pid)
{
    int i;
    
    i = 8;
    while (i)
    {
        if ((c >> (i - 1)) & 1)
        {
            kill(pid, SIGUSR1);
        }
        else
        {
            kill(pid, SIGUSR2);
        }
        i--;
        pause();
        usleep(200);
    }
}

void receive(int s)
{
    static char res = 0;
    static int i = 0;

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
}