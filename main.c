#include <stdio.h> // delet
#include "so_long.h"

int main (int argc, char *argv[])
{
	int	err;
	char *p;

	if (argc != 2)
	{
		errors(-11);
		return (0);
	}
	p = argv[1];
	err = map_file_check(p);
	if (err < 0)
	{
		errors(err); //edit
		return (0);
	}
	else
		printf(GREEN"Opening: %s\n"RESET, argv[1]); //edit
	return (0);
}
