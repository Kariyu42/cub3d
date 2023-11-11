#include "cub3d.h"
#include "err_type.h"

char	*map_info(char **av, char *pos)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	while ()
	{
		line = get_next_line(fd);
		if (line)
	}
}

int	map_data(t_config *conf, char **av)
{
	// collection of map textures;
	conf->data[0] = map_info(av, "NO");
	conf->data[1] = map_info(av, "SO");
	conf->data[2] = map_info(av, "WE");
	conf->data[3] = map_info(av, "EA");

	//collection of map color: floor, ceiling;
	conf->data[4] = map_color("F");
	conf->data[5] = map_color("C");
	// fd = open(av[1], O_RDONLY);
	// if (fd == -1)
	// 	return (-1);
	// while (1)
	// {
	// 	line = get_next_line(fd);

	// }
	// close(fd);
	return (0);
}

int	parse_data(t_config *conf, char **av)
{
	conf = malloc(sizeof(t_config));
	if (!conf)
		return (-1); // add personalized message: error.
	if (map_data(conf, av) == FAILS)
		return (-1);
	return (0);
}
