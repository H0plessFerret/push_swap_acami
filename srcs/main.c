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

int	main(int argc, const char **argv)
{
	t_env			env;

	initEnv(&env);
	parseInput(&(env.a_head), argc, argv);
	pb(&env);
	printf("\n");
	printDCList(env.a_head);
	printf("\n");
	printDCList(env.b_head);
	printf("\n");
	clearEnv(&env);
	return (0);
}
