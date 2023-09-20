#include "scr_game_over.h"

/*****************************************************************************/
/* Variable Declaration - game over */
/*****************************************************************************/
static ar_game_score_t gamescore;

/*****************************************************************************/
/* View - game over */
/*****************************************************************************/
static void view_scr_game_over();

view_dynamic_t dyn_view_item_game_over = {
	{
		.item_type = ITEM_TYPE_DYNAMIC,
	},
	view_scr_game_over
};

view_screen_t scr_game_over = {
	&dyn_view_item_game_over,
	ITEM_NULL,
	ITEM_NULL,

	.focus_item = 0,
};

void view_scr_game_over() {
	// Screen
	view_render.fillScreen(WHITE);
	view_render.setTextSize(2);
	view_render.setTextColor(BLACK);
	view_render.setCursor(11, 10);
	view_render.print("GAME OVER");
	view_render.setTextSize(1);
	view_render.setTextColor(BLACK);
	view_render.setCursor(16, 35);
	view_render.print("Your score:");
	view_render.setCursor(81, 35);
	view_render.print(gamescore.score_now);
	// Icon
	view_render.drawBitmap(10, 	48,	icon_restart,	15,	15,	0);
	view_render.drawBitmap(55, 	50,	icon_charts,	17,	15,	0);
	view_render.drawBitmap(100,	48,	icon_go_home,	16,	16,	0);
}

/*****************************************************************************/
/* Handle - game over */
/*****************************************************************************/
void rank_ranking() {
	if (gamescore.score_now > gamescore.score_1st) {
		gamescore.score_3rd = gamescore.score_2nd;
		gamescore.score_2nd = gamescore.score_1st;
		gamescore.score_1st = gamescore.score_now;
	}
	else if (gamescore.score_now > gamescore.score_2nd) {
		gamescore.score_3rd = gamescore.score_2nd;
		gamescore.score_2nd = gamescore.score_now;
	}
	else if (gamescore.score_now > gamescore.score_3rd) {
		gamescore.score_3rd = gamescore.score_now;
	}
}

void scr_game_over_handle(ak_msg_t* msg) {
	switch (msg->sig) {
	case SCREEN_ENTRY: {
		APP_DBG_SIG("SCREEN_ENTRY\n");
		// View render
		view_render.initialize();
		view_render_display_on();
		// Read score 1st, 2nd, 3rd
		eeprom_read(	EEPROM_SCORE_START_ADDR, \
						(uint8_t*)&gamescore, \
						sizeof(gamescore));
		// Read score play
		eeprom_read(	EEPROM_SCORE_PLAY_ADDR, \
						(uint8_t*)&gamescore.score_now, \
						sizeof(gamescore.score_now));
		// Reorganize
		rank_ranking();
	}
		break;

	case AC_DISPLAY_BUTTON_MODE_RELEASED: {
		APP_DBG_SIG("AC_DISPLAY_BUTTON_MODE_RELEASED\n");
		// Save score and go Menu game
		eeprom_write(	EEPROM_SCORE_START_ADDR, \
						(uint8_t*)&gamescore, \
						sizeof(gamescore));
		SCREEN_TRAN(scr_menu_game_handle, &scr_menu_game);
	}
		BUZZER_PlayTones(tones_cc);
		break;

	case AC_DISPLAY_BUTTON_UP_RELEASED: {
		APP_DBG_SIG("AC_DISPLAY_BUTTON_UP_RELEASED\n");
		// Save score and go Charts
		eeprom_write(	EEPROM_SCORE_START_ADDR, \
						(uint8_t*)&gamescore, \
						sizeof(gamescore));
		SCREEN_TRAN(scr_charts_game_handle, &scr_charts_game );
	}
		BUZZER_PlayTones(tones_cc);
		break;

	case AC_DISPLAY_BUTTON_DOWN_RELEASED: {
		APP_DBG_SIG("AC_DISPLAY_BUTTON_DOWN_RELEASED\n");
		// Save score and restart game
		eeprom_write(	EEPROM_SCORE_START_ADDR, \
						(uint8_t*)&gamescore, \
						sizeof(gamescore));
		SCREEN_TRAN(scr_archery_game_handle, &scr_archery_game );
	}	
		BUZZER_PlayTones(tones_cc);
		break;

	default:
		break;
	}
}