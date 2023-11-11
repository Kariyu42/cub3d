#include "cub3d.h"
#include "err_type.h"

int	main(int ac, char **av)
{
	t_config	conf;

	if (ac != 2)
		return (ft_putendl_fd(ARG_ERR, -1));
	else if (parse_data(&conf, av) == FAILS) // must add launch_game(); later.
		return (-1);
	return (0);
}

// int	ft_close(t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1000, 800, "Cub3D");
// 	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
// 	mlx_loop(vars.mlx);
// }