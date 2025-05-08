/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:21:29 by aaugusto          #+#    #+#             */
/*   Updated: 2025/05/08 18:19:09 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line; 
	
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: File not opening!");
		return (1);
	}
	
	while ((line = get_next_line(fd) != NULL))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
