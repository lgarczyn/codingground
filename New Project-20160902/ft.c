#include "filler.h"

#define READ_BUFFER 1024

char			ft_getchar_int(t_bool move)
{
	static char	buffer[1024];
	static int	pos;
	static int	len;
	char		c;
	
	if (pos >= len)
	{
		pos = 0;
		len = read(0, buffer, 1024);
		if (len < 0)
			return ('\0');
	}
	c = buffer[pos];
	if (move)
		pos++;
	return (c);	
}

char			ft_getchar()
{
	ft_getchar_int(false);
}

char	    	ft_readchar()
{
	ft_getchar_int(true);
}

t_bool	    	ft_readtochar(char c)
{
	while(ft_getchar() != c)
		if (ft_getchar() == '\0')
			return (false);
		else
			ft_readchar();
	ft_readchar();
	return (true);
}

t_bool	    	ft_readint(int *target)
{
	char	c;
	
	c = ft_getchar();
	if (c < '0' || c > '9')
		return (false);
	target = c - '0';
	ft_readchar();
	while (ft_getchar() >= '0' || ft_getchar() <= '9')
	{
		target = target * 10 + ft_getchar() - '0';
		ft_readchar();
	}
	return (true);
}