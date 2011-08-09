/*********************************************************
 * Wicked.c             - Source file containing 
 *                        some usefull stuff
 *
 *
 *	- getlocaltime ( get local time )
 * - shout_world ( shouting in q2 )
 *	- stuffcmd ( ported from q1 )
 *********************************************************/

  
#include "g_local.h"


/* ** wicked ** *****************************************
 * getlocaltime(char * timestr)                         *
 *    puts the local time as formatted string into      *
 *    timestr.                                          *
 ********************************************************/
char * getlocaltime (char * timestr){
	struct tm *ltime;				//localtime
	time_t gmtime;					//time

	time((unsigned long *)&gmtime);
	ltime=localtime(&gmtime);
	Com_sprintf(timestr, sizeof( ltime->tm_hour ) + sizeof(ltime->tm_min) + sizeof(ltime->tm_sec), "%2i:%2i:%2i", ltime->tm_hour, ltime->tm_min, ltime->tm_sec);
}

/* ** wicked ** Teleport me
=================================================================================
Personal Teleporter tutorial
=================================================================================
*/
void teleport_me (edict_t *ent, edict_t*dest){
	int i;
	byte oldMoveState; //exu: movestate before teleporting

	// unlink to make sure player can't possibly interfere with KillBox
	gi.unlinkentity (ent);

	// draw the teleport splash at dest
	gi.WriteByte (svc_temp_entity);// this is a really cool teleporter effect.
	//gi.WriteByte (TE_BOSSTPORT);// since we are moving the player
	gi.WriteByte (TE_BFG_EXPLOSION);
	gi.WritePosition (ent->s.origin);// we cant use the other way to
	gi.multicast (ent->s.origin, MULTICAST_PVS);// write the teleporter splash,
	dest->s.event = EV_PLAYER_TELEPORT;// but we can at the dest

	//move the player
	oldMoveState = ent->client->ps.pmove.pm_flags; //exu: save movestate before teleporting for later use
	ent->client->ps.pmove.pm_flags |= PMF_DUCKED; //exu: duck the player before moving, to ensure that he "fits" into the destination
	VectorCopy (dest->s.origin, ent->s.origin);
	VectorCopy (dest->s.origin, ent->s.old_origin);
	ent->s.origin[2] += 10;

	// clear the velocity and hold them in place briefly
	VectorClear (ent->velocity);
	ent->client->ps.pmove.pm_time = 160>>3;// hold time
	ent->client->ps.pmove.pm_flags |= PMF_TIME_TELEPORT;
	//gi.WriteByte (TE_PLASMA_EXPLOSION);


	// set angles
	for (i=0 ; i<3 ; i++)
		{
		ent->client->ps.pmove.delta_angles[i] = ANGLE2SHORT(dest->s.angles[i] - ent->client->resp.cmd_angles[i]);
		}

	VectorClear (ent->s.angles);
	VectorClear (ent->client->ps.viewangles);
	VectorClear (ent->client->v_angle);

	// kill anything at the destination
	KillBox (ent);
	//ent->client->ps.pmove.pm_flags = oldMoveState; //exu: restore initial movestate

	gi.linkentity (ent);
}

