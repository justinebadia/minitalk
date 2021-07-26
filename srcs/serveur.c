#include "utils.h"

void	ft_handler(int signal)
{
	static int	len = 0;
	static	int	i = 0;
	char		c;

	if (signal == SIGUSR1)
		i |= (1 << len++); // j'affecte 1 au bit du rang len
	if (signal == SIGUSR2)
		i |= (0 << len++); // j'affecte un 0 au bit du rang len
	if (len == 8)
	{
		c = (char)i;
		if (c == '\0')
			write(1, "\n", 1);
		write(1, &c, 1);
		len = 0;
		i = 0;
	}
}

int main (void)
{
	int		signo;
	
	signo = (int)getpid();
	ft_putnbr_fd(signo, 1);
	write(1, "\n", 1);
    signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
   while (1) // on boucle en attendant la réception d'un signal
	   pause();
	return (0);
}

/*si une fonction est associée à un signal, elle est exécutée lorsque le système constate l'arrivée du dit signal.*/