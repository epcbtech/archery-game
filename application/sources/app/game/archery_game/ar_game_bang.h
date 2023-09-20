#ifndef __AR_GAME_BANG_H__
#define __AR_GAME_BANG_H__

#include <stdio.h>

#include "fsm.h"
#include "port.h"
#include "message.h"
#include "timer.h"

#include "app.h"
#include "app_dbg.h"
#include "task_list.h"
#include "task_display.h"

#include "scr_archery_game.h"

#define NUM_BANG                 (5)
#define SIZE_BITMAP_BANG_I_X     (15)
#define SIZE_BITMAP_BANG_I_Y     (15)
#define SIZE_BITMAP_BANG_II_X    (10)
#define SIZE_BITMAP_BANG_II_Y    (10)

typedef struct {
    bool visible;
    uint32_t x, y;
    uint8_t action_image;
} ar_game_bang_t;

extern ar_game_bang_t bang[NUM_BANG];

#endif //__AR_GAME_BANG_H__