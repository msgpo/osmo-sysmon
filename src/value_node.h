#pragma once

#include <osmocom/core/linuxlist.h>

/* a single node in the tree of values */
struct value_node {
	/* our element in the parent list */
	struct llist_head list;
	/* the display name */
	const char *name;
	/* additional numeric index (for ifindex matching) */
	int idx;
	/* the value (if any) */
	const char *value;
	/* the children (if value == NULL) */
	struct llist_head children;
};

struct value_node *value_node_add(struct value_node *parent,
				  const char *name, const char *value);
struct value_node *value_node_find(struct value_node *parent, const char *name);
struct value_node *value_node_find_by_idx(struct value_node *parent, int idx);
struct value_node *value_node_find_or_add(struct value_node *parent, const char *name);
void value_node_del(struct value_node *node);
