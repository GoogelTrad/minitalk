/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:11:42 by cmichez           #+#    #+#             */
/*   Updated: 2023/02/14 22:51:48 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
    int j;
    
    j = ft_strlen(argv[2]) - 1;
    while (argv[2][j] && argc == 3)
    {
        decal_bit(argv[2][j], ft_atoi(argv[2]));
        j--;
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
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i--;
    }
}