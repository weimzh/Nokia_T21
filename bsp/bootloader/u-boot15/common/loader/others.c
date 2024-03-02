/*
 * Copyright (c) 2009, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <common.h>
#include <malloc.h>
#include <android_bootimg.h>
#include <boot_mode.h>
#include <dl_common.h>
#include "sparse_format.h"
#include <linux/usb/usb_uboot.h>
#include <sprd_common_rw.h>
#include <asm/errno.h>
#include "dl_operate.h"
#include <asm/arch/chip_releted_def.h>
#include <linux/input.h>
#include <secureboot/sec_common.h>

#include <chipram_env.h>
#include "custom.h"
#include "others.h"



#ifdef CONFIG_SECBOOT
extern int set_rma(void);
extern unsigned int get_lock_status(void);
extern int set_lock_status(unsigned int flag);
#endif
extern char *get_product_sn();

//############################################################################
void show_item_sel(int col, int row, bool sel, const char* p)
{
	char tmp[512];
	char* strsel = "-> ";
	int len = 0;
	int isel = strlen(strsel);
	
	memset(tmp, ' ', sizeof(tmp));
	tmp[64] = '\0';
	
	len = strlen(p);
	
	if (sel) {
		len = len > (512 - isel - 1) ? (512 - isel - 1) : len;
		
		strncpy(tmp, strsel, isel);
		strncpy(tmp + isel, p, len);	 
	} else {
		len = len > 511 ? 511 : len;
		strncpy(tmp + isel, p, len);
	}
	
	lcd_position_cursor(col, row);
	lcd_printf("%s", tmp);
}

void dispay_state_verified_tips(int op, int type)
{
	char buf[64];
	int row = 0;
	
    	memset(buf, ' ', sizeof(buf));
	buf[63] = '\0';
	
	row = lcd_get_screen_rows();
	lcd_position_cursor(0, row - ROW_UNLOCKED_TIP_START);
	
	if ( op == OP_PAUSE ) {
		sprintf(buf, "%s\n", "PRESS POWER BUTTON TO CONTINUE");
	} else if ( op == OP_DO ) {
	} else if ( op == OP_CANCEL ) {
		lcd_printf("%s", buf);
		lcd_position_cursor(0, row - ROW_UNLOCKED_TIP_START);
		sprintf(buf, "%s\n", "CANCELED!");
	} else if ( op == OP_TIMEOUT ) {
		lcd_printf("%s", buf);
		lcd_position_cursor(0, row - ROW_UNLOCKED_TIP_START);
		sprintf(buf, "%s\n", "TIMEOUT!");
	} else {
	    if ( type == TYPE_RED_EIO ) {
		    sprintf(buf, "%s\n", "PRESS POWER BUTTON TO CONTINUE");
		} else if ( type == TYPE_RED_OTHERS ) {
		    sprintf(buf, "%s\n", "PRESS POWER BUTTON TO POWER OFF");
		} else {
		    sprintf(buf, "%s\n", "PRESS POWER BUTTON TO PAUSE");
		}
	}
	lcd_printf("%s", buf);
}

static void display_warnning_logo()
{
	lcd_printf("      / \\\n");
	lcd_printf("    /  |  \\\n");
	lcd_printf("  /    |    \\\n");
	lcd_printf("  \\    |    /\n");
	lcd_printf("    \\  0  /\n");
	lcd_printf("      \\ /\n\n");
}

static bool is_gms_device(char * psn)
{
        if ( 0 == strncmp("gms", psn, 3) || 0 == strncmp("sngms", psn, 5) ) {
		return true;
        }
	return false;
}

void display_state_verified_eio_red()
{
	int row = 0;
	int sel = 0;
	int key_code;
	char buf[64];
        char *psn;
	int op = -1;
	int timeout = TIMEOUT_THIRTY_SEC; //10s
	bool bpause = false;
	int color = -1;
        bool bgms = false;
	
	memset(buf, '\0', sizeof(buf));
	
	lcd_clear();
    
	color = lcd_getfgcolor();
	lcd_setfgcolor(CONSOLE_COLOR_RED);
    	display_warnning_logo();
	lcd_setfgcolor(color);
	
    	lcd_printf("Your device is corrupt. It can't be trusted and may not work properly. \n\n");
	lcd_printf("Visit this link on another device to learn more: \n\n");
	color = lcd_getfgcolor();
	lcd_setfgcolor(CONSOLE_COLOR_RED);
	lcd_printf("https://www.nokia.com/mobile-support\n\n");
	lcd_setfgcolor(color);
	
	row = lcd_get_screen_rows();
        psn = get_product_sn();
	lcd_position_cursor(0, row - ROW_UNLOCKED_SN_START);
	sprintf(buf, "ID: %s\n", psn);
	lcd_printf("%s", buf);
    	lcd_position_cursor(0, row - ROW_UNLOCKED_DIV_START);
	lcd_printf("__________________________________________\n");

        bgms = is_gms_device(psn);

	if ( s_boot_mode == CMD_NORMAL_MODE || s_boot_mode == CMD_FASTBOOT_MODE ) {
		if (s_boot_mode == CMD_NORMAL_MODE && bgms) {
			return;
		}
#ifndef WT_COMPILE_FACTORY_VERSION
		dispay_state_verified_tips(op, TYPE_RED_EIO);

		while(op < 0) {
    			/* continue canheck till button pressed */
       			key_code = wait_for_keypress(timeout, true);
       			if ( key_code == KEY_POWER ) {
				    op = OP_DO;
				    dispay_state_verified_tips(op, TYPE_RED_EIO);
        		}  else if ( key_code < 0 ) {
				    op = OP_TIMEOUT;
        		}			
    	}
		dispay_state_verified_tips(op, TYPE_RED_OTHERS);
