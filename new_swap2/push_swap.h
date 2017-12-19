#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libftprintf/includes/ft_printf.h"
# include <limits.h>

# define NB(X)				((t_nb *)((X)->content))
# define ACTIONS(X)			((t_act *)((X)->content))
# define PIVOT(X)			((t_pivot *)((X)->content))
# define OPTIONS			"nvcli"

/*
*************  Define couleur ***************
*/

# define RED				"\e[31m"
# define BLUE				"\e[34m"
# define CYAN				"\e[36m"
# define BLACK				"\e[30m"
# define GREEN				"\e[32m"
# define BROWN				"\e[0;33m"
# define DEFAULT			"\e[39m"
# define MAGENTA			"\e[35m"
# define BOLD_RED			"\e[1;31m"
# define BOLD_BLUE			"\e[1;34m"
# define BOLD_CYAN			"\e[1;36m"
# define LIGHT_GREY			"\e[37m"
# define BOLD_BLACK			"\e[1;30m"
# define BOLD_GREEN			"\e[1;32m"
# define BOLD_BROWN			"\e[0;1;33m"
# define BOLD_DEFAULT		"\e[1;39m"
# define BOLD_MAGENTA		"\e[1;35m"
# define BOLD_LIGHT_GREY	"\e[1;37m"
# define END				"\033[0m"

/*
*************  Structures  ***************
*/

typedef struct				s_pivot
{
	t_elem					*pos;
	int						lower;
	int						upper;
	int						gap;
}							t_pivot;

typedef struct				s_lst
{
	t_dbllist				*a;
	t_dbllist				*b;
	t_dbllist				*actions;
	t_dbllist				*piv;

}							t_lst;

typedef struct				s_nb
{
	int						n;
	int						check;
}							t_nb;

typedef struct				s_act
{
	char					*name;
}							t_act;

typedef struct				s_options
{
	int						n;
	int						v;
	int						c;
	int						l;
	int						i;
}							t_options;

/*
************* Descriptions of options **************
*/

/*
** n - display the number of actions executed
** v - display list a and b after each actions
** c - put color to the last action executed
** l - put list sorted
** i - information about sort
*/

/*
****************************************************
*/

/*
*********************** Initialisation ********************
*/

void						ini_tnb(t_nb *snb);
void						ini_topt(t_options *sopt);
void						ini_lst_empty(t_lst *l);
void						ini_lst(t_lst *l);
void						freeing_lst(t_lst	*l);
void						ini_pivot(t_pivot *pivot);

/*
*********************** Recovery and verif ********************
*/

int							recover(t_lst *l, t_options *options, char **av);
int							recover_and_verif(t_dbllist **a, t_options *options,
							char **av);
int							verif_dup(t_dbllist **a);
int							verif_limits(char *av);
int							verif_digit(char *av);
int							verif_options(char *av, t_options *options);

/*
*********************** Lists fonctions ********************
*/

void						del_and_free_actions(t_dbllist **list,
							t_elem *to_remove);
void						ft_lstactionsdel(t_dbllist **list);

/*
*********************** Actions ********************
*/

void						sa(t_lst *l);
void						sb(t_lst *l);
void						ss(t_lst *l);
void						pa(t_lst *l);
void						pb(t_lst *l);
void						ra(t_lst *l);
void						rb(t_lst *l);
void						rr(t_lst *l);
void						rra(t_lst *l);
void						rrb(t_lst *l);
void						rrr(t_lst *l);

/*
*********************** Algorithme ********************
*/

void						algo(t_lst *l, t_options *options);
t_elem						*find_min(t_dbllist **pile);
int							which_side(t_dbllist **pile, t_elem *elem,
							int *count);
void						tri_simple(t_lst *l, t_options *options, int *tri);
int							a_is_almost_sorted(t_lst *l, t_options *options,
							int *tri);
void						more_effective_moving(t_lst *l, t_elem *elem,
							t_options *options);
void						more_effective_moving_b(t_lst *l, t_elem *elem,
							t_options *options);
int							be_almost_sorted_2(t_lst *l, t_options *options,
							int *tri);
int							is_sorted(t_dbllist *lst);
int							is_reversed(t_dbllist *lst);
void						tri_quicksort(t_lst *l, t_options *options,
							int *tri);
int							which_pivot(t_lst *l, int value);
void						lst_pivot(t_lst *l);
void						tri_a(t_lst *l, t_options *options);
void						tri_b(t_lst *l, t_options *options);

/*
*********************** Display ********************
*/

void						showlsthead(t_dbllist *list);
void						display(t_lst *l, t_options *options, int tri);
void						show_actions(t_dbllist *actions,
							t_options *options);
void						show_piles(t_lst *l, char *actions);
void						sa_color(void);
void						sb_color(void);
void						ss_color(void);
void						pa_color(void);
void						pb_color(void);
void						ra_color(void);
void						rb_color(void);
void						rr_color(void);
void						rra_color(void);
void						rrb_color(void);
void						rrr_color(void);
void						which_tri(int tri);

#endif
