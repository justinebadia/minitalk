#include "utils_bonus.h"

void	ft_handler(int signal)
{
	static int	len = 0;
	static	char c = 0;

	if (signal == SIGUSR1)
		c |= (1 << len); // j'affecte 1 au bit du rang len
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

int main (void)
{
	int		signo;
	struct sigaction s;
	
	signo = (int)getpid();
	ft_putnbr_fd(signo, 1);
	write(1, "\n", 1);
	s.sa_sigaction = ft_handler;
	s.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
   while (1) // on boucle en attendant la réception d'un signal
	   pause();
	return (0);
}