#endif
	}

	return;
}


void display_state_verified_red()
{
	int row = 0;
	int sel = 0;
	int key_code;
	char buf[64];
        char *psn;
	int op = -1;
	int timeout = TIMEOUT_THIRTY_SEC; //10s
	bool bpause = false;
	int color = -1;
        bool bgms = false;
	
	memset(buf, '\0', sizeof(buf));
	
	lcd_clear();
    
	color = lcd_getfgcolor();
	lcd_setfgcolor(CONSOLE_COLOR_RED);
    	display_warnning_logo();
	lcd_setfgcolor(color);
	
    	lcd_printf("No valid operating system could be found. The device will not boot. \n\n");
	lcd_printf("Visit this link on another device to learn more: \n\n");
	color = lcd_getfgcolor();
	lcd_setfgcolor(CONSOLE_COLOR_RED);
	lcd_printf("https://www.nokia.com/mobile-support\n\n");
	lcd_setfgcolor(color);
	
	row = lcd_get_screen_rows();
        psn = get_product_sn();
	lcd_position_cursor(0, row - ROW_UNLOCKED_SN_START);
	sprintf(buf, "ID: %s\n", psn);
	lcd_printf("%s", buf);
    	lcd_position_cursor(0, row - ROW_UNLOCKED_DIV_START);
	lcd_printf("__________________________________________\n");

        bgms = is_gms_device(psn);

	if ( s_boot_mode == CMD_NORMAL_MODE || s_boot_mode == CMD_FASTBOOT_MODE ) {
		if (s_boot_mode == CMD_NORMAL_MODE && bgms) {
			return;
		}
#ifndef WT_COMPILE_FACTORY_VERSION
		dispay_state_verified_tips(op, TYPE_RED_OTHERS);

		while(op < 0) {
    			/* continue canheck till button pressed */
       			key_code = wait_for_keypress(timeout, true);
       			if ( key_code == KEY_POWER ) {
				    op = OP_DO;
				    dispay_state_verified_tips(op, TYPE_RED_OTHERS);
        		} else if ( key_code < 0 ) {
				    op = OP_TIMEOUT;
        		}			
    	}
		dispay_state_verified_tips(op, TYPE_RED_OTHERS);
#endif
	}

	return;
}

