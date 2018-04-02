//
//  main.c
//  TestLua
//
//  Created by Bufu Huang on 2018/4/2.
//  Copyright © 2018年 Bufu Huang. All rights reserved.
//

#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

void load(lua_State *L, const char *fname, int *w, int *h)
{
    if(luaL_loadfile(L, fname) || lua_pcall(L, 0, 0, 0))
    {
        printf("cannot run config. file name: %s", lua_tostring(L, -1));
        //error(L, "cannot run config. file name: %s", lua_tostring(L, -1));
    }
    
    lua_getglobal(L, "width");
    lua_getglobal(L, "height");
    
    if(!lua_isnumber(L, -2))
    {
        printf("wwwww");
        //error(L, "width");
    }
    
    if(!lua_isnumber(L, -1))
    {
        printf("hhhhhhhh");
        //error("height");
    }
    
    *w = lua_tointeger(L, -2);
    *h = lua_tointeger(L, -1);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //lua_State *L = luaL_newstate();
    //luaL_dofile(L, "/Users/bufuhuang/Documents/Test/Lua/TestLua/TestLua/TestLua/Hello.lua");
    
    //lua_close(L);
    //printf("~~~~~~~");
    
//    char buff[256];
//    int error;
//    lua_State *L = luaL_newstate();
//    luaL_openlibs(L);
//
//    while (fgets(buff, sizeof(buff), stdin)) {
//        error = luaL_loadbuffer(L, buff, strlen(buff), "line") ||
//        lua_pcall(L, 0, 0, 0);
//
//        if(error)
//        {
//            fprintf(stderr, "%s", lua_tostring(L, -1));
//            lua_pop(L, -1);
//        }
//    }
    
//    lua_close(L);
    
    //--------------------------
//    lua_State *L = luaL_newstate();
//    int w = 0;
//    int h = 0;
//    load(L, "/Users/bufuhuang/Documents/Test/Lua/TestLua/TestLua/TestLua/Hello.lua", &w, &h);
//
//    printf("w is: %d\n", w);
//    printf("w is: %d\n", h);
//
//    lua_close(L);
    
    //--------------------------
    
//    lua_State *pL = luaL_newstate();
//    luaopen_base(pL);
//    luaopen_math(pL);
//    luaopen_string(pL);
//
//    int err = luaL_dofile(pL, "/Users/bufuhuang/Documents/Test/Lua/TestLua/TestLua/TestLua/Hello.lua");
//    printf("err is: %d\n", err);
//
//    lua_settop(pL, 0);
//    lua_getglobal(pL, "myName");
//
//    int isStr = lua_isstring(pL, 1);
//    if(isStr != 0)
//    {
//        const char *str = lua_tostring(pL, 1);
//        printf("myName is: %s\n", str);
//    }
//
//    lua_close(pL);
    
//----------------------------
//    lua_State *pL = luaL_newstate();
//    luaopen_base(pL);
//
//    luaL_dofile(pL, "/Users/bufuhuang/Documents/Test/Lua/TestLua/TestLua/TestLua/Hello.lua");
//    lua_settop(pL, 0);
//    lua_getglobal(pL, "helloTable");
//    lua_getglobal(pL, "helloTable1");
//
//    lua_pushstring(pL, "name");
//    lua_gettable(pL, -2);
//
//    const char* sName = lua_tostring(pL, -1);
//    printf("myName is: %s\n", sName);
//
//    lua_close(pL);
    
    //-------------------------------
    lua_State *pL = luaL_newstate();
    luaopen_base(pL);
    
    luaL_dofile(pL, "/Users/bufuhuang/Documents/Test/Lua/TestLua/TestLua/TestLua/Hello.lua");
    
    lua_settop(pL, 0);
    
    lua_getglobal(pL, "helloAdd");
    
    lua_pushnumber(pL, 10);
    lua_pushnumber(pL, 5);
    
    lua_call(pL, 2, 1);
    
    int iResult = lua_tonumber(pL, -1);
    printf("iResult is: %d\n", iResult);
    
    
    return 0;
}
