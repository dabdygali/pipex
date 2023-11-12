/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:16:03 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/12 11:55:35 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc == 1 || parse_args(argc, argv) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
