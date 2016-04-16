/*
* @Author: sxf
* @Date:   2015-12-16 12:02:18
* @Last Modified by:   sxf
* @Last Modified time: 2016-03-05 17:01:18
*/
#ifdef __APPLE__
#define GTEST_HAS_POSIX_RE 0
#endif

#include <gtest/gtest.h>
#include <sfvfs/sfvfs.h>
#include <stdio.h>
#include <exception>

using namespace std;

#define __MainTest__(name) TEST(MainTest_##name, name)

__MainTest__(Construction)
{
	printf("MainTest for construction\n");

	sfvfs_options opts = SFVFS_OPTIONS_DEFAULT;
	sfvfs_makefile("./data", &opts);
}
