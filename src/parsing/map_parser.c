#include "cub3d.h"
#include "err_type.h"

static char	**collect_map(t_config **conf)
{
	int		i;
	int		j;
	char	**map;

	i = (*conf)->map_loc;
	j = 0;
	map = malloc(sizeof(char *) * ((*conf)->map_len + 1));
	if (!map)
		return (NULL);
	while ((*conf)->file[i])
	{
		map[j] = trim_newline((*conf)->file[i], '\n');
		i++;
		j++;
	}
	map[j] = NULL;
	return (map);
}

static bool	scan_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (ft_strchr("1", line[i]))
		return (true);
	return (false);
}

static int	pinpoint_map(t_config **conf)
{
	int	i;

	i = -1;
	(*conf)->map_loc = 0;
	while (++i < (*conf)->file_size)
	{
		if (scan_map((*conf)->file[i]) == true)
			break ;
		(*conf)->map_loc++;
	}
	return (0);
}

int	find_map(t_config **conf)
{
	if (pinpoint_map(conf) == FAILS)
		return (FAILS);
	(*conf)->map_len = map_len(conf);
	(*conf)->map = collect_map(conf);
	if (!(*conf)->map)
		return (ft_putendl_fd(EMPTY_ERR, STDERR_FILENO));
	return (0);
}
