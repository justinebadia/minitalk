/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadia <jbadia@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:29:22 by jbadia            #+#    #+#             */
/*   Updated: 2021/07/27 15:42:25 by jbadia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_handler(int signal)
{
	static int	len = 0;
	static char	c = 0;

	if (signal == SIGUSR1)
		c |= (1 << len);
	len++;
	if (len == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		len = 0;
		c = 0;
	}
}

int	main(void)
{
	int		signo;

	signo = (int)getpid();
	ft_putnbr_fd(signo, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}
