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

int	map_data(t_config *conf, char **av)
{
	// // collection of map textures;
	// conf->data[0] = map_info(av, "NO");
	// conf->data[1] = map_info(av, "SO");
	// conf->data[2] = map_info(av, "WE");
	// conf->data[3] = map_info(av, "EA");

	// //collection of map color: floor, ceiling;
	// conf->data[4] = map_color("F");
	// conf->data[5] = map_color("C");
	// // fd = open(av[1], O_RDONLY);
	// // if (fd == -1)
	// // 	return (-1);
	// // while (1)
	// // {
	// // 	line = get_next_line(fd);

	// // }
	// // close(fd);
	return (0);
}

char **collect_map(int fd, char *line)
{
	char	**map;
	// while (line != NULL)
	// {
	// }
}

/*
MAP: "10NWES " and space
*/
bool	scan_map(char *line, t_config *conf)
{
	int	i;

	i = 0;
	conf->map_loc = 0;
	while (line[i] && line[i] == ' ')
	{
		conf->map_loc++;
		i++;
	}
	if (ft_strchr("1", line[i]))
		return (true);
	return (false);
}

int	find_map(char **av, t_config *conf)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("", STDERR_FILENO));
	while (true)
	{
		line = get_next_line(fd);
		if (scan_map(line, conf) == true)
			break ;
	}
	conf->map_len = map_len(conf);
	// stock all map
	conf->map = collect_map(fd, line);
}

int	parse_data(t_config *conf, char **av)
{
	conf = malloc(sizeof(t_config));
	if (!conf)
		return (2); // add personalized message: error.
	if (find_map(av, conf) == FAILS)
		return (2)
	// if (map_data(conf, av) == FAILS)
		// return (-1);
	return (0);
}
