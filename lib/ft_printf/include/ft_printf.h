/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 08:35:34 by hkumagai          #+#    #+#             */
/*   Updated: 2022/08/26 05:13:05 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/types.h>
# include <stdbool.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include "../../libft/include/libft.h"

int		ft_printf(const char *format, ...);
int		ft_formatlen(const char *format, va_list args);
char	*ft_convert_from_base(int base, unsigned long long nb, bool sign);
int		ft_output_c(va_list args);
int		ft_output_s(va_list args);
int		ft_output_p(va_list args);
int		ft_output_di(va_list args);
int		ft_output_u(va_list args);
int		ft_output_x(va_list args);
int		ft_output_X(va_list args);
int		ft_output_ps(void);

#endif
