/*********************************************************
 * wickedweapons.c      - Source file containing         *
 *                        declarations of wicked weapon  *
 *                        stuff                          *
 *********************************************************/

#include "g_local.h"

/*********************************************************
 * Cluster_Explode is a copy of Grenade_Explode moved    *
 * here in order to get wickedweapons.c running          *
 * correctly haven't got a workaround yet... :(          *
 *********************************************************/
static void Cluster_Explode (edict_t *ent)
//void Grenade_Explode (edict_t *ent)
{
	vec3_t		origin;
	int			mod;

	if (ent->owner->client)
		PlayerNoise(ent->owner, ent->s.origin, PNOISE_IMPACT);

	//FIXME: if we are onground then raise our Z just a bit since we are a point?
	if (ent->enemy)
	{
		float	points;
		vec3_t	v;
		vec3_t	dir;

		VectorAdd (ent->enemy->mins, ent->enemy->maxs, v);
		VectorMA (ent->enemy->s.origin, 0.5, v, v);
		VectorSubtract (ent->s.origin, v, v);
		points = ent->dmg - 0.5 * VectorLength (v);
		VectorSubtract (ent->enemy->s.origin, ent->s.origin, dir);
		if (ent->spawnflags & 1)
			mod = MOD_HANDGRENADE;
		else
			mod = MOD_GRENADE;
		T_Damage (ent->enemy, ent, ent->owner, dir, ent->s.origin, vec3_origin, (int)points, (int)points, DAMAGE_RADIUS, mod);
	}

	if (ent->spawnflags & 2)
		mod = MOD_HELD_GRENADE;
	else if (ent->spawnflags & 1)
		mod = MOD_HG_SPLASH;
	else
		mod = MOD_G_SPLASH;
	T_RadiusDamage(ent, ent->owner, ent->dmg, ent->enemy, ent->dmg_radius, mod);

	VectorMA (ent->s.origin, -0.02, ent->velocity, origin);
	gi.WriteByte (svc_temp_entity);
	if (ent->waterlevel)
	{
		if (ent->groundentity)
			gi.WriteByte (TE_GRENADE_EXPLOSION_WATER);
		else
			gi.WriteByte (TE_ROCKET_EXPLOSION_WATER);
	}
	else
	{
		if (ent->groundentity)
			gi.WriteByte (TE_GRENADE_EXPLOSION);
		else
			gi.WriteByte (TE_ROCKET_EXPLOSION);
	}
	gi.WritePosition (origin);
	gi.multicast (ent->s.origin, MULTICAST_PHS);

	G_FreeEdict (ent);
}

/*********************************************************
 * Cluster_Touch is a copy of Grenade_Touch moved here   *
 * in order to get wickedweapons.c running correctly     *
 * haven't got a workaround yet... :(                    *
 *********************************************************/
static void Cluster_Touch (edict_t *ent, edict_t *other, cplane_t *plane, csurface_t *surf)
{
	if (other == ent->owner)
		return;

	if (surf && (surf->flags & SURF_SKY))
	{
		G_FreeEdict (ent);
		return;
	}

	if (!other->takedamage)
	{
		if (ent->spawnflags & 1)
		{
			if (random() > 0.5)
				gi.sound (ent, CHAN_VOICE, gi.soundindex ("weapons/hgrenb1a.wav"), 1, ATTN_NORM, 0);
			else
				gi.sound (ent, CHAN_VOICE, gi.soundindex ("weapons/hgrenb2a.wav"), 1, ATTN_NORM, 0);
		}
		else
		{
			gi.sound (ent, CHAN_VOICE, gi.soundindex ("weapons/grenlb1b.wav"), 1, ATTN_NORM, 0);
		}
		return;
	}

	ent->enemy = other;
	Cluster_Explode (ent);
}

/* ** wicked ** * jump grenade -- think
=================
Jumpgen_Think
=================
*/
void Jumpgen_Think (edict_t *ent)
{
	edict_t		*blip = NULL;
	vec3_t		dir, up;
	
	while ((blip = findradius(blip, ent->s.origin, 50)) != NULL){
		if (!strcmp(blip->classname, "player")){
			VectorCopy( dir, blip->velocity ); 
			AngleVectors (dir, NULL, NULL, up);
			blip->takedamage = DAMAGE_NO;
			VectorMA(blip->velocity, 1000, up, blip->velocity);
			blip->takedamage = DAMAGE_YES;
			G_FreeEdict (ent);
		}
	}
	ent->think = Jumpgen_Think;
	ent->nextthink = level.time + .1;

}

