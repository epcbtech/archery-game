#include "task_list.h"
#include "timer.h"

const task_t app_task_table[] = {
	/*************************************************************************/
	/* SYSTEM TASK */
	/*************************************************************************/
	{TASK_TIMER_TICK_ID			,	TASK_PRI_LEVEL_7	,	task_timer_tick		},

	/*************************************************************************/
	/* APP TASK */
	/*************************************************************************/
	{AC_TASK_FW_ID				,	TASK_PRI_LEVEL_2	,	task_fw				},
	{AC_TASK_SHELL_ID			,	TASK_PRI_LEVEL_2	,	task_shell			},
	{AC_TASK_LIFE_ID			,	TASK_PRI_LEVEL_6	,	task_life			},
	{AC_TASK_IF_ID				,	TASK_PRI_LEVEL_4	,	task_if				},
	{AC_TASK_UART_IF_ID			,	TASK_PRI_LEVEL_4	,	task_uart_if		},
	{AC_TASK_DISPLAY_ID			,	TASK_PRI_LEVEL_4	,	task_display		},

	/*************************************************************************/
	/* ARCHERY GAME */
	/*************************************************************************/
	{AR_GAME_METEOROID_ID		,	TASK_PRI_LEVEL_4	,	ar_game_meteoroid_handle},
	{AR_GAME_BORDER_ID			,	TASK_PRI_LEVEL_4	,	ar_game_border_handle	},
	{AR_GAME_ARCHERY_ID			,	TASK_PRI_LEVEL_4	,	ar_game_archery_handle	},
	{AR_GAME_ARROW_ID			,	TASK_PRI_LEVEL_4	,	ar_game_arrow_handle	},
	{AR_GAME_BANG_ID			,	TASK_PRI_LEVEL_4	,	ar_game_bang_handle		},
	{AR_GAME_SCREEN_ID			,	TASK_PRI_LEVEL_4	,	scr_archery_game_handle	},

	/*************************************************************************/
	/* LINK TASK */
	/*************************************************************************/
	#if defined (IF_LINK_UART_EN)
	{AC_LINK_PHY_ID				,	TASK_PRI_LEVEL_3	,	task_link_phy		},
	{AC_LINK_MAC_ID				,	TASK_PRI_LEVEL_4	,	task_link_mac		},
	{AC_LINK_ID					,	TASK_PRI_LEVEL_5	,	task_link			},
	#endif

	/*************************************************************************/
	/* END OF TABLE */
	/*************************************************************************/
	{AK_TASK_EOT_ID				,	TASK_PRI_LEVEL_0	,	(pf_task)0			}
};

const task_polling_t app_task_polling_table[] = {
	{AC_TASK_POLLING_CONSOLE_ID	,	AK_ENABLE	,	task_polling_console		},
	{AK_TASK_POLLING_EOT_ID		,	AK_DISABLE	,	(pf_task_polling)0			},
};
