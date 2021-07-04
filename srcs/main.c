//                    DEBUG FILE!
//                    DEBUG FILE!
//                    DEBUG FILE!
//                    DEBUG FILE!
//                    DEBUG FILE!
//                    DEBUG FILE!
//                    DEBUG FILE!
//                    DEBUG FILE!
//                    DEBUG FILE!
//                    DEBUG FILE!
//                    DEBUG FILE!
//                    DEBUG FILE!
//                    DEBUG FILE!

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_dCList	*head;
	int32_t		count;

	head = NULL;
	count = 1;
	while (count < argc)
	{
		pushDCList(&head, atoi(argv[count]), false);
		++count;
	}
	printDCList(head);
	clearDCList(&head);
	return (0);
}
