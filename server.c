#include "minitalk.h"


void sig_handler(int sig)
{
	static int character;
	static int i;
	
	if(sig == SIGUSR1)
		character |= (1 << i);
	i++;
	if(i == 8)
	{
		ft_printf("%c",character);
		character = 0;
		i = 0;
	}
}

int main()
{
	int pid;

	pid = getpid();
	ft_printf("pid :%d\n",pid);
	signal(SIGUSR1,sig_handler);
	signal(SIGUSR2,sig_handler);
	while (1);
	return (0);
}