/* -*- mode: c; -*- */

/* ========================================================================= */

#include "battle.h"
#include "player.h"
#include "ptypes.h"
#include "pvp_action.h"
#include "util/test_util.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


/* ------------------------------------------------------------------------- */


  static bool
test_is_valid_action( void )
{
  pvp_player_t p1     = PVP_PLAYER_NULL;
  pvp_player_t p2     = PVP_PLAYER_NULL;
  pvp_battle_t battle = PVP_BATTLE_NULL;

  battle.p1 = & p1;
  battle.p2 = & p2;
  battle.phase = NEUTRAL;

  assert( p1.active_pokemon == 0 );
  p1.team[0].hp = 10;
  p1.team[0].charged_moves[0].energy = 10;
  p1.team[0].charged_moves[1].energy = 10;
  assert( p2.active_pokemon == 0 );
  p2.team[0].hp = 10;
  p2.team[0].charged_moves[0].energy = 10;
  p2.team[0].charged_moves[1].energy = 10;

  /* Waiting is always allowed */
  expect( is_valid_action( true, WAIT, & battle ) == true );
  expect( is_valid_action( false, WAIT, & battle ) == true );
  /* Fast attacking is permitted because of `NEUTRAL' phase */
  expect( is_valid_action( true, FAST, & battle ) == true );
  expect( is_valid_action( false, FAST, & battle ) == true );
  /* Not enough energy */
  expect( is_valid_action( true, CHARGED1, & battle ) == false );
  expect( is_valid_action( false, CHARGED1, & battle ) == false );
  expect( is_valid_action( true, CHARGED2, & battle ) == false );
  expect( is_valid_action( false, CHARGED2, & battle ) == false );
  /* Other pokemon have 0 hp, so switching is not allowed */
  expect( is_valid_action( true, SWITCH1, & battle ) == false );
  expect( is_valid_action( false, SWITCH1, & battle ) == false );
  expect( is_valid_action( true, SWITCH2, & battle ) == false );
  expect( is_valid_action( false, SWITCH2, & battle ) == false );
  /* Phase is not `SUSPEND_CHARGED' so shielding is not allowed */
  expect( is_valid_action( true, SHIELD, & battle ) == false );
  expect( is_valid_action( false, SHIELD, & battle ) == false );



  return true;
}


/* ------------------------------------------------------------------------- */

  bool
test_battle( void )
{
  bool rsl = true;

  rsl &= do_test( is_valid_action );

  return rsl;
}


/* ------------------------------------------------------------------------- */



/* ========================================================================= */

/* vim: set filetype=c : */
