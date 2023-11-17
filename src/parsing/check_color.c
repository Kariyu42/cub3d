#include "cub3d.h"
#include "err_type.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	same_color(t_config **conf)
{
	int	i;

	i = 0;
	if ((*conf)->c_color[0] && (*conf)->c_color[1] && (*conf)->c_color[2]
		&& (*conf)->f_color[0] && (*conf)->f_color[1] && (*conf)->f_color[2])
	{
		if (ft_strcmp((*conf)->c_color[0], (*conf)->f_color[0]) == 0)
			i++;
		if (ft_strcmp((*conf)->c_color[1], (*conf)->f_color[1]) == 0)
			i++;
		if (ft_strcmp((*conf)->c_color[2], (*conf)->f_color[2]) == 0)
			i++;
		if (i != 3)
			return (SUCCES);
		else
			return (ERROR);
	}
	else
		return (ERROR);
}

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	valid_color(char **color)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (color[i])
	{
		c = ft_atoi(color[i]);
		if (!(c >= 0 && c <= 255))
			return (ERROR);
		i++;
	}
	return (SUCCES);
}

int	check_color(char ***color, char *str)
{
	int	i;

	i = 0;
	if (str[i + 1] != ' ')
		return (ERROR);
	i++;
	while (!ft_isdigit(str[i]))
		i++;
	color[0] = ft_split(str + i, ',');
	if (color[0] == NULL)
		return (0);
	if ((len_tab(color[0]) == 3 && valid_color(color[0]) == SUCCES))
		return (SUCCES);
	else
		return (ERROR); //add error message
}
