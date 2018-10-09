/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecalimac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:38:37 by ecalimac          #+#    #+#             */
/*   Updated: 2018/01/12 18:15:52 by vistrate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_tetri
{
	int			offset1[2];
	int			offset2[2];
	int			offset3[2];
	int			offset4[2];
	char		letter;
}				t_tetri;

int				g_pieces;
int				g_map_size;
int				usage(void);
int				map_validator(char *name);
int				map_validator2(int fd, int c, int l, char buf);
void			error_malloc(void);
char			***make_array(char *name);
char			***populare_matrice(char ***matrice, char *name);
char			**populare_matrice2(char **piesa, char buf[21]);
void			print_array(char ***matrice);
int				check4diez(char ***matrice);
int				check_map_pieces_form(char ***matrice);
int				check_piece_form(char **piesa);
int				calculeaza_atingerile(char **piesa, int i, int j);
t_tetri			*create_offset_list(char ***matrice);
t_tetri			create_piece_offset(t_tetri offset_piesa, char **piesa);
int				**calculate_poz(int **poz, char **piesa);
void			elibereaza_poz(int **poz);
void			potriveste_harta(char ***matrice);
int				magic(t_tetri *offsets, int i_off, char **harta);
int				loc_valid(int i, int j, t_tetri piesa, char **harta);
void			pune(int i, int j, t_tetri piesa, char **harta);
void			scoate(int i, int j, t_tetri piesa, char **harta);
int				creeaza_dimensiunea_hartii(void);
char			**populeaza_harta(void);
void			afiseaza_solutia(char **harta);
void			elibereaza_harta(char **harta);
void			elibereaza_set_piese(char ***set);
#endif
