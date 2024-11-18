ft_putstr_fd(char *str,int fd,int *counter)
{
    	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
    (*counter)+=i;
}