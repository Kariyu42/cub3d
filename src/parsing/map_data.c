#include "cub3d.h"
#include "err_type.h"

/*
* CheckList for the Data ABOVE the map.
TODO collect data, STOP condition is: if we encouter map we stop parsing.
TODO check if all data is present. 🤗
TODO check if path of texture is valid.
TODO check format of data SO, WE, NO, EA, C, F.
TODO color: check that colors are separated by colons ",".
TODO color: check that integer doesn't exceed 0 - 255.
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int check_data(t_config **conf)
{
	int i;

	i = 0;
	(*conf)->count_data = 0;
	while (i < (*conf)->map_loc)
	{
		if (ft_strchr((*conf)->file[i], 'N') && ft_strchr((*conf)->file[i], 'O'))
			(*conf)->count_data++;
		else if (ft_strchr((*conf)->file[i], 'S') && ft_strchr((*conf)->file[i], 'O'))
			(*conf)->count_data++;
		else if (ft_strchr((*conf)->file[i], 'W') && ft_strchr((*conf)->file[i], 'E'))
			(*conf)->count_data++;
		else if (ft_strchr((*conf)->file[i], 'E') && ft_strchr((*conf)->file[i], 'A'))
			(*conf)->count_data++;
		else if (ft_strchr((*conf)->file[i], 'F'))
			(*conf)->count_data++;
		else if (ft_strchr((*conf)->file[i], 'C'))
			(*conf)->count_data++;
		i++;
	}
	printf("%d\n", (*conf)->count_data);
	if ((*conf)->count_data != 6)
		return (2);		//add error message
	return (0);
}

// int check_color(t_config **conf)
// {
// 	int i;

// 	i = 0;
// 	if (ft_strchr((*conf)->file[i], 'F'))
// 	{
		
// 	}
// }