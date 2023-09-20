#include "ar_game_meteoroid.h"

#include "ar_game_arrow.h"
#include "ar_game_bang.h"
#include "ar_game_border.h"
#include "scr_archery_game.h"

ar_game_meteoroid_t meteoroid[NUM_METEOROIDS];

#define AR_GAME_METEOROID_SETUP() \
do { \
    meteoroid[0].y = AXIS_Y_METEOROID_0; \
    meteoroid[1].y = AXIS_Y_METEOROID_1; \
    meteoroid[2].y = AXIS_Y_METEOROID_2; \
    meteoroid[3].y = AXIS_Y_METEOROID_3; \
    meteoroid[4].y = AXIS_Y_METEOROID_4; \
    for (uint8_t i = 0; i < NUM_METEOROIDS; i++) { \
        meteoroid[i].x = (rand() % 39) + 130; \
        meteoroid[i].visible = WHITE; \
        meteoroid[i].action_image = rand() % 3 + 1; \
    } \
} while (0);

#define AR_GAME_METEOROID_RUN() \
do { \
    for (uint8_t i = 0; i < NUM_METEOROIDS; i++) { \
        if (meteoroid[i].visible == WHITE) { \
            meteoroid[i].x -= settingsetup.meteoroid_speed; \
            if (meteoroid[i].action_image < 4) { \
                meteoroid[i].action_image++; \
            } \
            if (meteoroid[i].action_image == 4) { \
                meteoroid[i].action_image = 1; \
            } \
        } \
    } \
} while(0);

#define AR_GAME_METEOROID_DETONATOR() \
do { \
    for (uint8_t i = 0; i < NUM_BANG; i++) { \
        if (meteoroid[i].visible == WHITE) { \
            for (uint8_t j = 0; j < MAX_NUM_ARROW; j++) { \
                if (meteoroid[i].x < (arrow[j].x + SIZE_BITMAP_ARROW_X - 3)) { \
                    if ((meteoroid[i].y + 8) > arrow[j].y) { \
                        if ((meteoroid[i].y - 1) < arrow[j].y) { \
                            meteoroid[i].visible = BLACK; \
                            arrow[j].visible = BLACK; \
                            bang[i].visible = WHITE; \
                            bang[i].x = meteoroid[i].x-5; \
                            bang[i].y = meteoroid[i].y+2; \
                            arrow[j].x = 0; \
                            meteoroid[i].x = (rand() % 39) + 130; \
                            settingsetup.num_arrow++; \
                            ar_game_score += 10; \
                            BUZZER_PlayTones(tones_BUM); \
                        } \
                    } \
                } \
            } \
        } \
    } \
} while(0);

#define AR_GAME_METEOROID_RESET() \
do { \
    for (uint8_t i = 0; i < NUM_METEOROIDS; i++) { \
        meteoroid[i].x = (rand() % 39) + 130; \
        meteoroid[i].visible = BLACK; \
        meteoroid[i].action_image = rand() % 3 + 1; \
    } \
} while (0);

void ar_game_meteoroid_handle(ak_msg_t* msg) {
    switch (msg->sig) {
    case AR_GAME_METEOROID_SETUP: {
        APP_DBG_SIG("AR_GAME_METEOROID_SETUP\n");
        AR_GAME_METEOROID_SETUP();
    }
        break;

    case AR_GAME_METEOROID_RUN: {
        APP_DBG_SIG("AR_GAME_METEOROID_RUN\n");
        AR_GAME_METEOROID_RUN();
    }
        break;

    case AR_GAME_METEOROID_DETONATOR: {
        APP_DBG_SIG("AR_GAME_METEOROID_DETONATOR\n");
        AR_GAME_METEOROID_DETONATOR();
    }
        break;

    case AR_GAME_METEOROID_RESET: {
        APP_DBG_SIG("AR_GAME_METEOROID_RESET\n");
        AR_GAME_METEOROID_RESET();
    }
        break;

    default:
        break;
    }
}