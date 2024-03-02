#ifndef _ED_OTHERS_H_
#define _ED_OTHERS_H_

extern int s_boot_mode;
extern int is_gsimode;
extern int s_efused;

int wait_for_keypress(int timeout, bool bwait_only_power);

//#include "fastboot_hmd_infos.h"
#ifdef CONSOLE_COLOR_YELLOW
#undef CONSOLE_COLOR_YELLOW
#endif
#define CONSOLE_COLOR_YELLOW   0x00ffff00

#ifdef CONSOLE_COLOR_RED
#undef CONSOLE_COLOR_RED
#endif
#define CONSOLE_COLOR_RED   0x00ff0000

#ifdef CONSOLE_COLOR_ORANGE
#undef CONSOLE_COLOR_ORANGE
#endif
#define CONSOLE_COLOR_ORANGE   0x00ff7f27

#define KEY_PRESSED             0
#define KEY_NOT_PRESSED         1

#define ROW_UNLOCKED_SN_START  10
#define ROW_UNLOCKED_DIV_START  6
#define ROW_UNLOCKED_TIP_START  4

#define OP_DO      1
#define OP_CANCEL  2
#define OP_TIMEOUT 3
#define OP_PAUSE   4

#define TPYE_YELLOW     1
#define TYPE_ORANGE     2
#define TYPE_RED_EIO    3
#define TYPE_RED_OTHERS 4

#define ROW_LOG_START      10
#define ROW_ITEM_START     5

#define ROW_UNLOCKED_SN_START  10
#define ROW_UNLOCKED_DIV_START  6
#define ROW_UNLOCKED_TIP_START  4

#define TIMEOUT_MAX (2*60*60*1000)
#define TIMEOUT_TEN_SEC  (9*1000)
#define TIMEOUT_THIRTY_SEC (29*1000)

void show_item_sel(int col, int row, bool sel, const char* p);
void dispay_state_verified_tips(int op, int type);
void display_state_verified_red();
void display_state_verified_yellow();
void display_state_verified_orange();
int display_unlock_infos_and_wait_op(bool bunlock);
void display_state_verified_eio_red();

#endif