/* ** wicked ** fire_pipebomb declaration*

=================
fire_pipebomb
=================
*/
void Pipe_Think (edict_t *ent)
{
	vec3_t		origin;
	int			mod;

	
	if (ent->owner->client)
		PlayerNoise(ent->owner, ent->s.origin, PNOISE_IMPACT);


	//FIXME: if we are onground then raise our Z just a bit since we are a point?
	if (ent->enemy)
	{
		float	points;
		vec3_t	v;
		vec3_t	dir;

		VectorAdd (ent->enemy->mins, ent->enemy->maxs, v);
		VectorMA (ent->enemy->s.origin, 0.5, v, v);
		VectorSubtract (ent->s.origin, v, v);
		points = ent->dmg - 0.5 * VectorLength (v);
		VectorSubtract (ent->enemy->s.origin, ent->s.origin, dir);
		if (ent->spawnflags & 1)
			mod = MOD_HANDGRENADE;
		else
			mod = MOD_GRENADE;
		T_Damage (ent->enemy, ent, ent->owner, dir, ent->s.origin, vec3_origin, (int)points, (int)points, DAMAGE_RADIUS, mod);
	}

	if (ent->spawnflags & 2)
		mod = MOD_HELD_GRENADE;
	else if (ent->spawnflags & 1)
		mod = MOD_HG_SPLASH;
	else
		mod = MOD_PIPE_SPLASH;
	T_RadiusDamage(ent, ent->owner, ent->dmg, ent->enemy, ent->dmg_radius, mod);

	VectorMA (ent->s.origin, -0.02, ent->velocity, origin);
	gi.WriteByte (svc_temp_entity);
	if (ent->waterlevel)
	{
		if (ent->groundentity)
			gi.WriteByte (TE_GRENADE_EXPLOSION_WATER);
		else
			gi.WriteByte (TE_ROCKET_EXPLOSION_WATER);
	}
	else
	{
		if (ent->groundentity)
			gi.WriteByte (TE_GRENADE_EXPLOSION);
		else
			gi.WriteByte (TE_ROCKET_EXPLOSION);
	}
	gi.WritePosition (origin);
	gi.multicast (ent->s.origin, MULTICAST_PHS);
	

	G_FreeEdict (ent);
}

/* ** wicked ** Cluster Explode *
=================
Cluster Explode
    divide cluster into 5 new clusters
=================
*/
void Cluster_Spread1 (edict_t *ent)
{
	vec3_t   origin;
	int      mod;

	//Sean added these 4 vectors

	vec3_t   subCluster1;
	vec3_t   subCluster2;
	vec3_t   subCluster3;
	vec3_t   subCluster4;
	vec3_t   subCluster5;

	mod = MOD_CLUSTER;
	
	if (ent->owner->client)
		PlayerNoise(ent->owner, ent->s.origin, PNOISE_IMPACT);

	//FIXME: if we are onground then raise our Z just a bit since we are a point?
	T_RadiusDamage(ent, ent->owner, ent->dmg, NULL, ent->dmg_radius, mod);

	VectorMA (ent->s.origin, -0.02, ent->velocity, origin);
	gi.WriteByte (svc_temp_entity);
	if (ent->waterlevel)
		{
		if (ent->groundentity)
			gi.WriteByte (TE_GRENADE_EXPLOSION_WATER);
		else
			gi.WriteByte (TE_ROCKET_EXPLOSION_WATER);
		}
	else
		{
		if (ent->groundentity)
			gi.WriteByte (TE_GRENADE_EXPLOSION);
		else
			gi.WriteByte (TE_ROCKET_EXPLOSION);
		}
	gi.WritePosition (origin);
	gi.multicast (ent->s.origin, MULTICAST_PVS);

	// SumFuka did this bit : give grenades up/outwards velocities
	VectorSet(subCluster1,20,20,20);
	VectorSet(subCluster2,20,-20,20);
	VectorSet(subCluster3,-20,20,20);
	VectorSet(subCluster4,-20,-20,20);
	VectorSet(subCluster5,0,0,0);

	// Sean : explode the four grenades outwards
	fire_cluster2(ent, origin, subCluster1, 100, 15, 1.0, 120);
	fire_cluster2(ent, origin, subCluster2, 100, 15, 1.0, 120);
	fire_cluster2(ent, origin, subCluster3, 100, 15, 1.0, 120);
	fire_cluster2(ent, origin, subCluster4, 100, 15, 1.0, 120);
	fire_cluster2(ent, origin, subCluster5, 120, 2, 1.0, 150);

	G_FreeEdict (ent);
}

