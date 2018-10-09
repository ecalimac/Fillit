/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecalimac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:37:06 by ecalimac          #+#    #+#             */
/*   Updated: 2018/01/12 18:13:50 by vistrate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		potriveste_harta(char ***matrice)
{
	t_tetri		*offsets;
	int			i;
	int			i_off;
	char		**harta;

	i = 0;
	i_off = 0;
	offsets = create_offset_list(matrice);
	while (1)
	{
		g_map_size = creeaza_dimensiunea_hartii() + i;
		harta = populeaza_harta();
		if (magic(offsets, i_off, harta))
		{
			afiseaza_solutia(harta);
			elibereaza_harta(harta);
			free(offsets);
			return ;
		}
		elibereaza_harta(harta);
		i++;
	}
}

void		afiseaza_solutia(char **harta)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_map_size)
	{
		j = 0;
		while (j < g_map_size)
		{
			ft_putchar(harta[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int			magic(t_tetri *offsets, int i_off, char **harta)
{
	int		i;
	int		j;

	if (i_off == g_pieces)
		return (1);
	i = 0;
	while (i < g_map_size)
	{
		j = 0;
		while (j < g_map_size)
		{
			if (loc_valid(j, i, offsets[i_off], harta))
			{
				pune(j, i, offsets[i_off], harta);
				if (magic(offsets, i_off + 1, harta))
					return (1);
				scoate(j, i, offsets[i_off], harta);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			loc_valid(int i, int j, t_tetri piesa, char **harta)
{
	if (harta[j][i] != '.')
		return (0);
	if ((i + piesa.offset2[0] < 0 || i + piesa.offset2[0] >= g_map_size))
		return (0);
	if ((j + piesa.offset2[1] < 0 || j + piesa.offset2[1] >= g_map_size))
		return (0);
	if ((i + piesa.offset3[0] < 0 || i + piesa.offset3[0] >= g_map_size))
		return (0);
	if ((j + piesa.offset3[1] < 0 || j + piesa.offset3[1] >= g_map_size))
		return (0);
	if ((i + piesa.offset4[0] < 0 || i + piesa.offset4[0] >= g_map_size))
		return (0);
	if ((j + piesa.offset4[1] < 0 || j + piesa.offset4[1] >= g_map_size))
		return (0);
	if (harta[j + piesa.offset2[1]][i + piesa.offset2[0]] != '.')
		return (0);
	if (harta[j + piesa.offset3[1]][i + piesa.offset3[0]] != '.')
		return (0);
	if (harta[j + piesa.offset4[1]][i + piesa.offset4[0]] != '.')
		return (0);
	return (1);
}

void		pune(int i, int j, t_tetri piesa, char **harta)
{
	harta[j][i] = piesa.letter;
	harta[j + piesa.offset2[1]][i + piesa.offset2[0]] = piesa.letter;
	harta[j + piesa.offset3[1]][i + piesa.offset3[0]] = piesa.letter;
	harta[j + piesa.offset4[1]][i + piesa.offset4[0]] = piesa.letter;
}

void		scoate(int i, int j, t_tetri piesa, char **harta)
{
	harta[j][i] = '.';
	harta[j + piesa.offset2[1]][i + piesa.offset2[0]] = '.';
	harta[j + piesa.offset3[1]][i + piesa.offset3[0]] = '.';
	harta[j + piesa.offset4[1]][i + piesa.offset4[0]] = '.';
}

int			creeaza_dimensiunea_hartii(void)
{
	int		i;

	i = 2;
	while ((i * i) < (g_pieces * 4))
		i++;
	return (i);
}

char		**populeaza_harta(void)
{
	char	**harta;
	int		i;
	int		j;

	i = 0;
	if (!(harta = (char **)malloc(sizeof(char *) * g_map_size)))
		error_malloc();
	while (i < g_map_size)
		harta[i++] = (char *)malloc(sizeof(char) * g_map_size);
	i = 0;
	while (i < g_map_size)
	{
		j = 0;
		while (j < g_map_size)
		{
			harta[i][j] = '.';
			j++;
		}
		i++;
	}
	return (harta);
}

void		elibereaza_harta(char **harta)
{
	int	i;

	i = 0;
	while (i < g_map_size)
	{
		free(harta[i]);
		i++;
	}
	free(harta);
}

void		elibereaza_set_piese(char ***set)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_pieces)
	{
		j = 0;
		while (j < 4)
		{
			free(set[i][j]);
			j++;
		}
		free(set[i]);
		i++;
	}
	free(set);
}
