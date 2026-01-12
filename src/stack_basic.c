#include "stack.h"
#include <stdlib.h>

t_stack	*ft_new_stack(void)
{
	t_stack	*new_stack = (t_stack	*)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->head = NULL;
	new_stack->tail = NULL;
	new_stack->size = 0;
	return (new_stack);
}
void ft_destroy_stack(t_stack *stack)
{
    t_node	*tmp;

    if (!stack)
        return ;
    while (stack->head)
    {
        tmp = stack->head;
        stack->head = stack->head->next;
        ft_destroy_node(tmp);
    }
    free(stack);
}

void	ft_push_top(t_stack	*stack, t_node	*node)
{
	if (!stack || !node)
		return ;
	node->prev = NULL;
	node->next = stack->head;
	if (stack->head)
		stack->head->prev = node;
	else
		stack->tail = node;
	stack->head = node;
    stack->size++;
}

void	ft_push_bottom(t_stack	*stack, t_node	*node)
{
	if (!stack || !node)
		return ;
	node->prev = stack->tail;
	node->next = NULL;
	if (stack->tail)
        stack->tail->next = node;
    else
        stack->head = node;
	stack->tail = node;
	stack->size++;
}
t_node	*ft_pop_top(t_stack	*stack);
t_node	*ft_pop_bottom(t_stack	*stack);
