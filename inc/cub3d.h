#include "../Lib/Libft/inc/libft.h"
#include "../Lib/Libft/inc/get_next_line.h"
#include "../Lib/minilibx/mlx.h"

#include <fcntl.h>
#include <stdbool.h>

typedef struct s_config
{
	char	**data;
	char	**map;
	char	**file;
	int		file_size;
	int		map_loc;
	int		map_len;
	int		player; // kquetat-
	int		count_data; // epraduro
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

/* --- PARSING --- kquetat- */
int		parse_data(t_config **conf, char **av);
int		find_map(t_config **conf);
int		map_len(t_config **conf);
int		text_size(char **av, int fd);
char	*trim_newline(char *str, char c);
bool	inspect_line(t_config **conf, char *map_line, char *to_find);

/* PRINT MAP WHEN ALREADY STOCKED (must be removed before push)*/
void	print_map(t_config **conf);

/* --- epraduro --- */
int check_data(t_config **conf);
int	ft_strcmp(char *s1, char *s2);
// int	ft_close(t_vars *vars);