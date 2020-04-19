#include <stdlib.h>

int	first(int *ope, int o)
{
	int i;

	i = 0;
	while (ope[i] < 2 && i < o)
		i++;
	if (i < o)
		return (i);
	else
		return (0);
}

int	cal(int num1, int num2, int ope1)
{
	if (ope1 == 0)
		return (num1 + num2);
	if (ope1 == 1)
		return (num1 - num2);
	if (ope1 == 2)
		return (num1 * num2);
	if (ope1 == 3)
		return (num1 / num2);
	return ((int)((int)num1 % (int)num2));
}

int	*update_ope(int *ope, int o, int i)
{
	int *ans;
	int j;

	if (o > 0)
	{
		ans = (int*)malloc((o - 1) * sizeof(int));
		j = -1;
		while (++j < i)
			ans[j] = ope[j];
		j = i - 1;
		while (++j < o - 1)
			ans[j] = ope[j + 1];
		return (ans);
	}
	return (ope);
}

int	*update_num(int *num, int n, int i, int cal1)
{
	int	*ans;
	int	j;

	ans = (int*)malloc((n - 1) * sizeof(int));
	j = -1;
	while (++j < i)
		ans[j] = num[j];
	ans[i] = cal1;
	j = i;
	while (++j < n - 1)
		ans[j] = num[j + 1];
	return (ans);
}

int	calc(int *num, int *ope, int *n, int *o)
{
	int	i;
	int	num1;
	int	num2;
	int	ope1;

	while (*n > 1)
	{
		i = first(ope, *o);
		ope1 = ope[i];
		num1 = num[i];
		num2 = num[i + 1];
		ope = update_ope(ope, *o, i);
		num = update_num(num, *n, i, cal(num1, num2, ope1));
		(*n)--;
		(*o)--;
	}
	return (num[0]);
}