/* ** wicked ** Cluster Spread2 *
=================
Cluster Spread2
    divide the new cluster into 5 clusters again
=================
*/
void Cluster_Spread2 (edict_t *ent)
{
	vec3_t   origin;
	int      mod;

	//Sean added these 4 vectors

	vec3_t   grenade1;
	vec3_t   grenade2;
	vec3_t   grenade3;
	vec3_t   grenade4;
	vec3_t   grenade5;

	mod = MOD_CLUSTER;
	
	if (ent->owner->client)
		PlayerNoise(ent->owner, ent->s.origin, PNOISE_IMPACT);

	//FIXME: if we are onground then raise our Z just a bit since we are a point?
	T_RadiusDamage(ent, ent->owner, ent->dmg, NULL, ent->dmg_radius, mod);

	VectorMA (ent->s.origin, -0.02, ent->velocity, origin);
	gi.WriteByte (svc_temp_entity);
	if (ent->waterlevel)
		{
		if (ent->groundentity)
			gi.WriteByte (TE_GRENADE_EXPLOSION_WATER);
		else
			gi.WriteByte (TE_ROCKET_EXPLOSION_WATER);
		}
	else
		{
		if (ent->groundentity)
			gi.WriteByte (TE_GRENADE_EXPLOSION);
		else
			gi.WriteByte (TE_ROCKET_EXPLOSION);
		}
	gi.WritePosition (origin);
	gi.multicast (ent->s.origin, MULTICAST_PVS);

	// SumFuka did this bit : give grenades up/outwards velocities
	//VectorSet(grenade1, 10, 20,  0);
	VectorSet(grenade1, 30,  0, 30);
	VectorSet(grenade2,  0,-30, 30);
	VectorSet(grenade3,-30,  0, 30);
	VectorSet(grenade4,  0, 30, 30);
	VectorSet(grenade5,  0,  0, 30);

	// Sean : explode the four grenades outwards
	fire_cluster3(ent, origin, grenade1, 80,  8, 1.0, 120);
	fire_cluster3(ent, origin, grenade2, 80,  8, 1.0, 120);
	fire_cluster3(ent, origin, grenade3, 80,  8, 1.0, 120);
	fire_cluster3(ent, origin, grenade4, 80,  8, 1.0, 120);
	fire_cluster3(ent, origin, grenade5, 100, 0, 1.0, 150);

	G_FreeEdict (ent);
}

/* ** wicked ** Pipe */
void fire_pipe (edict_t *self, vec3_t start, vec3_t aimdir, int damage, int speed, float timer, float damage_radius)
{
	edict_t	*pipe;
	vec3_t	dir;
	vec3_t	forward, right, up;

	vectoangles (aimdir, dir);
	AngleVectors (dir, forward, right, up);

	pipe = G_Spawn();
	VectorCopy (start, pipe->s.origin);
	VectorScale (aimdir, speed, pipe->velocity);
	VectorMA (pipe->velocity, 200 + crandom() * 10.0, up, pipe->velocity);
	VectorMA (pipe->velocity, crandom() * 10.0, right, pipe->velocity);
	VectorSet (pipe->avelocity, 300, 300, 300);
	pipe->movetype = MOVETYPE_BOUNCE;
	pipe->clipmask = MASK_SHOT;
	pipe->solid = SOLID_BBOX;
	pipe->s.effects |= EF_GRENADE;
	VectorClear (pipe->mins);
	VectorClear (pipe->maxs);
	pipe->s.modelindex = gi.modelindex ("models/objects/pipe/tris.md2");
	pipe->owner = self;
	//pipe->nextthink = level.time + 60;
	pipe->nextthink = level.time + 0.25;
	pipe->think = Jumpgen_Think;
	pipe->dmg = damage;
	pipe->dmg_radius = damage_radius;
	pipe->classname = "detpipe";
	pipe->s.renderfx = RF_FULLBRIGHT;
    pipe->s.effects |= EF_COLOR_SHELL;
    pipe->s.effects |= EF_BLASTER;
    pipe->s.renderfx |= RF_SHELL_DOUBLE;

	gi.linkentity (pipe);
}


