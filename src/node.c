#include "stack.h"
#include <stdlib.h>

t_node	*ft_new_node(int data)
{
	t_node	*new_node = (t_node	*)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_destroy_node(t_node	*node)
{
	if (node)
		free(node);
}

