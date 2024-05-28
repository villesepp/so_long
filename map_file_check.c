#include "so_long.h"
#include <stdio.h> // delete

int	map_file_check(char *p)
{
    int len;
    int fd;

	len = ft_strlen(p);
	if (len < 5)
	{
		return (-15);
	}
   	if (len >= 5)
    	if ((p[len - 1] == 'r' && p[len - 2] == 'e') && (p[len - 3] == 'b' && p[len - 4] == '.'))
		{
			fd = open(p, O_RDONLY);
			if (fd == -1)
			{
				return (-16);
			}
		}
	return (0);
}
