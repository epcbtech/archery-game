#include "ar_game_arrow.h"

#include "ar_game_archery.h"
#include "scr_archery_game.h"

ar_game_arrow_t arrow[MAX_NUM_ARROW];

#define AR_GAME_ARROW_SETUP()  \
do { \
    for (uint8_t i = 0; i < MAX_NUM_ARROW; i++) { \
        arrow[i].x = 0; \
        arrow[i].y = 0; \
        arrow[i].visible = BLACK; \
        arrow[i].action_image = 1; \
    } \
} while (0);

#define AR_GAME_ARROW_RUN() \
do { \
    for (uint8_t i = 0; i < MAX_NUM_ARROW; i++) { \
        if (arrow[i].visible == WHITE) { \
            arrow[i].x += settingsetup.arrow_speed; \
            if (arrow[i].x == MAX_AXIS_X_ARROW) { \
                arrow[i].visible = BLACK; \
                arrow[i].x = 0; \
                settingsetup.num_arrow++; \
            } \
        } \
    } \
} while(0);

#define AR_GAME_ARROW_SHOOT() \
do { \
    for (uint8_t i = 0; i < MAX_NUM_ARROW; i++) { \
        if (arrow[i].visible == BLACK && settingsetup.num_arrow != 0) { \
            settingsetup.num_arrow--; \
            arrow[i].visible = WHITE; \
            arrow[i].y = archery.y - 5; \
            BUZZER_PlayTones(tones_cc); \
            break; \
        } \
        else if (settingsetup.num_arrow == 0) { \
            BUZZER_PlayTones(tones_3beep); \
            break; \
        } \
    } \
} while(0);

#define AR_GAME_ARROW_RESET() \
do { \
    for (uint8_t i = 0; i < MAX_NUM_ARROW; i++) { \
        arrow[i].x = 0; \
        arrow[i].y = 0; \
        arrow[i].visible = BLACK; \
        arrow[i].action_image = 1; \
    } \
} while (0);

void ar_game_arrow_handle(ak_msg_t* msg) {
    switch (msg->sig) {
    case AR_GAME_ARROW_SETUP: {
        APP_DBG_SIG("AR_GAME_ARROW_SETUP\n");
        AR_GAME_ARROW_SETUP();
    }
        break;

    case AR_GAME_ARROW_RUN: {
        APP_DBG_SIG("AR_GAME_ARROW_RUN\n");
        AR_GAME_ARROW_RUN();
    }
        break;

    case AR_GAME_ARROW_SHOOT: {
        APP_DBG_SIG("AR_GAME_ARROW_SHOOT\n");
        AR_GAME_ARROW_SHOOT();
    }
        break;

    case AR_GAME_ARROW_RESET: {
        APP_DBG_SIG("AR_GAME_ARROW_RESET\n");
        AR_GAME_ARROW_RESET();
    }
        break;

    default:
        break;
    }
}