void display_state_verified_yellow()
{
	int row = 0;
	int sel = 0;
	int key_code;
	char buf[64];
	int op = -1;
	int timeout = TIMEOUT_TEN_SEC; //10s
	bool bpause = false;
	int color = -1;
        bool bgms = false;
        char *psn;
	
	memset(buf, '\0', sizeof(buf));
	
	lcd_clear();
    
	color = lcd_getfgcolor();
	lcd_setfgcolor(CONSOLE_COLOR_YELLOW);
    	display_warnning_logo();
	lcd_setfgcolor(color);
	
    	lcd_printf("Your device has loaded a different operating system. \n\n");
	lcd_printf("Visit this link on another device to learn more: \n\n");
	color = lcd_getfgcolor();
	lcd_setfgcolor(CONSOLE_COLOR_YELLOW);
	lcd_printf("https://www.nokia.com/mobile-support\n\n");
	lcd_setfgcolor(color);
	
	row = lcd_get_screen_rows();
        psn = get_product_sn();
	lcd_position_cursor(0, row - ROW_UNLOCKED_SN_START);
	sprintf(buf, "ID: %s\n", psn);
	lcd_printf("%s", buf);
    	lcd_position_cursor(0, row - ROW_UNLOCKED_DIV_START);
	lcd_printf("__________________________________________\n");

        bgms = is_gms_device(psn);
	if ( s_boot_mode == CMD_NORMAL_MODE || s_boot_mode == CMD_FASTBOOT_MODE ) {
		if (s_boot_mode == CMD_NORMAL_MODE && bgms) {
			return;
		}

#ifndef WT_COMPILE_FACTORY_VERSION
		dispay_state_verified_tips(op, TPYE_YELLOW);

    		while(op < 0 || op == OP_PAUSE) {
    			/* continue canheck till button pressed */
       			key_code = wait_for_keypress(timeout, true);
       			if ( key_code == KEY_POWER ) {
				if ( !bpause ) {
					op = OP_PAUSE;
					timeout = TIMEOUT_MAX;
				} else {
					timeout = TIMEOUT_TEN_SEC;
					op = OP_DO;
				}
				bpause = !bpause;
			
				dispay_state_verified_tips(op, TPYE_YELLOW);
			} else if ( key_code < 0 ) {
				op = OP_TIMEOUT;
        		}			
    		}
			dispay_state_verified_tips(op, TPYE_YELLOW);
#endif
        }
	
	lcd_splash("logo");
        if ( s_boot_mode == CMD_FASTBOOT_MODE ) {
	    lcd_position_cursor(0, 0);
            lcd_printf("\n   fastboot mode");
        }
	return;
}

void display_state_verified_orange()
{
	int row = 0;
	int sel = 0;
	int key_code;
	char buf[64];
	int op = -1;
	int timeout = TIMEOUT_TEN_SEC; //10s
	bool bpause = false;
	int color = -1;
        bool bgms = false;
        char *psn;
	
	memset(buf, '\0', sizeof(buf));
	
	lcd_clear();
    	color = lcd_getfgcolor();
	lcd_setfgcolor(CONSOLE_COLOR_ORANGE);
    	display_warnning_logo();
	lcd_setfgcolor(color);
	
    	lcd_printf("The boot loader is unlocked and software integrity cannot be guaranteed. Any data stored on the device may be available to attackers. Do not store any sensitive data on the device.  \n\n");
	lcd_printf("Visit this link on another device to learn more: \n\n");
	color = lcd_getfgcolor();
	lcd_setfgcolor(CONSOLE_COLOR_ORANGE);
	lcd_printf("https://www.nokia.com/mobile-support\n\n");
	lcd_setfgcolor(color);
	
	row = lcd_get_screen_rows();
        psn = get_product_sn();
	lcd_position_cursor(0, row - ROW_UNLOCKED_SN_START);
	sprintf(buf, "ID: %s\n", psn);
	lcd_printf("%s", buf);
    	lcd_position_cursor(0, row - ROW_UNLOCKED_DIV_START);
	lcd_printf("__________________________________________\n");

        bgms = is_gms_device(psn);
	if ( s_boot_mode == CMD_NORMAL_MODE || s_boot_mode == CMD_FASTBOOT_MODE ) {
		if (s_boot_mode == CMD_NORMAL_MODE && bgms) {
			return;
		}

#ifndef WT_COMPILE_FACTORY_VERSION
		dispay_state_verified_tips(op, TYPE_ORANGE);

    		while(op < 0 || op == OP_PAUSE) {
    			/* continue canheck till button pressed */
       			key_code = wait_for_keypress(timeout, true);
       			if ( key_code == KEY_POWER ) {
				if ( !bpause ) {
					op = OP_PAUSE;
					timeout = TIMEOUT_MAX;
				} else {
					timeout = TIMEOUT_TEN_SEC;
					op = OP_DO;
				}
				bpause = !bpause;
			
				dispay_state_verified_tips(op, TYPE_ORANGE);
			} else if ( key_code < 0 ) {
				op = OP_TIMEOUT;
        		}			
    		}
			dispay_state_verified_tips(op, TYPE_ORANGE);
#endif
	}
	lcd_splash("logo");
        if ( s_boot_mode == CMD_FASTBOOT_MODE ) {
		lcd_position_cursor(0, 0);
        	lcd_printf("\n   fastboot mode");
        }
	return;
}


