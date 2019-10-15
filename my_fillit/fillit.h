
#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

# define L_TETR (int [8]) {0,0,1,0,2,0,2,1};
# define L90_TETR (int [8]) {0,2,1,0,1,1,1,2};
# define L180_TETR (int [8]) {0,0,0,1,1,1,2,1};
# define L270_TETR (int [8]) {0,0,0,1,0,2,1,0};
# define J_TETR (int [8]) {0,1,1,1,2,0,2,1};
# define J90_TETR (int [8]) {0,0,0,1,0,2,1,2};
# define J180_TETR (int [8]) {0,0,0,1,1,0,2,0};
# define J270_TETR (int [8]) {0,0,1,0,1,1,1,2};
# define O_TETR (int [8]) {0,0,0,1,1,0,1,1};
# define I_TETR (int [8]) {0,0,1,0,2,0,3,0};
# define I90_TETR (int [8]) {0,0,0,1,0,2,0,3};
# define T_TETR (int [8]) {0,0,0,1,0,2,1,1};
# define T90_TETR (int [8]) {0,0,1,0,1,1,2,0};
# define T180_TETR (int [8]) {0,1,1,0,1,1,1,2};
# define T270_TETR (int [8]) {0,1,1,0,1,1,2,1};
# define Z_TETR (int [8]) {0,0,0,1,1,1,1,2};
# define Z90_TETR (int [8]) {0,1,1,0,1,1,2,0};
# define S_TETR (int [8]) {0,1,0,2,1,0,1,1};
# define S90_TETR (int [8]) {0,0,1,0,1,1,2,1};

typedef	struct		s_tetrimino
{
	int					*coords;
	char				letter;
	struct	s_tetrimino	*next;
}					t_tetrimino;

int	etetr_read_check(int fd);

#endif
