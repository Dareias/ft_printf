/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fillip <fillip@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 00:50:19 by fillip            #+#    #+#             */
/*   Updated: 2025/06/09 15:17:05 by fillip           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
/*
hh - char, unsigned char argument
h - short, unsigned short argument
l - long, unsigned long argument
ll - long long, unsigned long long argument
L - a, A, e, E, f, F, g, G long double argument
j - intmax_t uintmax_t argument
z - size_t ssize_t argument
t - ptrdiff_t argument
*/

/*
d, i - int to signed decimal
o, u, x, X - unsigned int to octal, unsigned decimal, hexadecimal
e, E - d.ddde+-dd, exponent, precision spec
f, F - ddd.ddd, precision spec
g, G - wtf?
a, A - hexadecimal something ?
c - if no l modifier, convert int to unsigned char, if l then some multibyte shit
s - if no l, const char * expected as pointer to array, if precision then do special stuff
p - void * to hexadecimal
n - number of characters stored to int pointed to by argument
m - glibc, errno output
*/

static const t_spec g_spec[] = 
{
	{'c', print_char},
	{'s', print_str},
	{'p', print_ptr},
	{'d', print_num},
	{'i', print_num},
	{'u', print_uns},
	{'x', print_lhex},
	{'X', print_uhex},
	{0, NULL}
};

const t_spec	*find_spec(char c)
{
	int	i;

	i = 0;
	while (g_spec[i].printer != NULL)
	{
		if (g_spec[i].spec == c)
			return &g_spec[i];
		i++;
	}
}

int	ft_printf(const char *restrict format, ...)
{
	va_list	args;
	int		printed;

	va_start(args, format);
	printed = 0;
	while (*format)
	{
		if (*format == '%')	//can be put into init helper func
		{
			format++;
			t_format f = {0};
			parse_flags();
			parse_width();
			parse_prec();
			const t_spec *spec = find_spec(*format);
			if (spec)
				printed += spec->printer(args, &f);
			else
			{
				write(1, format - 1, 1);
				write(1, format, 1);
				printed += 2;
			}
		}
		else
		{
			write(1, format, 1);
			printed++;
		}
		format++;
	}
	va_end(args);
	return (printed);
}