int display_unlock_infos_and_wait_op(bool bunlock)
{
	int row = 0;
	int sel = 0;
	int op = -1;
	int key_code;
	int color = -1;
	
	lcd_clear();
	
	color = lcd_getfgcolor();
	lcd_setfgcolor(CONSOLE_COLOR_ORANGE);
    display_warnning_logo();
	lcd_setfgcolor(color);
        if (bunlock) {
            lcd_printf("Nokia phones already feature a fully optimized, certificated and tested version of Android.\n");
	    lcd_printf("While unlocking the bootloader will allow you to customize your device, we ask that you do not proceed unless you have read and fully agree to the following:\n\n");
	    lcd_printf(" - once your phone is unlocked, it will no longer be covered by the manufacturer's limited warranty provided by HMD Global.\n");
	    lcd_printf(" - Once a device is unlocked, the process cannot be undone.\n");
	    lcd_printf(" - Unlocking a device means you may lose some of its functionalities, including - but not limit to\n");
	    lcd_printf("   - telephone, radio, audio, video, payment, encryption and DRM.\n");
	    lcd_printf(" - After unlocking, all media and content on the device will be erased, and you will need to reinstall all applications.\n");
	    lcd_printf(" - Applications may not work anymore.\n");
	    lcd_printf(" - You could cause permanent/physical damage to your device.\n");
	    lcd_printf(" - Your device may become unsafe to the point of causing you harm.\n\n");
            lcd_printf("Press the Volume Up/Volume Down to select whether to unlock the bootloader, then the power button to continue. \n");
        } else {
            lcd_printf("Nokia phones already feature a fully optimized, certificated and tested version of Android.\n\n");
            lcd_printf(" - After locking, all media and content on the device will be erased, and you will need to reinstall all applications.\n");
            lcd_printf(" - Applications may not work anymore.\n\n");
            lcd_printf("Press the Volume Up/Volume Down to select whether to lock the bootloader, then the power button to continue. \n");
        }
    
	
	row = lcd_get_screen_cureent_row();
	
	row = row + ROW_ITEM_START;
	//lcd_position_cursor(0, row); 
	debugf("==> row = %d", row);
	lcd_printf("________________________________________________________\n"); 
        if ( bunlock ) {
            show_item_sel(7, row, true, "Don't unlock - Do not unlock bootloader and restart device.");
	    show_item_sel(7, row + 1, false, "Unlock - Unlock bootloader");
        } else {
            show_item_sel(7, row, true, "Don't lock - Do not lock bootloader and restart device.");
	    show_item_sel(7, row + 1, false, "Lock - Lock bootloader");
        }
	
    while(op < 0) {
    	/* continue canheck till button pressed */
    	if(is_gsimode){
			lcd_printf("\n  gsimode skip ++++");
			key_code = KEY_POWER;
			op = OP_DO;
			break;
		}
       	key_code = wait_for_keypress(TIMEOUT_THIRTY_SEC, false);
       	if (key_code == KEY_VOLUMEDOWN) {
		sel --;
		sel = (sel < 0 ? 1 : sel);
        } else if (key_code == KEY_VOLUMEUP) {
		sel ++;
		sel = (sel > 1 ? 0 : sel);
        } else if ( key_code == KEY_POWER ) {
		op = (sel == 1 ? OP_DO : OP_CANCEL);
	}		
		
	if ( key_code < 0 ) {
		op = OP_TIMEOUT;
		lcd_splash("logo");
                if ( s_boot_mode == CMD_FASTBOOT_MODE ) {
	    		lcd_position_cursor(0, 0);
            		lcd_printf("\n   fastboot mode");
        	}
	} else if ( key_code != KEY_POWER ) {
                if ( bunlock ) {
		    show_item_sel(7, row, sel == 0, "Don't unlock - Do not unlock bootloader and restart device.");
	            show_item_sel(7, row + 1, sel == 1, "Unlock - Unlock bootloader");
                } else {
		    show_item_sel(7, row, sel == 0, "Don't lock - Do not lock bootloader and restart device.");
	            show_item_sel(7, row + 1, sel == 1, "Lock - Lock bootloader");
                }
	}
    }
	return op;
}

