extern void* D_0038FC78;
extern char D_00374EF8[];
extern char D_00374F08[];
extern char D_00374F18[];
extern char D_00374F28[];

struct Entry_00252D50 {
    void* m_0;
    void* m_4;
    void* m_8;
};

struct List_00252D50 {
    char pad[0x248];
    Entry_00252D50* m_entries[1];
};

struct Script_00252D50 {
    char pad[0x18];
    void* m_params;
};

extern "C" List_00252D50* func_0022DD38(void* game);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void func_001E7860(void* params, const char* name, void* value);
extern "C" void func_001E76D8(void* params, const char* name, void* value);

bool Cmd_00252D50(void* params, Script_00252D50* script)
{
    List_00252D50* list = func_0022DD38(D_0038FC78);
    if (list) {
        int index;
        func_001E7E58(params, D_00374EF8, &index, 1);
        Entry_00252D50* e = list->m_entries[index];
        func_001E7860(script->m_params, D_00374F08, e->m_0);
        func_001E76D8(script->m_params, D_00374F18, e->m_4);
        func_001E76D8(script->m_params, D_00374F28, e->m_8);
        return true;
    }
    return false;
}
