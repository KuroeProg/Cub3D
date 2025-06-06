#include <stdio.h>

int	ft_hexconvert(char *nptr)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (i < 6)
	{
		if (nptr[i] <= '9' && nptr[i] >= '0')
			nb = nb * 16 + nptr[i] - 48;
		else if (nptr[i] <= 'F' && nptr[i] >= 'A')
			nb = nb * 16 + nptr[i] - 65 + 10;
		i++;
	}
	return (nb);
}

int main()
{
	char color[6] = "473B78";
	printf("%d\n",ft_hexconvert(color));
}
