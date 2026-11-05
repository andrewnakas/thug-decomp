struct Item_00252F28 {
    int m0;
    int m4;
    int m8;
};

struct Obj_00252F28 {
    char pad[0x248];
    Item_00252F28* m_items[1];
};

struct Script_00252F28 {
    char pad[0x18];
    void* m_params;
};

extern void* D_0038FC78;
extern char D_00374EF8[];
extern char D_00374F28[];

extern "C" Obj_00252F28* func_0022DD38(void* game);
extern "C" int func_001E7E58(void* params, const char* name, int* out, int req);
extern "C" void func_001E76D8(void* params, const char* name, int value);

bool Cmd_00252F28(void* params, Script_00252F28* script)
{
    Obj_00252F28* o = func_0022DD38(D_0038FC78);
    if (o) {
        int idx;
        func_001E7E58(params, D_00374EF8, &idx, 1);
        func_001E76D8(script->m_params, D_00374F28, o->m_items[idx]->m8);
        return true;
    }
    return false;
}