static int s_key_pre = -1;
static int s_count_times = -1;

int wait_for_keypress(int timeout, bool bwait_only_power){
	debugf("Enter fastboot wait_for_keypress\n");
	int key_code;
	int i=0, row;
	int times_timeout = (timeout)/100;
	char tmp[32];
	row = lcd_get_screen_rows();
	debugf("wait_for_keypress: set timeout times to %d\n", times_timeout);
	do {
		if(i>=times_timeout){
			debugf("wait_for_keypress time out\n");
			key_code = -1;
			break;
		}
		udelay(100 * 1000);
		
		memset(tmp, ' ', sizeof(tmp));
	    tmp[31] = '\0';
	
		if ( !bwait_only_power ) { 
		    key_code = board_key_scan();
		    debugf("key_code is %x\n", key_code);
			debugf("s_count_times is %d, s_key_pre=%d\n", s_count_times, s_key_pre);
		    if (key_code == KEY_VOLUMEDOWN || key_code == KEY_VOLUMEUP) {
			    if ( s_key_pre != key_code || s_count_times > 2) {
			        s_key_pre = key_code;
			        s_count_times = 0;
					memset(tmp, ' ', sizeof(tmp));
	                tmp[31] = '\0';
					lcd_position_cursor(0, row - 2);
					lcd_printf("%s", tmp);
			        break;
			    } else {
					debugf("skip keycode %x\n", key_code);
			 	    continue;
			    }
		    }
		}
		
		if ( power_button_pressed() == KEY_PRESSED ) {
			key_code = KEY_POWER;
            debugf("s_count_times is %d, s_key_pre=%d\n", s_count_times, s_key_pre);
			if ( s_key_pre != key_code || s_count_times > 2) {
			    s_key_pre = key_code;
			    s_count_times = 0;
				debugf("key_code is %x\n", key_code);
				memset(tmp, ' ', sizeof(tmp));
	            tmp[31] = '\0';
				lcd_position_cursor(0, row - 2);
				lcd_printf("%s", tmp);
			    break;
			} else {
				debugf("skip keycode %x\n", key_code);
			 	continue;
			}
		}
		sprintf(tmp, "Timeout: %d", times_timeout - i);
		
	    lcd_position_cursor(0, row - 2);
		lcd_printf("%s", tmp);
		i++;
		s_count_times ++;
	} while(1);
	
	memset(tmp, ' ', sizeof(tmp));
	tmp[31] = '\0';
	lcd_position_cursor(0, row - 2);
	lcd_printf("%s", tmp);
	debugf("fastboot wait_for_keypress key_code is %x\n", key_code);
	return key_code;
}



