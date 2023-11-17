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
	char	*no_text;// epraduro
	char 	*so_text;// epraduro
	char 	*we_text;// epraduro
	char 	*ea_text;// epraduro
	int		no_find;
	int		so_find;
	int		we_find;
	int		ea_find;
	int 	f_find;// epraduro
	int 	c_find;// epraduro
	char	**f_color;// epraduro
	char	**c_color;// epraduro
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

/*	GET_TEXTURE.C	*/
int		skip(char *line);
char	*get_texture_path_no(t_config **conf);
char	*get_texture_path_so(t_config **conf);
char	*get_texture_path_we(t_config **conf);
char	*get_texture_path_ea(t_config **conf);

/*	CHECK_COLOR.C	*/
int	ft_strcmp(char *s1, char *s2);
int	same_color(t_config **conf);
int	len_tab(char **tab);
int	valid_color(char **color);
int check_color(char ***color, char *line);

/*	MAP_DATA.C	*/
bool	is_dir(char *arg);
bool	is_xpm_file(char *arg);
int	check_path(char *arg);
int check_data(t_config **conf);


// int	ft_close(t_vars *vars);