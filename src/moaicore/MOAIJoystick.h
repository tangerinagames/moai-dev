// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef MOAIJOYSTICK_H
#define MOAIJOYSTICK_H

#include <moaicore/MOAILua.h>
#include <aku/AKU.h>

//================================================================//
// MOAIFoo
//================================================================//
/**	@name	MOAIFoo
	@text	Example class for extending Moai using MOAILuaObject.
			Copy this object, rename it and add your own stuff.
			Just don't forget to register it with the runtime
			using the REGISTER_LUA_CLASS macro (see moaicore.cpp).
*/
class MOAIJoystick : public virtual MOAILuaObject {
private:

	//----------------------------------------------------------------//
	static int _getAxisValue(lua_State* L);
	static int _getButton(lua_State* L);
	static int _getName(lua_State* L);
	static int _connected(lua_State* L);
	static int _setNumber(lua_State* L);

	//----------------------------------------------------------------//
	int number;

public:

	DECL_LUA_FACTORY(MOAIJoystick)

	//----------------------------------------------------------------//
	MOAIJoystick();
	~MOAIJoystick();
	void RegisterLuaClass(MOAILuaState& state);
	void RegisterLuaFuncs(MOAILuaState& state);
};

#endif
