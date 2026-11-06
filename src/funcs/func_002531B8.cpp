extern int D_0038FC78;
extern char D_00374EF8[];
extern char D_00374F18[];
extern char D_00374F70[];

struct Item_002531B8 {
    int m0;
    void* m4;
};

struct Mgr_002531B8 {
    char m_pad[0x248];
    Item_002531B8* m_items[1];
};

extern "C" Mgr_002531B8* func_0022DD38(int id);
extern "C" bool func_001E7E58(void* params, char* name, int* out, int assert);
extern "C" bool func_001E82B8(void* params, char* name, void** out, int assert);
extern "C" int func_00103F28(char* fmt, ...);
extern "C" void func_001E66C0(void* a, void* b);

bool Cmd_002531B8(void* params, void* script)
{
    Mgr_002531B8* m = func_0022DD38(D_0038FC78);
    if (m) {
        int idx;
        void* p;
        func_001E7E58(params, D_00374EF8, &idx, 1);
        if (func_001E82B8(params, D_00374F18, &p, 1)) {
            func_00103F28(D_00374F70, idx);
            func_001E66C0(m->m_items[idx]->m4, p);
        }
        return true;
    }
    return false;
}
