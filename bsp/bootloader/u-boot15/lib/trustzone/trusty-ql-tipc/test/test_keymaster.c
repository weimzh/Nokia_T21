/*
 * Copyright (C) 2019 unisoc.com
 */

#include <trusty/keymaster.h>
#include <trusty/trusty_dev.h>
#include <trusty/trusty_ipc.h>
#include <trusty/util.h>

#define LOCAL_LOG 1

static struct trusty_ipc_dev* _ipc_dev;
static struct trusty_dev _tdev; /* There should only be one trusty device */

void kermaster_test(void) {
    int rc;
    /* init Trusty device */
    trusty_info("Initializing Trusty device\n");
    rc = trusty_dev_init(&_tdev, NULL);
    if (rc != 0) {
        trusty_error("Initializing Trusty device failed (%d)\n", rc);
        return rc;
    }

    /* create Trusty IPC device */
    trusty_info("Initializing Trusty IPC device\n");
    rc = trusty_ipc_dev_create(&_ipc_dev, &_tdev, PAGE_SIZE);
    if (rc != 0) {
        trusty_error("Initializing Trusty IPC device failed (%d)\n", rc);
        return rc;
    }


    trusty_info("Initializing Trusty Keymaster client\n");
    rc = km_tipc_init(_ipc_dev);
    if (rc != 0) {
        trusty_error("Initlializing Trusty Keymaster client failed (%d)\n", rc);
        return rc;
    }

    trusty_info("shutdown Trusty Keymaster client\n");
    (void)km_tipc_shutdown(_ipc_dev);

    trusty_info("shutdown Trusty IPC device\n");
    (void)trusty_ipc_dev_shutdown(_ipc_dev);

    trusty_info("shutdown Trusty device\n");
    (void)trusty_dev_shutdown(&_tdev);


    return TRUSTY_ERR_NONE;
}
