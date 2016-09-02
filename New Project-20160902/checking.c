#include "filler.h"

int			check_pos(t_tab table, t_tab piece, t_p move, t_p pos)
{
	if (piece.data[pos.y][pos.x])
	{
		if (move.x + pos.x < 0 && move.x + pos.x >= table.width)
			return (-1);
		if (move.y + pos.y < 0 && move.y + pos.y >= table.height)
			return (-1);
		pawn = table.data[move.y + pos.y][move.x + pos.x];
		if (pawn & s_enemy)
			return (-1);
		if (pawn & s_friendly)
			return (1);
	}
	return (0);
}

t_bool		is_legal(t_tab table, t_tab piece, t_p move)
{
	t_pos	pos;
	t_bool	overlap;
	t_pawn	pawn;
	int		ret;

	overlap = false;
	pos.y = -1;
	while (pos.y < piece.height)
	{
		pos.x = -1;
		while (pos.x < piece.width)
		{
			ret = check_pos(table, piece, move, pos);
			if (ret < 0)
				return (false);
			else if (ret > 0 && overlap)
				return (false);
			else if (ret > 0)
				overlap = true;
			pos.x++;
		}
		pos.y++;
	}
	return (overlap);
}