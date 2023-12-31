#include "cub3d.h"
#include "err_type.h"

/*
* CheckList for the Map: kquetat-
TODO check extension .cub ✅
TODO collect map, trim \n ✅
TODO Check map characters 😊
TODO At the same time check at least for ONLY one player, Not more than one. 😊
TODO Surround (entouré la carte) map with '/' ou pas... juste les espaces.
TODO Check map is closed using flood fill
! Need to check if there is more to add...

* CheckList for the Data ABOVE the map: epraduro
TODO collect data, STOP condition is: if we encouter map we stop parsing.
TODO check if all data is present.
TODO check if path of texture is valid.
TODO check format of data SO, WE, NO, EA, C, F.
TODO color: check that colors are separated by colons ",".
TODO color: check that integer doesn't exceed 0 - 255.

* OMG RayCasting...

*/

t_window	new_window(t_vars *vars, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(vars->mlx, widht, height, name);
	return (window);
}

int	ft_close(void)
{
	write(1, "Vous avez fermé la fenêtre du jeu!\n", 38);
	exit(0);
}

int	start_game(t_config **conf, t_vars *vars)
{

	// hook take one param t_vars need to be in t_conf !!!
	(void) conf;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1000, 800, "Cub3D");
	load_img(vars);
	if (load_map(conf, vars) == ERROR)
		return (ERROR);
	mlx_hook(vars->win, 17, 0, ft_close, &vars);
	mlx_loop(vars->mlx);
	return (SUCCES);
}

int	main(int ac, char **av)
{
	t_vars		vars;
	int			err_type;
	t_config	*conf;

	if (ac < 2)
		return (ft_putendl_fd(ARG_ERR, STDERR_FILENO));
	err_type = parse_data(&conf, av);
	if (err_type == FAILS) // must add launch_game(); later.
		return (-1);
	else if (err_type == 2)
		return (2);
	if (start_game(&conf, &vars) == ERROR)
		return (ERROR);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	int			err_type;
// 	t_config	*conf; 

// 	if (ac < 2)
// 		return (ft_putendl_fd(ARG_ERR, STDERR_FILENO));
// 	err_type = parse_data(&conf, av);
// 	if (err_type == FAILS) // must add launch_game(); later.
// 		return (-1);
// 	else if (err_type == 2)
// 		return (2);
// 	return (0);
// }

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