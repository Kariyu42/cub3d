#include "cub3d.h"
#include "err_type.h"

/*
* CheckList for the Data ABOVE the map.
TODO check if all data is present. 🤗
TODO check if path of texture is valid.
TODO check format of data SO, WE, NO, EA, C, F. 🤗
TODO color: check that colors are separated by colons ",". 🤗
TODO color: check that integer doesn't exceed 0 - 255. 🤗
*/

bool	is_dir(char *arg)
{
	int		fd;
	bool	res;

	res = false;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		res = true;
	}
	return (res);
}

bool	is_xpm_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'x' || arg[len - 2] != 'p'
			|| arg[len - 1] != 'm'
			|| arg[len - 4] != '.'))
		return (false);
	return (true);
}

int	check_path(char *arg)
{
	int	fd;

	if (is_dir(arg))
		return (ERROR);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (ERROR); //add error message
	close(fd);
	if (!is_xpm_file(arg))
		return (ERROR); //add error message
	return (SUCCES);
}

void	init_texture(t_config **conf)
{
	(*conf)->count_data = 0;
	(*conf)->no_find = 0;
	(*conf)->so_find = 0;
	(*conf)->we_find = 0;
	(*conf)->ea_find = 0;
	(*conf)->no_text = NULL;
	(*conf)->so_text = NULL;
	(*conf)->we_text = NULL;
	(*conf)->ea_text = NULL;
}

int	check_data(t_config **conf)
{
	int	i;

	i = 0;
	while (i < (*conf)->map_loc)
	{
		if (ft_strchr((*conf)->file[i], 'N') && \
			ft_strchr((*conf)->file[i], 'O'))
		{
			(*conf)->count_data++;
			(*conf)->no_text = get_texture_path_no(conf);
			if (check_path((*conf)->no_text) == ERROR)
				return (ERROR); //add error message
		}
		else if (ft_strchr((*conf)->file[i], 'S') && \
			ft_strchr((*conf)->file[i], 'O'))
		{
			(*conf)->count_data++;
			(*conf)->so_text = get_texture_path_so(conf);
			if (check_path((*conf)->so_text) == ERROR)
				return (ERROR); //add error message
		}
		else if (ft_strchr((*conf)->file[i], 'W') && \
			ft_strchr((*conf)->file[i], 'E'))
		{
			(*conf)->count_data++;
			(*conf)->we_text = get_texture_path_we(conf);
			if (check_path((*conf)->we_text) == ERROR)
				return (ERROR); //add error message
		}
		else if (ft_strchr((*conf)->file[i], 'E') && \
			ft_strchr((*conf)->file[i], 'A'))
		{
			(*conf)->count_data++;
			(*conf)->ea_text = get_texture_path_ea(conf);
			if (check_path((*conf)->ea_text) == ERROR)
				return (ERROR); //add error message
		}
		else if (ft_strchr((*conf)->file[i], 'F'))
		{
			(*conf)->count_data++;
			if (check_color(&(*conf)->f_color, (*conf)->file[i]) == ERROR)
				return (ERROR); //add error message
		}
		else if (ft_strchr((*conf)->file[i], 'C'))
		{
			(*conf)->count_data++;
			if (check_color(&(*conf)->c_color, (*conf)->file[i]) == ERROR)
				return (ERROR); //add error message
		}
		i++;
	}
	if (same_color(conf) == ERROR)
		return (ERROR); // add error message
	if ((*conf)->count_data != 6)
		return (ERROR); //add error message
	return (SUCCES);
}
