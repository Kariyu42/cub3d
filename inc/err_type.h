#include "../Lib/Libft/inc/libft.h"

/* cub3D custom define */
# define FAILS -1
# define ERROR 2
# define SUCCES 0

/* List of Error messages */
# define ARG_ERR "Error\nPlease provide a valid [.cub] map.\n"
# define OPEN_ERR "Error\nFailed to open the file.\n"
# define CLOSE_ERR "Error\nFailed to close the file.\n"
# define MALLOC_ERR "Error\nFailed to malloc\n"
# define DIR_ERR "Error\nCan't open a directory\n"
# define EMPTY_ERR "Error\nNo Map was collected\n"
# define PLAYER_ERR "Error\nCannot have more than one player\n"
# define XPM_ERR "Error\nThe file is not a .xpm or there is an invalid char on the line\n"
# define COLOR_ERR "Error\nPlease give a different color for the sky and the ground\n"
# define NB_COLOR_ERR "Error\nPlease give a number between 0 and 255\n"
# define FORMAT_ERR "Error\nPlease follow the RGB format\n"
# define ELEMENT_ERR "Error\nPlease give 6 elements or be careful to give them the right format\n"
# define PATH_ERR "Error\nTexture wrong path\n"