#include "ft.h"

int	*push_back1(int *num, int *n, int add)
{
	int	*ans;
	int	i;

	ans = (int*)malloc((*n + 1) * sizeof(int));
	i = 0;
	while (i < *n)
	{
		ans[i] = num[i];
		i++;
	}
	ans[*n] = add;
	(*n)++;
	return (ans);
}

int	*push_back2(int *ope, int *o, char **str)
{
	int	*ans;
	int	i;

	ans = (int*)malloc((*o + 1) * sizeof(int));
	i = 0;
	while (i < *o)
	{
		ans[i] = ope[i];
		i++;
	}
	if (**str == '+')
		ans[*o] = 0;
	else if (**str == '-')
		ans[*o] = 1;
	else if (**str == '*')
		ans[*o] = 2;
	else if (**str == '/')
		ans[*o] = 3;
	else if (**str == '%')
		ans[*o] = 4;
	(*o)++;
	(*str)++;
	return (ans);
}

int	loop(char **str)
{
	int	*num;
	int	*ope;
	int	n;
	int	o;

	n = 0;
	o = 0;
	while ((**str != 0) && (**str) != ')')
	{
		if (issp(**str))
			(*str)++;
		else if (isnum(*str))
			num = push_back1(num, &n, (int)atoip(str));
		else if (isope(**str))
			ope = push_back2(ope, &o, str);
		else if (**str == '(')
		{
			(*str)++;
			num = push_back1(num, &n, loop(str));
		}
	}
	(*str)++;
	return (calc(num, ope, &n, &o));
}

int	eval_expr(char *str)
{
	return (loop(&str));
}
