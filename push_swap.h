#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"


/* 
------------ Structures se cachent ici ------------
*/

typedef struct 			s_pushswap
{
  t_double				*stack_a;
  t_double 				*stack_b;
  t_double				*stack_op;
  t_double				*stack_pivot;  
}						t_pushswap;

typedef struct 			s_args
{
	int					info:1;
	int 				num:1;
	int 				debug:1;
}						t_args;

typedef struct 			s_n
{
	int					nb;
	int					flag;	
}						t_n;














#endif