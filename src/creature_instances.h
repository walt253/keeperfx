/******************************************************************************/
// Free implementation of Bullfrog's Dungeon Keeper strategy game.
/******************************************************************************/
/** @file creature_instances.h
 *     Header file for creature_instances.c.
 * @par Purpose:
 *     creature_instances functions.
 * @par Comment:
 *     Just a header file - #defines, typedefs, function prototypes etc.
 * @author   Tomasz Lis
 * @date     11 Mar 2010 - 12 May 2010
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#ifndef DK_CRTRINSTANCE_H
#define DK_CRTRINSTANCE_H

#include "globals.h"
#include "creature_control.h"
#include "bflib_basics.h"
#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/
enum CreatureInstances {
    CrInst_NULL = 0,
    CrInst_SWING_WEAPON_SWORD,
    CrInst_SWING_WEAPON_FIST,
    CrInst_ESCAPE,
    CrInst_FIRE_ARROW,
    CrInst_FIREBALL, // 5
    CrInst_FIRE_BOMB,
    CrInst_FREEZE,
    CrInst_ARMOUR,
    CrInst_LIGHTNING,
    CrInst_REBOUND, // 10
    CrInst_HEAL,
    CrInst_POISON_CLOUD,
    CrInst_INVISIBILITY,
    CrInst_TELEPORT,
    CrInst_SPEED, // 15
    CrInst_SLOW,
    CrInst_DRAIN,
    CrInst_FEAR,
    CrInst_MISSILE,
    CrInst_NAVIGATING_MISSILE, // 20
    CrInst_FLAME_BREATH,
    CrInst_WIND,
    CrInst_LIGHT,
    CrInst_FLY,
    CrInst_SIGHT, // 25
    CrInst_GRENADE,
    CrInst_HAILSTORM,
    CrInst_WORD_OF_POWER,
    CrInst_FART,
    CrInst_DIG, // 30
    CrInst_PRETTY_PATH,
    CrInst_DESTROY_AREA,
    CrInst_TUNNEL,
    CrInst_CELEBRATE_SHORT,
    CrInst_REINFORCE, // 35
    CrInst_EAT,
    CrInst_ATTACK_ROOM_SLAB,
    CrInst_DAMAGE_WALL,
    CrInst_FIRST_PERSON_DIG,
    CrInst_LIZARD, // 40
    CrInst_CAST_SPELL_DISEASE,
    CrInst_CAST_SPELL_CHICKEN,
    CrInst_CAST_SPELL_TIME_BOMB,
    CrInst_MOAN,
    CrInst_TORTURED, // 45
    CrInst_TOKING,
    CrInst_RELAXING,
    CrInst_FAMILIAR,
    CrInst_SUMMON, // 49
    //CrInst_CAST_SPELL_GROUP,
    CrInst_LISTEND,
};

/******************************************************************************/
#pragma pack(1)

struct Thing;

typedef long (*Creature_Instf_Func)(struct Thing *, long *);

struct InstanceInfo {
    TbBool instant;
    long time;
    long fp_time;
    long action_time;
    long fp_action_time;
    long reset_time;
    long fp_reset_time;
    unsigned char graphics_idx;
    unsigned long flags;
    short force_visibility;
    unsigned char primary_target;
    unsigned char func_idx;
    long func_params[2];
    long range_min;
    long range_max;
    long symbol_spridx;
    short tooltip_stridx;
    unsigned char priority;
};

/******************************************************************************/

#pragma pack()
/******************************************************************************/
extern const struct NamedCommand creature_instances_func_type[];
extern Creature_Instf_Func creature_instances_func_list[];
/******************************************************************************/
long instf_attack_room_slab(struct Thing *creatng, long *param);
long instf_creature_cast_spell(struct Thing *creatng, long *param);
long instf_creature_fire_shot(struct Thing *creatng, long *param);
long instf_damage_wall(struct Thing *creatng, long *param);
long instf_destroy(struct Thing *creatng, long *param);
long instf_dig(struct Thing *creatng, long *param);
long instf_eat(struct Thing *creatng, long *param);
long instf_fart(struct Thing *creatng, long *param);
long instf_first_person_do_imp_task(struct Thing *creatng, long *param);
long instf_pretty_path(struct Thing *creatng, long *param);
long instf_reinforce(struct Thing *creatng, long *param);
long instf_tortured(struct Thing *creatng, long *param);
long instf_tunnel(struct Thing *creatng, long *param);

const struct NamedCommand creature_instances_func_type[] = {
  {"attack_room_slab",         1},
  {"creature_cast_spell",      2},
  {"creature_fire_shot",       3},
  {"creature_damage_wall",     4},
  {"creature_destroy",         5},
  {"creature_dig",             6},
  {"creature_eat",             7},
  {"creature_fart",            8},
  {"first_person_do_imp_task", 9},
  {"creature_pretty_path",     10},
  {"creature_reinforce",       11},
  {"creature_tortured",        12},
  {"creature_tunnel",          13},
  {"none",                     14},
  {NULL,                       0},
};

Creature_Instf_Func creature_instances_func_list[] = {
  NULL,
  instf_attack_room_slab,
  instf_creature_cast_spell,
  instf_creature_fire_shot,
  instf_damage_wall,
  instf_destroy,
  instf_dig,
  instf_eat,
  instf_fart,
  instf_first_person_do_imp_task,
  instf_pretty_path, //[10]
  instf_reinforce,
  instf_tortured,
  instf_tunnel,
  NULL,
  NULL,
};

enum creature_instances_func {
  CrInstFn_none = 0,
  CrInstFn_attack_room_slab = 1,
  CrInstFn_creature_cast_spell = 2,
  CrInstFn_creature_fire_shot = 3,
  CrInstFn_damage_wall = 4,
  CrInstFn_destroy = 5,
  CrInstFn_dig = 6,
  CrInstFn_eat = 7,
  CrInstFn_fart = 8,
  CrInstFn_first_person_do_imp_tasK = 9,
  CrInstFn_pretty_path = 10,
  CrInstFn_reinforce = 11,
  CrInstFn_tortured = 12,
  CrInstFn_tunnel = 13,
};

/******************************************************************************/
/** Returns creature instance info structure for given instance index. */
#define creature_instance_info_get(inst_idx) creature_instance_info_get_f(inst_idx,__func__)
struct InstanceInfo *creature_instance_info_get_f(CrInstance inst_idx,const char *func_name);
void process_creature_instance(struct Thing *thing);
long process_creature_self_spell_casting(struct Thing* thing);

TbBool creature_instance_info_invalid(const struct InstanceInfo *inst_inf);
TbBool creature_instance_is_available(const struct Thing *thing, CrInstance inum);

TbBool creature_choose_first_available_instance(struct Thing *thing);
void creature_increase_available_instances(struct Thing *thing);
TbBool creature_has_ranged_weapon(const struct Thing *thing);
TbBool creature_has_disarming_weapon(const struct Thing* creatng);
TbBool creature_has_ranged_object_weapon(const struct Thing *creatng);
TbBool creature_has_quick_range_weapon(const struct Thing *creatng);

int creature_instance_get_available_pos_for_id(struct Thing *thing, CrInstance req_inst_id);
int creature_instance_get_available_number_for_pos(struct Thing *thing, int req_avail_pos);
CrInstance creature_instance_get_available_id_for_pos(struct Thing *thing, int req_avail_pos);

TbBool instance_draws_possession_swipe(CrInstance inum);

void delay_teleport(struct Thing *creatng);
void delay_heal_sleep(struct Thing *creatng);
/******************************************************************************/
#ifdef __cplusplus
}
#endif
#endif
