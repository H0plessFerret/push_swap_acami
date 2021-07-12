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
#include <stdlib.h>

int	main(int argc, const char **argv)
{
	t_env		env;
	//int64_t		action_count;
	//t_dCList	*action_iter;

	initEnv(&env);
	parseInput(&env, argc, argv);
	printf("A:\n");
	printDCList(env.a_head);
	printf("\nB:\n");
	printDCList(env.b_head);
	/*
	action_iter = env.actions->next;
	action_count = 1;
	while (action_iter != env.actions)
	{
		++action_count;
		action_iter = action_iter->next;
	}
	printf("\nActions: %lld", action_count);
	*/
	printf("\n");
	clearEnv(&env);
	exit (0);
}
