#include "cub3d.h"
#include "err_type.h"

// int	skip(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] && line[i] != ' ' && line[i] != '\t')
// 		i++;
// 	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
// 		i++;
// 	return (i);
// }

int	ft_contain(char *str, char *find)
{
	int	i;
	int	j;
	int	k;
	int	len_find;

	i = 0;
	len_find = ft_strlen(find);
	while (str[i])
	{
		j = 0;
		k = i;
		while (str[k] == find[j])
		{
			j++;
			k++;
		}
		if (j == len_find)
			return (1);
		i++;
	}
	return (0);
}

int	check_path(char *arg)
{
	int	fd;
	int	len;

	format_path_texture(arg);
	len = ft_strlen(arg);
	if (is_dir(arg))
		return (ft_putendl_fd(DIR_ERR, STDERR_FILENO));
	if (arg[len - 4] != '.' || arg[len - 3] != 'x' || \
	arg[len - 2] != 'p' || arg[len - 1] != 'm')
		return (ft_putendl_fd(XPM_ERR, STDERR_FILENO));
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd(OPEN_ERR, STDERR_FILENO));
	close(fd);
	return (SUCCES);
}

int	get_texture_path(char *str, char **store_data, int *data)
{
	if (ft_contain(str, ".xpm") == 0)
		return (ERROR);
	else
	{
		*store_data = str + 3;
		(*data)++;
	}
	return (check_path(*store_data));
}

int	get_textures(t_config **conf, int i)
{
	if (ft_contain((*conf)->file[i], "NO"))
	{
		if (get_texture_path((*conf)->file[i],
				&(*conf)->no_text, &(*conf)->count_data) == ERROR)
			return (ft_putendl_fd(PATH_ERR, STDERR_FILENO));
	}
	else if (ft_contain((*conf)->file[i], "SO"))
	{
		if (get_texture_path((*conf)->file[i],
				&(*conf)->so_text, &(*conf)->count_data) == ERROR)
			return (ft_putendl_fd(PATH_ERR, STDERR_FILENO));
	}
	else if (ft_contain((*conf)->file[i], "WE"))
	{
		if (get_texture_path((*conf)->file[i],
				&(*conf)->we_text, &(*conf)->count_data) == ERROR)
			return (ft_putendl_fd(PATH_ERR, STDERR_FILENO));
	}
	else if (ft_contain((*conf)->file[i], "EA"))
	{
		if (get_texture_path((*conf)->file[i],
				&(*conf)->ea_text, &(*conf)->count_data) == ERROR)
			return (ft_putendl_fd(PATH_ERR, STDERR_FILENO));
	}
	return (SUCCES);
}

int	get_colors(t_config **conf, int i)
{
	if (ft_strchr((*conf)->file[i], 'F'))
	{
		if (check_color(&(*conf)->f_color,
				(*conf)->file[i], &(*conf)->count_data) == ERROR)
			return (ERROR);
	}
	else if (ft_strchr((*conf)->file[i], 'C'))
	{
		if (check_color(&(*conf)->c_color,
				(*conf)->file[i], &(*conf)->count_data) == ERROR)
			return (ERROR);
	}
	return (SUCCES);
}
