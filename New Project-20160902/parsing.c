#include "filler.h"

t_bool		parse_table_line(t_tab *piece, int line, t_bool isX)
{
	int		i;
	char	c;

	if (!(piece.data[line] = malloc(piece.width)))
		return (false);
	if (!ft_readtochar(' '))
		return (false);
	i = 0;
	while (i < piece.width)
	{
		c = ft_readchar();
		if (c == '.')
			piece.data[line][i] = s_none;
		else if (c == 'O' || c == 'o')
			piece.data[line][i] = s_friendly ;
		else if (c == 'X' || c == 'x')
			piece.data[line][i] = s_enemy ;
		else
			return (false);
	}
	if (ft_readchar() != '\n')
		return (false);
	return (true);
}

t_bool		parse_piece_line(t_tab *piece, int line)
{
	int		i;
	char	c;

	if (!(piece.data[line] = malloc(piece.width)))
		return (false);
	i = 0;
	while (i < piece.width)
	{
		c = ft_readchar();
		if (c == '.')
			piece.data[line][i] = s_none;
		else if (c == '*')
			piece.data[line][i] = s_friendly;
		else
			return (false);
	}
	if (ft_readchar() != '\n')
		return (false);
	return (true);
}

t_bool		parse_header(t_tab *tab)
{
	if (!ft_readtochar(' '))
		return (false);
	if (!ft_readint(&(tab->width)))
		return (false);
	if (!ft_readtochar(' '))
		return (false);
	if (!ft_readint(&(tab->height)))
		return (false);
	if (tab->width <= 0 && tab->height <= 0)
		return (false);
	if (!ft_readtochar('\n'))
		return (false);
	tab->data = (t_pawn**)malloc(table->height * sizeof(t_pawn*));
	if (tab->data == NULL)
		return (false);
	return (true);
}

t_bool		parse_tables(t_tab *table, t_tab* piece, t_bool isX)
{
	int		i;
	
	if (!parse_header(table))
		return (false);
	if (!ft_readtochar('\n'))
		return (false);
	i = -1;
	while (++i < table.height)
		if (!parse_table_line(table, i, isX))
			return (false);
	if (!parse_header(piece))
		return (false);
	i = -1;
	while (++i < piece.height)
		if (!parse_piece_line(piece, i))
			return (false);
	return (true);
}

t_bool		parse_intro(t_bool *isX)
{
	int		player;

	if (!ft_readtochar('p'))
		return (false);
	if (!ft_readint(&player))
		return (false);
	if (!ft_readtochar('\n'))
		return (false);
	if (player != 0 && player != 1)
		return (false);
	*isX = (player == 1);
	return (true);
}