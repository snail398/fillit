/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <lmaximin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:24:14 by lmaximin          #+#    #+#             */
/*   Updated: 2019/11/28 20:33:54 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/get_next_line.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

#include <stdio.h>

int     main(void)
{
    char *line = NULL;
    int fd = open("src/main.c", O_RDONLY);
    printf("%d",fd);
    get_next_line(fd, &line);
    printf("%s", line);
    close(fd);
    return (0);
}