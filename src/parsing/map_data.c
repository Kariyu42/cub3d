#include "cub3d.h"
#include "err_type.h"

/*
* CheckList for the Data ABOVE the map.
TODO check if all data is present. 🤗
TODO check if path of texture is valid. 🤗
TODO check format of data SO, WE, NO, EA, C, F. 🤗
TODO color: check that colors are separated by colons ",". 🤗
TODO color: check that integer doesn't exceed 0 - 255. 🤗
*/

void	init_texture(t_config **conf)
{
	(*conf)->count_data = 0;
	(*conf)->no_text = NULL;
	(*conf)->so_text = NULL;
	(*conf)->we_text = NULL;
	(*conf)->ea_text = NULL;
}

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

char	*format_path_texture(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			j = -1;
			while (str[++j])
				str[j] = str[j + 1];
			i = -1;
		}
		else
			break ;
	}
	i = ft_strlen(str);
	i--;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

int	check_data(t_config **conf)
{
	int	i;

	i = -1;
	init_texture(conf);
	while (++i < (*conf)->map_loc)
		if (get_textures(conf, i) == ERROR || get_colors(conf, i) == ERROR)
			return (ERROR);
	// printf("data = %d\n", (*conf)->count_data);
	if ((*conf)->count_data != 6)
		return (ft_putendl_fd(ELEMENT_ERR, STDERR_FILENO));
	if (same_color(conf) == ERROR)
		return (ERROR);
	return (SUCCES);
}
