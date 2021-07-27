/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:28:48 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/27 15:01:16 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	send_signal(int pid, int c)
{
	int	j;
	int	ret;

	j = 0;
	while (j < 8)
	{
		usleep(75);
		if (c & (1 << j))
			ret = kill (pid, SIGUSR1);
		else
			ret = kill (pid, SIGUSR2);
		if (ret == -1)
			error_msg("wrong PID");
		j++;
	}
}

void 	received_msg(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)info;
	(void)ucontext;
	ft_putstr_fd("SIGNAL RECEIVED FROM SERVOR, CLOSE CLIENT", 1);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char**argv)
{
	int					pid;
	int					i;
	struct sigaction	s;

	i = 0;
	if (argc != 3)
		error_msg("wrong args");
	pid = ft_atoi(argv[1]);
	s.sa_sigaction = received_msg;
	s.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s, NULL);
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	send_signal(pid, argv[2][i]);
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
