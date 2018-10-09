/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecalimac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 20:53:18 by ecalimac          #+#    #+#             */
/*   Updated: 2018/01/12 18:06:30 by vistrate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		error_malloc(void)
{
	ft_putendl("error");
	exit(1);
}

char		***make_array(char *name)
{
	char	***matrice;
	int		i;
	int		j;

	i = 0;
	if (!(matrice = (char ***)malloc(sizeof(char **) * g_pieces)))
		error_malloc();
	while (i < g_pieces)
		if (!(matrice[i++] = (char **)malloc(sizeof(char *) * 4)))
			error_malloc();
	i = 0;
	while (i < g_pieces)
	{
		j = 0;
		while (j < 4)
			if (!(matrice[i][j++] = (char *)malloc(sizeof(char) * 4)))
				error_malloc();
		i++;
	}
	return (matrice = populare_matrice(matrice, name));
}

char		***populare_matrice(char ***matrice, char *name)
{
	int		fd;
	int		i;
	char	buf[21];
	int		r;

	i = 0;
	if ((fd = open(name, O_RDONLY)) == -1)
		error_malloc();
	while ((r = read(fd, buf, 21)))
	{
		if (r == -1)
			error_malloc();
		matrice[i] = populare_matrice2(matrice[i], buf);
		i++;
	}
	close(fd);
	return (matrice);
}

char		**populare_matrice2(char **piesa, char buf[21])
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			piesa[i][j] = *buf;
			buf++;
			j++;
		}
		buf++;
		i++;
	}
	return (piesa);
}

void		print_array(char ***matrice)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < g_pieces)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				ft_putchar(matrice[i][j][k]);
				k++;
			}
			ft_putchar('\n');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
