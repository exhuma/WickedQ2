/*
Wicked Say_World Functions

*/



#define for_each_player(PLAYER,INDEX)\
for(INDEX=1;INDEX<=maxclients->value;INDEX++)\
if ((PLAYER=&g_edicts[i]) && PLAYER->inuse)


void shout_power_f(edict_t *self, char *state);
void shout_f(edict_t *self, char *channel, char *msg);

