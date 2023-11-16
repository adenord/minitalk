/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:32:36 by adenord           #+#    #+#             */
/*   Updated: 2023/11/16 17:38:41 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>
#include <libft.h>

volatile sig_atomic_t	g_state;

void	handle_signal(int signum)
{
	if (signum == SIGUSR1)
		g_state = 0;
	if (signum == SIGUSR2)
		g_state = 1;
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
}

int	constructor(void)
{
	int	recon;
	int	i;

	recon = 0;
	i = 8;
	while (--i >= 0)
	{
		pause();
		recon |= (g_state << i);
	}
	return (recon);
}

int	pid_constructor(void)
{
	int		recon;
	int		pid_cli;

	pid_cli = 0;
	recon = -1;
	while (recon != 0)
	{
		recon = constructor();
		if (recon > 0)
		{
			pid_cli += (recon - '0');
			pid_cli *= 10;
		}
	}
	pid_cli /= 10;
	return (pid_cli);
}

int	main(void)
{
	pid_t	pid_cli;
	int		recon;

	pid_cli = 0;
	ft_printf("Server up, PID -> %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		recon = -1;
		while (recon != 0)
		{
			recon = constructor();
			write(1, &recon, 1);
		}
		pid_cli = pid_constructor();
		usleep(100);
		kill(pid_cli, SIGUSR1);
	}
	return (0);
}
