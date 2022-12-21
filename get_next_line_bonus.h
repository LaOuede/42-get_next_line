/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:22:53 by gle-roux          #+#    #+#             */
/*   Updated: 2022/12/21 07:36:01 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h> //read
# include <stdlib.h> //malloc ; free

/* -------------------- get_next_line -------------------- */
char	*read_n_save(int fd, char *save);
void	*ft_free(char *str1, char *str2);
char	*get_before(char *save, char *line);
char	*get_next_line(int fd);
char	*keep_after(char *save);

/* ------------------------ utils ------------------------ */
void	*ft_bzero(char *str, size_t len);
void	*ft_calloc(size_t count, size_t size);
int		ft_strchr_new_line(char *save);
char	*ft_strdup(char *save);
char	*ft_strjoin(char *temp, char *buf);

#endif
