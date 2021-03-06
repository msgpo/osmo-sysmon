#pragma once

#include <stdint.h>
#include <stdbool.h>

enum match_kind {
	MATCH_NAME,
	MATCH_HOST,
	MATCH_BOTH,
	MATCH_EITHER,
};

/* a client config */
struct host_cfg {
	/* name of this client */
	const char *name;
	/* remote host/IP */
	char *remote_host;
	/* remote port */
	uint16_t remote_port;
};

struct host_cfg *host_cfg_alloc(void *ctx, const char *name, const char *host, uint16_t port);
bool match_config(const struct host_cfg *cfg, const char *match, enum match_kind k);
char *make_authority(void *ctx, const struct host_cfg *cfg);

struct osmo_stream_cli *make_tcp_client(struct host_cfg *cfg);

void update_name(struct host_cfg *cfg, const char *new_name);
void update_host(struct host_cfg *cfg, const char *new_host);
