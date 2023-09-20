#ifndef __AR_GAME_BORDER_H__
#define __AR_GAME_BORDER_H__

#include <stdio.h>

#include "fsm.h"
#include "port.h"
#include "message.h"
#include "timer.h"

#include "app.h"
#include "app_dbg.h"
#include "task_list.h"
#include "task_display.h"

#include "buzzer.h"
#include "scr_archery_game.h"

#define AXIS_X_BORDER           (15)
#define AXIS_Y_BORDER_ON        (2)
#define AXIS_Y_BORDER_UNDER     (52)

typedef struct {
    bool visible;
    uint32_t x, y;
    uint8_t action_image;
} ar_game_border_t;

extern uint32_t ar_game_score;
extern ar_game_border_t border;

#endif //__AR_GAME_BORDER_H__