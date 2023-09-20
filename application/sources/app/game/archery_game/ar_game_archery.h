#ifndef __AR_GAME_ARCHERY_H__
#define __AR_GAME_ARCHERY_H__

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

#define STEP_ARCHERY_AXIS_Y     (10)
#define SIZE_BITMAP_ARCHERY_X   (15)
#define SIZE_BITMAP_ARCHERY_Y   (15)
#define AXIS_X_ARCHERY          (0)
#define AXIS_Y_ARCHERY          (30)

typedef struct {
    bool visible;
    uint32_t x, y;
    uint8_t action_image;
} ar_game_archery_t;

extern ar_game_archery_t archery;

#endif //__AR_GAME_ARCHERY_H__
