#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	t;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	t = 0;
	while (str[t] == ' ' || (str[t] >= 9 && str[t] <= 13))
		t++;
	if (str[t] == '-' || str[t] == '+')
	{
		if (str[t] == '-')
			sign *= -1;
		t++;
	}
	while (str[t] >= '0' && str[t] <= '9')
	{
		result *= 10;
		result += str[t] - '0';
		t++;
	}
	return (result * sign);
}

void ft_signal(int pid, char c)
{
	int i;
	
	i = 0;
	while (i < 8)
	{
		if((c >> i) & 1)
			kill(pid , SIGUSR1);
		else
			kill(pid , SIGUSR2);
		usleep(100);
		i++;
	}
	
}

int main(int ac,char **argv)
{
if (ac == 3)
{
	int pid;
	char *str;
	int i = 0;
	pid = ft_atoi(argv[1]);
	str =argv[2];
	while (str[i])
	{
		ft_signal(pid,str[i]);
		i++;
	}
	
}
else
{
	ft_printf("error");
	return (0);
}
return (0);
}