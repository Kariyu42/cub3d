#include "../Lib/Libft/inc/libft.h"
#include "../Lib/Libft/inc/get_next_line.h"
#include "../Lib/minilibx/mlx.h"

#include <fcntl.h>
#include <stdbool.h>

typedef struct s_config
{
	char	**data;
	char	**map;
	int		map_loc;
	int		map_len;
	/*
	mlx window
	donnees parsing
	map**
	*/
}	t_config;

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

int	parse_data(t_config **conf, char **av);
// int	ft_close(t_vars *vars);