#include "cub3d.h"
#include "err_type.h"

void	print_map(t_config **conf)
{
	int	i;

	i = 0;
	while ((*conf)->map[i])
	{
		printf("%s\n", (*conf)->map[i]);
		i++;
	}
}

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

char	*trim_newline(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	str[i] = '\0';
	return (str);
}

char	**collect_map(t_config **conf)
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

int	map_len(t_config **conf)
{
	int	i;
	int	res;
	int line;

	res = 0;
	line = 0;
	i = (*conf)->map_loc;
	while ((*conf)->file[i])
	{
		line = count_map((*conf)->file[i]);
		if (line == 2)
			break;      // add error message
		res += line;
		i++;
	}
	return (res);
}

int	pinpoint_map(t_config **conf)
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
		return (2);
	(*conf)->map_len = map_len(conf);
	printf("petit truc %d\n", (*conf)->map_len);
	(*conf)->map = collect_map(conf);   // stock all map
	//print_map(conf);
	return (0);
}

int	verif_extension(char *str)
{
	int len;
	int fd;

	len = ft_strlen(str);
	fd = open(str, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (FAILS); // add error message
	}
	close(fd);
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

int	parse_data(t_config **conf, char **av)
{
	int	fd;

	fd = 0;
	*conf = malloc(sizeof(t_config));
	if (!conf)
		return (2); // add personalized message: error.
	if (verif_extension(av[1]) == FAILS)
		return (2);
	if (collect_data(conf, av, fd) == -1 || find_map(conf) == -1)
		return (2);
	if (check_data(conf) == 2)
		return (2);
	if (check_format(conf) == 2)
		return (2);
	// print_map(conf);
	// if (map_data(conf, av) == FAILS)
		// return (-1);
	return (0);
}
