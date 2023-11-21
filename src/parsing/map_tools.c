#include "cub3d.h"
#include "err_type.h"

// /* Print_map to be removed */
void	print_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		// printf("map[%.2d]: %s\naddress: %p\n", i, map[i], &map[i]);
		printf("map[%.2d]: %s\n", i, map[i]);
		i++;
	}
	printf("map[%d]: %s\n", i, map[i]);
	return ;
}

bool	inspect_line(t_config **conf, char *map_line, char *to_find)
{
	int	i;

	i = -1;
	while (map_line[++i])
	{
		if (!ft_strchr(to_find, map_line[i]))
			return (false);
		else if (ft_strchr("NWES", map_line[i]))
			(*conf)->player++;
	}
	return (true);
}

int	longest_line(char **map)
{
	int	i;
	int	len;
	int	res;

	i = -1;
	res = 0;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if (res < len)
			res = len;
	}
	return (res);
}

char	*trim_newline(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	str[i] = '\0';
	return (str);
}

int	text_size(char **av, int fd)
{
	int	len;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd(OPEN_ERR, STDERR_FILENO));
	len = 0;
	while (get_next_line(fd))
		len++;
	if (close(fd) == -1)
		return (ft_putendl_fd(CLOSE_ERR, STDERR_FILENO));
	return (len);
}

int	map_len(t_config **conf)
{
	int	i;
	int	res;

	res = 0;
	i = (*conf)->map_loc;
	while ((*conf)->file[i])
	{
		res++;
		i++;
	}
	return (res);
}
