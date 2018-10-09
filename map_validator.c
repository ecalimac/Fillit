/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecalimac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:54:38 by ecalimac          #+#    #+#             */
/*   Updated: 2018/01/12 18:28:36 by vistrate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			map_validator(char *name)
{
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (0);
	if (map_validator2(fd, 0, 0, 'e'))
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int			map_validator2(int fd, int c, int l, char buf)
{
	while (read(fd, &buf, 1))
	{
		if (buf != '.' && buf != '#' && buf != '\n')
			return (0);
		if (c > 4 || l > 4)
			return (0);
		if (buf == '\n' && l == 4)
		{
			g_pieces++;
			l = 0;
			c = 0;
		}
		else if (buf == '\n' && c == 4)
		{
			l++;
			c = 0;
		}
		else
			c = (buf != '\n') ? (c + 1) : (42);
	}
	if (c == 0 && l == 4 && ++g_pieces)
		return (1);
	return (0);
}

int			check4diez(char ***matrice)
{
	int		i;
	int		j;
	int		k;
	int		contor;

	i = 0;
	contor = 0;
	while (i < g_pieces)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				if (matrice[i][j][k] == '#')
					contor++;
				k++;
			}
			j++;
		}
		if (contor != 4)
			return (0);
		contor = 0;
		i++;
	}
	return (1);
}

int			check_map_pieces_form(char ***matrice)
{
	int		i;
	int		n;

	i = 0;
	while (i < g_pieces)
	{
		n = check_piece_form(matrice[i]);
		if (n != 6 && n != 8)
			return (0);
		i++;
	}
	return (1);
}

int			check_piece_form(char **piesa)
{
	int		i;
	int		j;
	int		atingeri;

	i = 0;
	atingeri = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piesa[i][j] == '#')
				atingeri = atingeri + calculeaza_atingerile(piesa, i, j);
			j++;
		}
		i++;
	}
	return (atingeri);
}

int			calculeaza_atingerile(char **piesa, int i, int j)
{
	int		atingeri;

	atingeri = 0;
	if (i + 1 >= 0 && i + 1 < 4)
		if (piesa[i + 1][j] == '#')
			atingeri++;
	if (i - 1 >= 0 && i - 1 < 4)
		if (piesa[i - 1][j] == '#')
			atingeri++;
	if (j + 1 >= 0 && j + 1 < 4)
		if (piesa[i][j + 1] == '#')
			atingeri++;
	if (j - 1 >= 0 && j - 1 < 4)
		if (piesa[i][j - 1] == '#')
			atingeri++;
	return (atingeri);
}
