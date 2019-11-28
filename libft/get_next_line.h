/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaximin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:26:10 by lmaximin          #+#    #+#             */
/*   Updated: 2019/09/22 16:26:48 by lmaximin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>

int				get_next_line(const int fd, char **line);
typedef struct	s_file_buf
{
	int		fd;
	char	*data;
}				t_file_buf;

#endif
