int	isnum(char *c)
{
	if (*c >= '0' && *c <= '9')
		return (1);
	else if (*c == '-')
		if (c[1] >= '0' && c[1] <= '9')
			return (1);
	return (0);
}

int	isope(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (1);
	if (c == '*')
		return (1);
	if (c == '/')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

int	issp(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r')
		return (1);
	return (0);
}
