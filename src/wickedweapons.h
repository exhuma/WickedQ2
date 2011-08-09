/*********************************************************
 * wickedweapons.h      - Header file containing         *
 *                        definitions of wicked weapon   *
 *                        stuff                          *
 *********************************************************/

void Jumpgen_Think (edict_t *ent);
void Pipe_Think (edict_t *ent);
void Cluster_Spread1 (edict_t *ent);
void Cluster_Spread2 (edict_t *ent);
static void Cluster_Explode (edict_t *ent);
void fire_pipe (edict_t *self, vec3_t start, vec3_t aimdir, int damage, int speed, float timer, float damage_radius);
void fire_cluster (edict_t *self, vec3_t start, vec3_t aimdir, int damage, int speed, float timer, float damage_radius);
void fire_cluster2 (edict_t *self, vec3_t start, vec3_t aimdir, int damage, int speed, float timer, float damage_radius);
void fire_cluster3 (edict_t *self, vec3_t start, vec3_t aimdir, int damage, int speed, float timer, float damage_radius);
