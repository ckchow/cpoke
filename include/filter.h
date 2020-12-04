/* -*- mode: c; -*- */

#ifndef _FILTER_H
#define _FILTER_H

/* ========================================================================== */

#include "pokemon.h"


/* -------------------------------------------------------------------------- */

/**
 * Filters/predicates to narrow rosters and gm_stores.
 */
typedef bool (*base_mon_pred_fn)( base_pokemon_t *, void * );
typedef bool (*roster_mon_pred_fn)( roster_pokemon_t *, void * );
typedef bool (*pdex_mon_pred_fn)( pdex_mon_t *, void * );


/* -------------------------------------------------------------------------- */

  static inline bool
pdex_mon_region_p( pdex_mon_t * mon, region_t * reg )
{
  return get_region( mon->dex_number ) == reg;
}

  static bool
pdex_mon_region_pred( pdex_mon_t * mon, void * reg )
{
  return pdex_mon_region_p( mon, (region_t *) reg );
}

  static inline bool
base_mon_region_p( base_pokemon_t * mon, region_t * reg )
{
  return pdex_mon_region_p( mon->pdex_mon, reg );
}

  static bool
base_mon_region_pred( base_pokemon_t * mon, void * reg )
{
  return base_mon_region_p( mon, (region_t *) reg );
}


/* -------------------------------------------------------------------------- */

  static inline bool
pdex_mon_family_p( pdex_mon_t * mon, uint16_t family )
{
  return mon->family == family;
}

static bool
pdex_mon_family_pred( pdex_mon_t * mon, void * familyp )
{
  return pdex_mon_family_p( mon, *( (uint16_t *) familyp ) );
}

  static inline bool
base_mon_family_p( base_pokemon_t * mon, uint16_t family )
{
  return pdex_mon_family_p( mon->pdex_mon, family );
}

  static bool
base_mon_family_pred( base_pokemon_t * mon, void * familyp )
{
  return base_mon_family_p( mon, *( (uint16_t *) familyp ) );
}


/* -------------------------------------------------------------------------- */

  static inline bool
pdex_mon_tags_p( pdex_mon_t * mon, pdex_tag_mask_t tags )
{
  return  !! ( mon->tags & tags );
}

  static bool
pdex_mon_tags_pred( pdex_mon_t * mon, void * tagsp )
{
  return pdex_mon_tags_p( mon, *( (pdex_tag_mask_t *) tagsp ) );
}

  static inline bool
base_mon_tags_p( base_pokemon_t * mon, pdex_tag_mask_t tags )
{
  return pdex_mon_tags_p( mon->pdex_mon, tags );
}

  static bool
base_mon_tags_pred( base_pokemon_t * mon, void * tagsp )
{
  return base_mon_tags_p( mon, *( (pdex_tag_mask_t *) tagsp ) );
}


/* -------------------------------------------------------------------------- */

  static inline bool
pdex_mon_types_any_p( pdex_mon_t * mon, ptype_mask_t types )
{
  return !! ( mon->types & types );
}

  static bool
pdex_mon_types_any_pred( pdex_mon_t * mon, void * typesp )
{
  return pdex_mon_types_any_p( mon, *( (ptype_mask_t *) typesp ) );
}

  static inline bool
base_mon_types_any_p( base_pokemon_t * mon, ptype_mask_t types )
{
  return pdex_mon_types_any_p( mon->pdex_mon, types );
}

  static bool
base_mon_types_any_pred( base_pokemon_t * mon, void * typesp )
{
  return base_mon_types_any_p( mon, *( (ptype_mask_t *) typesp ) );
}


/* -------------------------------------------------------------------------- */

  static inline bool
pdex_mon_types_all_p( pdex_mon_t * mon, ptype_mask_t types )
{
  return types <= ( mon->types & types )
}

  static bool
pdex_mon_types_all_pred( pdex_mon_t * mon, void * typesp )
{
  return pdex_mon_types_all_p( mon, *( (ptype_mask_t *) typesp ) );
}

  static inline bool
base_mon_types_all_p( base_pokemon_t * mon, ptype_mask_t types )
{
  return pdex_mon_types_all_p( mon->pdex_mon, types );
}

  static bool
base_mon_types_all_pred( base_pokemon_t * mon, void * typesp )
{
  return base_mon_types_all_p( mon, *( (ptype_mask_t *) typesp ) );
}


/* -------------------------------------------------------------------------- */



/* ========================================================================== */

#endif /* filter.h */

/* vim: set filetype=c : */
