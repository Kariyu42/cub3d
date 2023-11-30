#include "cub3d.h"
#include "err_type.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.addr = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

void	put_img_to_window(t_vars *vars, t_image image, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win,
		image.reference, x, y);
}

void	load_img(t_vars *vars)
{
	vars->bdd.floor = ft_new_sprite(vars->mlx, "./textures/floor.xpm");
	vars->bdd.wall = ft_new_sprite(vars->mlx, "./textures/wall.xpm");
	vars->bdd.player = ft_new_sprite(vars->mlx, "./textures/player.xpm");
	vars->bdd.empty = ft_new_sprite(vars->mlx, "./textures/void.xpm");
}

void	get_coor_player(t_config **conf)
{
	int	i;
	int	j;

	i = -1;
	while ((*conf)->map[++i])
	{
		j = 0;
		while ((*conf)->map[i][j])
		{
			if ((*conf)->map[i][j] == 'N' || (*conf)->map[i][j] == 'E'
				|| (*conf)->map[i][j] == 'S' || (*conf)->map[i][j] == 'W')
			{
				(*conf)->pos_p_x = j;
				(*conf)->pos_p_y = i;
				return ;
			}
			j++;
		}
	}
}

void	put_image_minmap(t_config **conf, t_vars *vars, int i, int j)
{
	if (((*conf)->pos_y >= 0 && (*conf)->pos_y < (*conf)->map_len)
		&& ((*conf)->pos_x >= 0
			&& (*conf)->pos_x < (int) ft_strlen((*conf)->map[(*conf)->pos_y])))
	{
		if ((*conf)->map[(*conf)->pos_y][(*conf)->pos_x] == '1')
			put_img_to_window(vars, vars->bdd.wall, j * 12, i * 12);
		else if ((*conf)->map[(*conf)->pos_y][(*conf)->pos_x] == '0')
			put_img_to_window(vars, vars->bdd.floor, j * 12, i * 12);
		else if ((*conf)->map[(*conf)->pos_y][(*conf)->pos_x] == 'N'
			|| (*conf)->map[(*conf)->pos_y][(*conf)->pos_x] == 'E'
			|| (*conf)->map[(*conf)->pos_y][(*conf)->pos_x] == 'S'
			|| (*conf)->map[(*conf)->pos_y][(*conf)->pos_x] == 'W')
			put_img_to_window(vars, vars->bdd.player, j * 12, i * 12);
		else if ((*conf)->map[(*conf)->pos_y][(*conf)->pos_x] == ' ')
			put_img_to_window(vars, vars->bdd.empty, j * 12, i * 12);
	}
	else
		put_img_to_window(vars, vars->bdd.empty, j * 12, i * 12);
}

int	load_map(t_config **conf, t_vars *vars)
{
	int	i;
	int	j;

	get_coor_player(conf);
	(*conf)->pos_y = (*conf)->pos_p_y - (MID_MIMMAP - 1);
	i = -1;
	while (++i < SIZE_MINMAP)
	{
		j = -1;
		(*conf)->pos_x = (*conf)->pos_p_x - (MID_MIMMAP - 1);
		while (++j < SIZE_MINMAP)
		{
			put_image_minmap(conf, vars, i, j);
			(*conf)->pos_x++;
		}
		(*conf)->pos_y++;
	}
	return (SUCCES);
}
