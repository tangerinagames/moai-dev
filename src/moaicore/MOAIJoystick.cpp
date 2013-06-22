	// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moaicore/MOAIJoystick.h>

//================================================================//
// lua
//================================================================//

//----------------------------------------------------------------//
int MOAIJoystick::_getAxisValue(lua_State* L) {
	MOAI_LUA_SETUP(MOAIJoystick, "U")

	AKUGetJoystickAxisFunc getJoystickAxis = AKUGetFunc_GetJoystickAxis();
	if (getJoystickAxis) {
		lua_pushnumber(state, getJoystickAxis(self->number, state.GetValue<int>(2, 0)));
		return 1;
	}

	return 0;
}

//----------------------------------------------------------------//
int MOAIJoystick::_getButton(lua_State* L) {
	MOAI_LUA_SETUP(MOAIJoystick, "U")

	AKUGetJoystickButtonFunc getJoystickButton = AKUGetFunc_GetJoystickButton();
	if (getJoystickButton) {
		lua_pushboolean(state, getJoystickButton(self->number, state.GetValue<int>(2, 0)));
		return 1;
	}

	return 0;
}

//----------------------------------------------------------------//
int MOAIJoystick::_getName(lua_State* L) {
	MOAI_LUA_SETUP(MOAIJoystick, "U")

	AKUGetJoystickNameFunc getJoystickName = AKUGetFunc_GetJoystickName();
	if (getJoystickName) {
		lua_pushstring(state, getJoystickName(self->number));
		return 1;
	}

	return 0;
}

//----------------------------------------------------------------//
int MOAIJoystick::_connected(lua_State* L) {
	MOAI_LUA_SETUP(MOAIJoystick, "U")

	AKUIsJoystickConnectedFunc isJoystickConnected = AKUGetFunc_IsJoystickConnected();
	if (isJoystickConnected) {
		lua_pushboolean(state, isJoystickConnected(self->number));
		return 1;
	}

	return 0;
}

//----------------------------------------------------------------//
int MOAIJoystick::_setNumber(lua_State* L) {
	MOAI_LUA_SETUP(MOAIJoystick, "U")

	self->number = state.GetValue<int>(2, 0);

	return 0;
}

//================================================================//
// MOAIJoystick
//================================================================//

//----------------------------------------------------------------//
MOAIJoystick::MOAIJoystick() : number(0) {
	RTTI_BEGIN
		RTTI_EXTEND(MOAILuaObject)
	RTTI_END
}

//----------------------------------------------------------------//
MOAIJoystick::~MOAIJoystick() {
}

//----------------------------------------------------------------//
void MOAIJoystick::RegisterLuaClass(MOAILuaState& state) {

	luaL_Reg regTable [] = {
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}

//----------------------------------------------------------------//
void MOAIJoystick::RegisterLuaFuncs(MOAILuaState& state) {

	luaL_Reg regTable [] = {
		{ "getAxisValue",	_getAxisValue },
		{ "getButton",	_getButton },
		{ "getName",	_getName },
		{ "connected",	_connected },
		{ "setNumber",	_setNumber },
		{ NULL, NULL }
	};

	luaL_register(state, 0, regTable);
}
