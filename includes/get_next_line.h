/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:25:59 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/09/27 11:26:00 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<stddef.h>
# include<fcntl.h>
# include<sys/types.h>
# include<unistd.h>
# define BUFFER_SIZE 1024

char	*ft_sub(char const *s, int start, int len);
char	*ft_strd(char *s);
int		ft_strl(const char *s);
char	*get_next_line(int fd);
int		line_in_str(char *str);
char	*aff_line(char *str);
char	*after_line(char *str);
char	*ft_strj(char *s1, char *s2);
char	*to_ret(char **str);
char	*freeee(char *str);

#endif