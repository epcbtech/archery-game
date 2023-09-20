#include "ar_game_archery.h"

ar_game_archery_t archery;
static uint32_t archery_y = AXIS_Y_ARCHERY;

#define AR_GAME_ARCHERY_SETUP() \
do { \
    archery.x = AXIS_X_ARCHERY; \
    archery.y = AXIS_Y_ARCHERY; \
    archery.visible = WHITE; \
    archery.action_image = 1; \
} while (0);

#define AR_GAME_ARCHERY_UP() \
do { \
    archery_y -= STEP_ARCHERY_AXIS_Y; \
    if (archery_y == 0) {archery_y = 10;} \
} while(0);

#define AR_GAME_ARCHERY_DOWN() \
do { \
    archery_y += STEP_ARCHERY_AXIS_Y; \
    if (archery_y > 50) {archery_y = 50;} \
} while(0);

#define AR_GAME_ARCHERY_RESET() \
do { \
    archery.x = AXIS_X_ARCHERY; \
    archery.y = AXIS_Y_ARCHERY; \
    archery.visible = BLACK; \
    archery_y = AXIS_Y_ARCHERY; \
} while(0);

void ar_game_archery_handle(ak_msg_t* msg) {
    switch (msg->sig) {
    case AR_GAME_ARCHERY_SETUP: {
        APP_DBG_SIG("AR_GAME_ARCHERY_SETUP\n");
        AR_GAME_ARCHERY_SETUP();
    }
        break;

    case AR_GAME_ARCHERY_UPDATE: {
        APP_DBG_SIG("AR_GAME_ARCHERY_UPDATE\n");
        archery.y = archery_y;
    }
        break;

    case AR_GAME_ARCHERY_UP: {
        APP_DBG_SIG("AR_GAME_ARCHERY_UP\n");
        AR_GAME_ARCHERY_UP();
    }
        break;

    case AR_GAME_ARCHERY_DOWN: {
        APP_DBG_SIG("AR_GAME_ARCHERY_DOWN\n");
        AR_GAME_ARCHERY_DOWN();
    }
        break;

    case AR_GAME_ARCHERY_RESET: {
        APP_DBG_SIG("AR_GAME_ARCHERY_RESET\n");
        AR_GAME_ARCHERY_RESET();
    }
        break;

    default:
        break;
    }
}