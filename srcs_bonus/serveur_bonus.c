/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:29:34 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/27 15:04:53 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	ft_handler(int signal, siginfo_t *info, void *ucontext)
{
	static int	len = 0;
	static char	c = 0;
	int			ret;

	(void)ucontext;
	(void)info;
	if (signal == SIGUSR1)
		c |= (1 << len);
	len++;
	if (len == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
		{
			write(1, "\nEND OF MESSAGE\n", 17);
			ret = kill(info->si_pid, SIGUSR1);
			if (ret == -1)
				error_msg("error kill return");
		}
		len = 0;
		c = 0;
	}
}

int	main(void)
{
	int					signo;
	struct sigaction	s;
	int					ret;

	signo = (int)getpid();
	ft_putnbr_fd(signo, 1);
	write(1, "\n", 1);
	s.sa_sigaction = ft_handler;
	s.sa_flags = SA_SIGINFO;
	ret = sigaction(SIGUSR1, &s, NULL);
	if (ret == -1)
		error_msg("Sigaction error");
	ret = sigaction(SIGUSR2, &s, NULL);
	if (ret == -1)
		error_msg("Sigaction error");
	while (1)
		pause();
	return (0);
}
