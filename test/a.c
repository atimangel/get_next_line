#include <stdio.h>
#include <stdlib.h>

void	ft_change(char *a)
{
	int i;

	i = -1;
	a = (char *)malloc(10);
	while (++i < 10)
		a[i] = '~';
	a[i] = '\0';
	printf("#2 %s\n", a);
	free(a);
}
int	main(void)
{
	char *a;
	int		i;

	i = -1;
	//a = (char *)malloc(10);
	//while (++i < 10)
	//	a[i] = 'a';
	//a[i] = '\0';
	//printf("#1 %s\n", a);
	//free(a);
	ft_change(a);
	//printf("#2 %s\n", a);
}
