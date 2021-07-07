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
	t_actionList	action_list;

	env.actions = &action_list;
	initEnv(&env);
	parseInput(&(env.a_head), argc, argv);
	clearEnv(&env);
	return (0);
}
