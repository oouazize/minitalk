/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:17:30 by oouazize          #+#    #+#             */
/*   Updated: 2021/12/19 11:48:25 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_pid(char *pid)
{
	int	i;
	int	pid_n;

	i = 0;
	while (i < (int)ft_strlen(pid))
	{
		if (!ft_isdigit(pid[i]))
		{
			ft_putstr_fd("not valid pid", 1);
			exit (0);
		}
		i++;
	}
	pid_n = ft_atoi(pid);
	if (pid_n <= 0 || pid_n >= 99999 || i > 10)
	{
		ft_putstr_fd("not valid pid", 1);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_putstr_fd("you need to enter PID and string", 1);
		exit (0);
	}
	check_pid(argv[1]);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (i < (int)ft_strlen(argv[2]) + 1)
	{
		argc = 128;
		while (argc != 0)
		{
			usleep(15);
			if (argc & argv[2][i])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			argc = argc >> 1;
		}
		i++;
	}
}
