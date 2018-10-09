/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_offsets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecalimac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:29:25 by ecalimac          #+#    #+#             */
/*   Updated: 2018/01/12 18:10:30 by vistrate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*create_offset_list(char ***matrice)
{
	int		i;
	t_tetri	*piece_offsets;

	i = 0;
	if (!(piece_offsets = (t_tetri *)malloc(sizeof(t_tetri) * g_pieces)))
		error_malloc();
	while (i < g_pieces)
	{
		piece_offsets[i] = create_piece_offset(piece_offsets[i], matrice[i]);
		piece_offsets[i].letter = 'A' + i;
		i++;
	}
	return (piece_offsets);
}

t_tetri		create_piece_offset(t_tetri offset_piesa, char **piesa)
{
	int		i;
	int		**poz;

	if (!(poz = (int **)malloc(sizeof(int *) * 4)))
		error_malloc();
	i = 0;
	while (i < 4)
	{
		poz[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	poz = calculate_poz(poz, piesa);
	offset_piesa.offset1[0] = 0;
	offset_piesa.offset1[1] = 0;
	offset_piesa.offset2[0] = poz[1][0] - poz[0][0];
	offset_piesa.offset2[1] = poz[1][1] - poz[0][1];
	offset_piesa.offset3[0] = poz[2][0] - poz[0][0];
	offset_piesa.offset3[1] = poz[2][1] - poz[0][1];
	offset_piesa.offset4[0] = poz[3][0] - poz[0][0];
	offset_piesa.offset4[1] = poz[3][1] - poz[0][1];
	elibereaza_poz(poz);
	return (offset_piesa);
}

int			**calculate_poz(int **poz, char **piesa)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piesa[i][j] == '#')
			{
				poz[k][0] = j;
				poz[k][1] = i;
				k++;
			}
			j++;
		}
		i++;
	}
	return (poz);
}

void		elibereaza_poz(int **poz)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		free(poz[i]);
		i++;
	}
	free(poz);
}
