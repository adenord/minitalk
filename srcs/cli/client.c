/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:22:42 by adenord           #+#    #+#             */
/*   Updated: 2023/11/16 19:48:55 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <client.h>

volatile sig_atomic_t	g_received;

void	handle_signal(int signum)
{
	if (signum == SIGUSR1)
		g_received = 1;
}

void	bits_sender(char c, pid_t pid)
{
	int	nbits;
	int	state;

	nbits = 7;
	while (nbits >= 0)
	{
		state = c >> nbits & 1;
		if (state == 0)
			kill(pid, SIGUSR1);
		if (state == 1)
			kill(pid, SIGUSR2);
		nbits--;
		usleep(50);
	}
}

void	iterator(char *str, pid_t pid_srv)
{
	int	i;

	i = -1;
	while (str[++i])
		bits_sender(str[i], pid_srv);
}

int	main(int argc, char **argv)
{
	pid_t	pid_srv;
	char	*cli_pid;

	if (argc != 3)
	{
		ft_printf("Error : Too few arguments\n");
		return (0);
	}
	g_received = 0;
	cli_pid = ft_itoa(getpid());
	pid_srv = ft_atoi(argv[1]);
	iterator(argv[2], pid_srv);
	bits_sender(0, pid_srv);
	iterator(cli_pid, pid_srv);
	bits_sender(0, pid_srv);
	signal(SIGUSR1, handle_signal);
	pause();
	if (g_received == 1)
		ft_printf("Message sent and received !\n");
	return (0);
}
