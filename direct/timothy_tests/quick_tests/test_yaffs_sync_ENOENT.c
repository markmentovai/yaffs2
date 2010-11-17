/*
 * YAFFS: Yet another FFS. A NAND-flash specific file system.
 *
 * Copyright (C) 2002-2010 Aleph One Ltd.
 *   for Toby Churchill Ltd and Brightstar Engineering
 *
 * Created by Timothy Manning <timothy@yaffs.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include "test_yaffs_sync_ENOENT.h"


int test_yaffs_sync_ENOENT(void)
{
	int error_code=-1;
	int output = yaffs_sync("yaffs2/non-existing-file");
	
	if (output<0){
		error_code=yaffs_get_error();
		if (abs(error_code)==ENOENT){
			return 1;
		} else {
			print_message("returned error does not match the the expected error\n",2);
			return -1;
		}
	} else {
		print_message("synced a file in a non-existing directory (which is a bad thing)\n",2);
		return -1;
	}	


}


int test_yaffs_sync_ENOENT_clean(void)
{
	return 1;
}

