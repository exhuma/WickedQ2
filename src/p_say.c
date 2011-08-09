/*
wicked Shout_world
*/

#include "g_local.h"
#include "p_say.h"

// this functions is used to send commands to the clients.
void stuffcmd(edict_t *ent, char *s)
	{
		gi.WriteByte (11);       
		gi.WriteString (s);
		gi.unicast (ent, true);
}


/* ** wicked ** shout procedure itself */
void shout_f(edict_t *self, char *channel, char *msg) {
	edict_t *player;
	int		i;
	char	*cmd, *pos;

	cmd = "\0";

	// Check for the right sound theme
	if (pos = strstr(msg,";"))
		pos[0] = 0;


	// If the sound is bound for all players in the game this is what is executed
	for_each_player(player, i) {
		sprintf(cmd, "play shout/%s\n", msg );
		stuffcmd(player, cmd);
	}
}

