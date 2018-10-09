/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecalimac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 19:38:09 by ecalimac          #+#    #+#             */
/*   Updated: 2018/01/12 18:23:17 by vistrate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			usage(void)
{
	ft_putendl("usage: ./fillit input_file");
	return (1);
}

int			main(int argc, char **argv)
{
	char	***matrice;

	if (argc != 2)
		return (usage());
	if (map_validator(argv[1]))
	{
		matrice = make_array(argv[1]);
		if (check4diez(matrice) && check_map_pieces_form(matrice))
			potriveste_harta(matrice);
		else
		{
			ft_putendl("error");
			elibereaza_set_piese(matrice);
			return (1);
		}
	}
	else
	{
		ft_putendl("error");
		return (1);
	}
	elibereaza_set_piese(matrice);
	return (0);
}
