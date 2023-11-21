#include "cub3d.h"
#include "err_type.h"

char	**map_dup(t_config **conf, char **map)
{
	char	**tmp;
	int		len;
	int		i;
	int		j;

	i = -1;
	j = 0;
	tmp = ft_calloc(sizeof(char *), (*conf)->map_len + 3);
	if (!tmp)
		return (NULL);
	len = longest_line((*conf)->map) + 3;
	while (++i < (*conf)->map_len + 2)
	{
		if (i == 0 || i == (*conf)->map_len + 1)
			tmp[i] = fill_extremities(tmp[i], len);
		else if (map[j])
		{
			tmp[i] = fill_map(map[j], tmp[i], len);
			j++;
		}
	}
	tmp[i] = NULL;
	return (tmp);
}

int	inspect_map(t_config **conf)
{
	int		i;
	char	**tmp;

	i = -1;
	(*conf)->player = 0;
	while ((*conf)->map[++i])
	{
		if (inspect_line(conf, (*conf)->map[i], "10 NWES") == false)
			return (ft_putendl_fd(CHAR_ERR, STDERR_FILENO));
		else if ((*conf)->player > 1)
			return (ft_putendl_fd(PLAYER_ERR, STDERR_FILENO));
	}
	tmp = map_dup(conf, (*conf)->map);
	if (!tmp)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO));
	if (flood_fill(conf, tmp) == false)
		return (FAILS);
	return (0);
}

int	collect_data(t_config **conf, char **av, int fd)
{
	int	i;

	i = -1;
	(*conf)->file_size = text_size(av, fd);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd(OPEN_ERR, STDERR_FILENO));
	(*conf)->file = malloc(sizeof(char *) * ((*conf)->file_size + 1));
	if (!(*conf)->file)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO));
	while (++i < (*conf)->file_size)
		(*conf)->file[i] = get_next_line(fd);
	(*conf)->file[i] = NULL;
	return (0);
}

static int	check_extension(char *str)
{
	int	len;
	int	fd;

	len = ft_strlen(str);
	fd = open(str, O_DIRECTORY);
	if (fd >= 0)
	{
		if (close(fd) == -1)
			return (ft_putendl_fd(CLOSE_ERR, STDERR_FILENO));
		return (ft_putendl_fd(DIR_ERR, STDERR_FILENO));
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd(OPEN_ERR, STDERR_FILENO));
	if ((str[len - 4] == '.' && str[len - 3] == 'c'
		&& str[len - 2] == 'u' && str[len - 1] == 'b'))
		return (0);
	if (close(fd) == -1)
		return (ft_putendl_fd(CLOSE_ERR, STDERR_FILENO));
	return (FAILS);
}

int	parse_data(t_config **conf, char **av)
{
	int	fd;

	fd = 0;
	*conf = malloc(sizeof(t_config));
	if (!conf)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO));
	if (check_extension(av[1]) == FAILS)
		return (FAILS);
	else if (collect_data(conf, av, fd) == -1 || find_map(conf) == -1)
		return (FAILS);
	else if (inspect_map(conf) == -1)
		return (FAILS);
	else if (check_data(conf) == 2)
		return (2);
	// print_map(conf);
	// if (map_data(conf, av) == FAILS)
		// return (-1);
	return (0);
}
