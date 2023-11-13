#include "cub3d.h"
#include "err_type.h"

// char	*map_info(char **av, char *pos)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(av[1], O_RDONLY);
// 	if (fd < 0)
// 		return (NULL);
// 	while ()
// 	{
// 		line = get_next_line(fd);
// 		if (line)
// 	}
// }

// int	map_data(t_config *conf, char **av)
// {
// 	// // collection of map textures;
// 	// conf->data[0] = map_info(av, "NO");
// 	// conf->data[1] = map_info(av, "SO");
// 	// conf->data[2] = map_info(av, "WE");
// 	// conf->data[3] = map_info(av, "EA");

// 	// //collection of map color: floor, ceiling;
// 	// conf->data[4] = map_color("F");
// 	// conf->data[5] = map_color("C");
// 	// // fd = open(av[1], O_RDONLY);
// 	// // if (fd == -1)
// 	// // 	return (-1);
// 	// // while (1)
// 	// // {
// 	// // 	line = get_next_line(fd);

// 	// // }
// 	// // close(fd);
// 	return (0);
// }

char	**collect_map(t_config **conf, int fd, char *line)
{
	int		i;
	char	**map;

	i = 0;
	printf("len_map: %d\n", (*conf)->map_len);
	map = malloc(sizeof(char *) * ((*conf)->map_len + 1));
	if (!*map || !map)
		return (NULL);
	while (line != NULL && i <= (*conf)->map_len)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

/*
MAP: "10NWES " and space
*/
bool	scan_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (ft_strchr("1", line[i]))
		return (true);
	return (false);
}

int	map_len(t_config **conf, char **av)
{
	int	fd;
	int	i;
	int	res;
	char	*line;

	i = -1;
	res = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (2);
	while (++i <= (*conf)->map_loc)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	while (line)
	{
		printf("res: %d\n", res);
		res++;
		line = get_next_line(fd);
		printf("%s", line);
	}
	if (close(fd) == -1)
		return (2);
	return (res);
}

int	find_map(char **av, t_config **conf)
{
	int		fd;
	char	*line;

	(*conf)->map_loc = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("failed to open", STDERR_FILENO));
	while (true)
	{
		line = get_next_line(fd);
		if (scan_map(line) == true)
			break ;
		(*conf)->map_loc++;
	}
	printf("map_loc: %d\n", (*conf)->map_loc++);
	(*conf)->map_len = map_len(conf, av);
	(*conf)->map = collect_map(conf, fd, line);   // stock all map
	close(fd);
	return (0);
}

void	print_map(t_config **conf)
{
	int	i;

	i = 0;
	while ((*conf)->map[i])
	{
		printf("%s", (*conf)->map[i]);
		i++;
	}
}


int	parse_data(t_config **conf, char **av)
{
	*conf = malloc(sizeof(t_config));
	if (!conf)
		return (2); // add personalized message: error.
	if (find_map(av, conf) == FAILS)
		return (2);
	print_map(conf);
	// if (map_data(conf, av) == FAILS)
		// return (-1);
	return (0);
}
