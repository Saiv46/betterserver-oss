#ifndef PLAYER_H
#define PLAYER_H
#include <CMath.h>
#include <Packet.h>
#include <io/Time.h>
#include <stdint.h>

typedef enum
{
	PLAYER_NONE = 0,
	PLAYER_ESCAPED = 0x1 << 0,
	PLAYER_DEAD = 0x1 << 1,
	PLAYER_DEMONIZED = 0x1 << 2,
	PLAYER_REVIVED = 0x1 << 3,
	PLAYER_CANTREVIVE = 0x1 << 4,
	PLAYER_LEFT = 0x1 << 5,
	PLAYER_KILLER = 0x1 << 6
} PlayerFlags;

typedef struct
{
	double	  timeout;
	TimeStamp last_packet;
	double	  attack_timer;
	TimeStamp last_attack;
	double	  ping_total;
	double	  ping_timer;
	TimeStamp last_rings;
	double	  death_timer;
	double	  revival;
	uintptr_t data[4]; /* Can be used as pointer/data field */
	struct
	{
		double	 survive_time;
		double	 danger_time;
		double	 camp_time;
		double	 braindead_time;
		bool	 brain_damage;
		uint16_t stun_time;
		uint16_t stuns;
		uint16_t hp_restored;
		uint16_t rings;
		uint16_t damage;
		uint16_t damage_taken;
		uint16_t kills;
	} stats;
	uint32_t	chunk;
	PlayerFlags flags;
	Vector2		start_pos;
	Vector2		pos;
	uint16_t	revival_init[5]; // An array for 5 player IDs
	uint16_t	errors;			 // Used as tracker for errors like lag/etc
	uint16_t	ping_last;
	uint16_t	rings;
	uint16_t	heal_rings;
	uint8_t		ex_teleport;
	uint8_t		mod_tool_timer;
	uint8_t		state;
	uint8_t		death_timer_sec;
	bool		ready;
	bool		mod_tool;
	bool		is_attacking;
} Player;

#define SET_FLAG(x, flag) x |= (flag)
#define DEL_FLAG(x, flag) x = x & ~(flag)

struct Server;
struct PeerData;
bool player_add_error(struct Server* server, struct PeerData* v, uint16_t by);
void player_check_zone(struct Server* server, struct PeerData* v);

#endif
