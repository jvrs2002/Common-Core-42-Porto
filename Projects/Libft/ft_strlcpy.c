int	ft_strlcpy(char *ostr, char *nstr, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		nstr[i] = ostr[i];
		i++;
	}
	nstr[i] = '\0';
	return i;
}