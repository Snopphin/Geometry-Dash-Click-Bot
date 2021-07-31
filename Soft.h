#pragma once
#include "cocos2d.h"
using namespace cocos2d;
namespace Soft {
	inline void(__thiscall* SF)(cocos2d::CCLayer* self, float delta);
	void __fastcall hkSoft(cocos2d::CCLayer* self, void*, float delta);


	inline bool(__thiscall* initfm)(CCLayer* self, void* GJGameLevel);
	bool __fastcall InitFMOD(CCLayer* self, int edx, void* GJGameLevel);
	void mem_init();
}