#pragma once
#include "MinHook.h"
#include <cocos2d.h>

namespace PlayerObject {


	inline bool(__thiscall* pushButton)(void* self, void* PlayerButton);
	inline bool(__thiscall* releaseButton)(void* self, void* PlayerButton);
	// Hook functions
	bool __fastcall pushButtonHook(void* self, int edx, void* PlayerButton);
	bool __fastcall releaseButtonHook(void* self, int edx, void* PlayerButton);


	// Hooks init function
	void mem_init();
}