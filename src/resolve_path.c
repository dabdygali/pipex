/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:39:16 by dabdygal          #+#    #+#             */
/*   Updated: 2023/11/20 18:05:25 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*build_path(char *head, char *cmd, char *name)
{
	int		i;
	char	*substr;
	char	*path;

	while (*head)
	{
		i = 0;
		while (head[i] != ':' && head[i])
			i++;
		substr = ft_substr(head, 0, i);
		if (!substr)
		{
			perror(name);
			return (NULL);
		}
		if (check_existence)

		
		free(substr);
		if (head[i])
			i++;
		head += i;
	}
	return (NULL);
}

int	resolve_path(char **path, char *s, char **env, char *name)
{
	while (*env && !ft_strnstr(*env, "PATH=", 5))
		env++;
	if (*s == '.' || *s == '/' || *env == NULL)
	{
		*path = ft_strdup(s);
		if (*path == NULL)
		{
			perror(name);
			return (-1);
		}
		return (0);
	}
	*path = build_path(*env + 5, s, name);
	if (*path)
		return (0);
	if (ft_putstr_fd(name, STDERR_FILENO) < 0)
		perror(name);
	if (ft_putstr_fd(": command not found: ", STDERR_FILENO) < 0)
		perror(name);
	if (ft_putendl_fd(s, STDERR_FILENO) < 0)
		perror(name);
	return (-1);
}
