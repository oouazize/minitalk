/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouazize <oouazize@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:17:38 by oouazize          #+#    #+#             */
/*   Updated: 2021/12/19 17:05:33 by oouazize         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handl_sig(int sig)
{
	static int	chr;
	static int	count = 7;
	static int	i;
	static char	ary[1000000];

	if (sig == SIGUSR1)
		chr = chr | (1 << count);
	count--;
	if (count == -1)
	{
		count = 7;
		ary[i] = chr;
		i++;
		if (chr == '\0')
		{
			write(1, ary, ft_strlen(ary));
			i = 0;
		}
		chr = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("this is PID of server : ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handl_sig);
	signal(SIGUSR2, handl_sig);
	while (1)
		pause();
	return (0);
}
