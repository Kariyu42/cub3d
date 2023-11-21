#include "cub3d.h"
#include "err_type.h"

void	examine_path(t_config **conf, char **map, t_pos pos, char *to_fill)
{
	if (pos.y < 0 || pos.x < 0 || pos.y >= (*conf)->map_len + 2 \
		|| !ft_strchr(to_fill, map[pos.y][pos.x]) \
		|| map[pos.y][pos.x] == '1' || (*conf)->anomaly)
		return ;
	if (map[pos.y][pos.x] && map[pos.y][pos.x] == '/')
		(*conf)->anomaly = true;
	map[pos.y][pos.x] = 'X';
	// print_map(map);
	examine_path(conf, map, (t_pos){pos.x - 1, pos.y}, to_fill);
	examine_path(conf, map, (t_pos){pos.x + 1, pos.y}, to_fill);
	examine_path(conf, map, (t_pos){pos.x, pos.y - 1}, to_fill);
	examine_path(conf, map, (t_pos){pos.x, pos.y + 1}, to_fill);
}

t_pos	find_pos(char letter, char **map)
{
	int	i;
	int	j;
	t_pos	pos;

	i = -1;
	pos.x = -1;
	pos.y = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == letter)
			{
				pos.x = j;
				pos.y = i;
				printf("j'ai trouve la POSITION\n");
				return (pos);
			}
		}
	}
	return (pos);
}

bool	flood_fill(t_config **conf, char **tmp)
{
	int		i;
	t_pos	pos;

	i = -1;
	(*conf)->anomaly = false;
	while (tmp[++i])
	{
		while (tmp[i] && ft_strchr(tmp[i], '0'))
		{
			pos = find_pos('0', tmp);
			if (pos.x < 0 || pos.y < 0)
				return (false);
			examine_path(conf, tmp, pos, "0/NWSE");
			// printf("tmp[%.2d]: %s\n", i, tmp[i]);
		}
		if ((*conf)->anomaly == true)
		{
			printf("c'est pas fermé bg\nau revooir\n");
			print_map(tmp);
			return (false);
		}
	}
	printf("c'est bon poto elle est fermé\n");
	print_map(tmp);
	return (true);
}

char	*fill_map(char *map, char *tmp, int line_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * (line_len));
	if (!tmp)
		return (NULL);
	while (i < line_len - 1)
	{
		if (i == 0)
			tmp[i] = '/';
		else if ((map[j] && map[j] == ' ') || !map[j])
			tmp[i] = '/';
		else if (map[j])
			tmp[i] = map[j];
		if (map[j] && i != 0)
			j++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*fill_extremities(char *tmp, int line_len)
{
	int	i;

	i = -1;
	tmp = malloc(sizeof(char) * line_len);
	if (!tmp)
		return (NULL);
	while (++i < line_len - 1)
		tmp[i] = '/';
	tmp[i] = '\0';
	return (tmp);
}
