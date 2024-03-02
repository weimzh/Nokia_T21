/*
 * (C) Copyright 2000-2009
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

/*
 *  Command Processor Table
 */

#include <common.h>
#include <command.h>
#include <linux/ctype.h>

cmd_tbl_t_driver *find_cmd_tbl_driver(const char *cmd, cmd_tbl_t_driver *table, int table_len)
{
        cmd_tbl_t_driver *cmdtp = NULL;
        cmd_tbl_t_driver *cmdtp_temp = table;   /* Init value */
        const char *p;
        int len;
        int n_found = 0;

        if (!cmd)
                return NULL;
        /*
         * Some commands allow length modifiers (like "cp.b");
         * compare command name only until first dot.
         */
        len = ((p = strchr(cmd, '.')) == NULL) ? strlen (cmd) : (p - cmd);

        for (cmdtp = table; cmdtp != table + table_len; cmdtp++) {
                if (strncmp(cmd, cmdtp->name, len) == 0) {
                        if (len == strlen(cmdtp->name))
                        {
                                return cmdtp;   /* full match */
                        }
                        cmdtp_temp = cmdtp;     /* abbreviated command ? */
                        n_found++;
                }
        }
        if (n_found == 1) {                     /* exactly one match */
                return cmdtp_temp;
        }

        return NULL;    /* not found or ambiguous command */
}

cmd_tbl_t_driver *find_cmd_driver(const char *cmd)
{
        cmd_tbl_t_driver *start = ll_entry_start_driver(cmd_tbl_t_driver, cmd);
        const int len = ll_entry_count_driver(cmd_tbl_t_driver, cmd);

        return find_cmd_tbl_driver(cmd, start, len);
}


static int cmd_call_driver(cmd_tbl_t_driver *cmdtp, int flag, int argc, char * const argv[])
{
        int result;

        if (!cmdtp)
                return 1;

	if(argv[3] == NULL)
	{
		result = (cmdtp->cmd)(argc, argv);
		if (result)
			debug("%s failed, result = %d\n", cmdtp->name, result);
		else
			debug("%s success, result = %d\n", cmdtp->name, result);

		return result;

	}else if(strncmp(argv[3], "help", 4) == 0){
		printf("%s\n", cmdtp->help);
		return 0;
	}else{
		result = (cmdtp->cmd)(argc, argv);
		if (result)
			debug("%s failed, result = %d\n", cmdtp->name, result);
		else
			debug("%s success, result = %d\n", cmdtp->name, result);

		return result;
	}
	
}

void list_all_module_case(const char *cmd, cmd_tbl_t_driver *table, int table_len)
{
        cmd_tbl_t_driver *cmdtp = NULL;
        int len;

        if (!cmd || !table)
                return;

        len = strlen(cmd);
        for (cmdtp = table; cmdtp != table + table_len; cmdtp++) {
                if (strncmp(cmd, cmdtp->name, len) == 0) {
			printf("%s:\r", cmdtp->name);	
			printf("%s\n", cmdtp->help);	
                }
        }

}

void list_all_case(int flag, int argc, char * const argv[],
                               int *repeatable, ulong *ticks)
{
        enum command_ret_t rc = CMD_RET_SUCCESS;
        char* cmd = argv[1];

        cmd_tbl_t_driver *start = ll_entry_start_driver(cmd_tbl_t_driver, cmd);
        const int len = ll_entry_count_driver(cmd_tbl_t_driver, cmd);
        list_all_module_case(cmd, start, len);
}


void test_all_module_case(const char *cmd, cmd_tbl_t_driver *table, int table_len, int argc, char * const argv[])
{
        cmd_tbl_t_driver *cmdtp = NULL;
        int len;
        int flag = 0;

        if (!cmd || !table)
                return;

        len = strlen(cmd);
        for (cmdtp = table; cmdtp != table + table_len; cmdtp++) {
                if (strncmp(cmd, cmdtp->name, len) == 0) {
                        cmd_call_driver(cmdtp, flag, argc, argv);
                }
        }
}

void test_all_case(int flag, int argc, char * const argv[],
                               int *repeatable, ulong *ticks)
{
        enum command_ret_t rc = CMD_RET_SUCCESS;
        char *cmd = argv[1];

        cmd_tbl_t_driver *start = ll_entry_start_driver(cmd_tbl_t_driver, cmd);
        const int len = ll_entry_count_driver(cmd_tbl_t_driver, cmd);
        test_all_module_case(cmd, start, len, argc, argv);

}

void cmd_process_driver(int flag, int argc, char * const argv[],
                               int *repeatable, ulong *ticks)
{
        enum command_ret_t rc = CMD_RET_SUCCESS;
        cmd_tbl_t_driver *cmdtp;


        /* Look up command in command table */
        cmdtp = find_cmd_driver(argv[2]);
        if (cmdtp == NULL) {
                printf("Unknown command '%s' - try 'help'\n", argv[2]);
                return;
        }

        rc = cmd_call_driver(cmdtp, flag, argc, argv);

}
