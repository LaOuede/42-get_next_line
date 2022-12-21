/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:23:09 by gle-roux          #+#    #+#             */
/*   Updated: 2022/12/21 10:27:05 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
  Read the file and check for new line character
  Reset buffer to '\0'
  Handle errors during read
  Save what have been read in save and return it
*/
char	*read_n_save(int fd, char *save)
{
	int		rbytes;
	char	*buf;
	char	*temp;

	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (ft_strchr_new_line(save) == 0)
	{
		ft_bzero(buf, BUFFER_SIZE);
		rbytes = read(fd, buf, BUFFER_SIZE);
		if (rbytes == 0)
			break ;
		if (rbytes < 0)
			return (ft_free(save, buf));
		temp = save;
		save = ft_strjoin(temp, buf);
		ft_free(temp, 0);
	}
	ft_free(buf, 0);
	return (save);
}

/*
  Extract characters before the new line character
  Include the new line character
  Copy all this in line and return line
  Define "index" in order to use keep_after function
*/
char	*get_before(char *save, char *line)
{
	size_t	len;

	len = 0;
	while (save[len] != '\0' && save[len] != '\n')
		len++;
	if (save[len] == '\n')
		len++;
	line = ft_calloc(sizeof * line, len + 1);
	if (!line)
		return (NULL);
	while (len--)
		line[len] = save[len];
	return (line);
}

/*
  Store in save the characters after the new line character
  Use "index" as starting point of extraction
  Free save and return new_save
*/
char	*keep_after(char *save)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = ft_strdup(save);
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\0')
		return (save = ft_free(save, temp));
	while (temp[i++])
	{
		save[j] = temp[i];
		j++;
	}
	ft_free (temp, 0);
	return (save);
}

/*Free a string if it exists*/
void	*ft_free(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (0);
}

/*
  Return a single line from a given file descriptor
  As there is a loop, the function returns the entire contents of a file
  (line by line until it reaches the end of the file)
  Works with any BUFFER_SIZE (specified at compilation)
  Pointer to index to get the value of len in get_before function

  Bonus requirements =
   1- only 1 st4tic variable ;
   2- get_next_line need to manage multiple file descriptor without
     losing the reading thread on each descriptors.
*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[1024];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	line = NULL;
	save[fd] = read_n_save(fd, save[fd]);
	if (!save[fd] || *save[fd] == '\0')
		return (save[fd] = ft_free(save[fd], 0));
	line = get_before(save[fd], line);
	if (!line)
		return (line = ft_free(line, 0));
	save[fd] = keep_after(save[fd]);
	return (line);
}
