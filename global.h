#pragma once

#ifndef __GLOBAL__
#define __GLOBAL__

static class global {
public:
	static bool girdstatus[10][10];
	static int sun;
	static void setHardLevel(int);
	static int getHardLevel();
	static int hardLevel;
};

#endif