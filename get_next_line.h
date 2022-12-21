/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:22:53 by gle-roux          #+#    #+#             */
/*   Updated: 2022/12/21 07:35:11 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h> //read
# include <stdlib.h> //malloc ; free

/* -------------------- get_next_line -------------------- */
char	*get_before(char *save, char *line);
char	*get_next_line(int fd);
char	*keep_after(char *save);
char	*read_n_save(int fd, char *save);

/* ------------------------ utils ------------------------ */
void	*ft_calloc(size_t count, size_t size);
void	*ft_free(char *str1, char *str2);
int		ft_strchr_new_line(char *save);
char	*ft_strdup(char *save);
char	*ft_strjoin(char *temp, char *buf);

#endif
