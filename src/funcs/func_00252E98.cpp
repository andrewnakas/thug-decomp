struct Entry_00252E98 {
    int m_a;
    int m_b;
};

struct Mgr_00252E98 {
    char pad0[0x248];
    Entry_00252E98* m_entries[1];
};

struct Script_00252E98 {
    char pad0[0x18];
    void* m_params;
};

extern void* D_0038FC78;
extern char D_00374EF8[];
extern char D_00374F18[];

extern "C" Mgr_00252E98* func_0022DD38(void* mgr);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void func_001E76D8(void* params, const char* name, int value);

bool func_00252E98(void* params, Script_00252E98* script)
{
    Mgr_00252E98* m = func_0022DD38(D_0038FC78);
    if (m) {
        int index;
        func_001E7E58(params, D_00374EF8, &index, 1);
        func_001E76D8(script->m_params, D_00374F18, m->m_entries[index]->m_b);
        return true;
    }
    return false;
}