/* ** wicked ** fire_cluster declaration */
void fire_cluster (edict_t *self, vec3_t start, vec3_t aimdir, int damage, int speed, float timer, float damage_radius)
{
	edict_t	*cluster;
	vec3_t	dir;
	vec3_t	forward, right, up;

	vectoangles (aimdir, dir);
	AngleVectors (dir, forward, right, up);

	cluster = G_Spawn();
	VectorCopy (start, cluster->s.origin);
	VectorScale (aimdir, speed, cluster->velocity);
	VectorMA (cluster->velocity, 200 + crandom() * 10.0, up, cluster->velocity);
	VectorMA (cluster->velocity, crandom() * 10.0, right, cluster->velocity);
	VectorSet (cluster->avelocity, 300, 300, 300);
	cluster->movetype = MOVETYPE_BOUNCE;
	cluster->clipmask = MASK_SHOT;
	cluster->solid = SOLID_BBOX;
	cluster->s.effects |= EF_GRENADE;
	VectorClear (cluster->mins);
	VectorClear (cluster->maxs);
	cluster->s.modelindex = gi.modelindex ("models/objects/cluster/tris.md2");
	cluster->owner = self;
	cluster->nextthink = level.time + 1.5;
	cluster->think = Cluster_Spread1;
	cluster->dmg = damage;
	cluster->dmg_radius = damage_radius;
	cluster->classname = "detcluster";
	cluster->s.renderfx = RF_FULLBRIGHT;

	gi.linkentity (cluster);
}

/* ** wicked ** Fire_cluster2 */
void fire_cluster2 (edict_t *self, vec3_t start, vec3_t aimdir, int damage, int speed, float timer, float damage_radius)
{
	edict_t	*cluster;
	vec3_t	dir;
	vec3_t	forward, right, up;

	vectoangles (aimdir, dir);
	AngleVectors (dir, forward, right, up);

	cluster = G_Spawn();
	VectorCopy (start, cluster->s.origin);
	VectorScale (aimdir, speed, cluster->velocity);
	VectorMA (cluster->velocity, 200 + crandom() * 10.0, up, cluster->velocity);
	VectorMA (cluster->velocity, crandom() * 10.0, right, cluster->velocity);
	VectorSet (cluster->avelocity, 300, 300, 300);
	cluster->movetype = MOVETYPE_BOUNCE;
	cluster->clipmask = MASK_SHOT;
	cluster->solid = SOLID_BBOX;
	cluster->s.effects |= EF_GRENADE;
	VectorClear (cluster->mins);
	VectorClear (cluster->maxs);
	cluster->s.modelindex = gi.modelindex ("models/objects/cluster2/tris.md2");
	cluster->owner = self;
	cluster->touch = Cluster_Touch;
	cluster->nextthink = level.time + 1;
	cluster->think = Cluster_Spread2;
	cluster->dmg = damage;
	cluster->dmg_radius = damage_radius;
	cluster->classname = "hcluster";
	cluster->spawnflags = 1;
	cluster->s.sound = gi.soundindex("weapons/hgrenc1b.wav");

	if (timer <= 0.0)
		Cluster_Explode (cluster);
	else
	{
		gi.sound (self, CHAN_WEAPON, gi.soundindex ("weapons/hgrent1a.wav"), 1, ATTN_NORM, 0);
		gi.linkentity (cluster);
	}
}

/* ** wicked ** Fire_cluster3 */
void fire_cluster3 (edict_t *self, vec3_t start, vec3_t aimdir, int damage, int speed, float timer, float damage_radius)
{
	edict_t	*cluster;
	vec3_t	dir;
	vec3_t	forward, right, up;

	vectoangles (aimdir, dir);
	AngleVectors (dir, forward, right, up);

	cluster = G_Spawn();
	VectorCopy (start, cluster->s.origin);
	VectorScale (aimdir, speed, cluster->velocity);
	VectorMA (cluster->velocity, 200 + crandom() * 10.0, up, cluster->velocity);
	VectorMA (cluster->velocity, crandom() * 10.0, right, cluster->velocity);
	VectorSet (cluster->avelocity, 300, 300, 300);
	cluster->movetype = MOVETYPE_BOUNCE;
	cluster->clipmask = MASK_SHOT;
	cluster->solid = SOLID_BBOX;
	cluster->s.effects |= EF_GRENADE;
	VectorClear (cluster->mins);
	VectorClear (cluster->maxs);
	cluster->s.modelindex = gi.modelindex ("models/objects/cluster2/tris.md2");
	cluster->owner = self;
	cluster->touch = Cluster_Touch;
	cluster->nextthink = level.time + 1;
	cluster->think = Cluster_Explode;
	cluster->dmg = damage;
	cluster->dmg_radius = damage_radius;
	cluster->classname = "hcluster";
	cluster->spawnflags = 1;
	cluster->s.sound = gi.soundindex("weapons/hgrenc1b.wav");

	if (timer <= 0.0)
		Cluster_Explode (cluster);
	else
	{
		gi.sound (self, CHAN_WEAPON, gi.soundindex ("weapons/hgrent1a.wav"), 1, ATTN_NORM, 0);
		gi.linkentity (cluster);
	}
}
