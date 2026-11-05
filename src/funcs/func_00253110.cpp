extern "C" void* func_0022DD38(int a);
extern "C" int func_001E7E58(void* params, char* name, int* out, int req);
extern "C" int func_001E81F0(void* params, char* name, void** out, int req);
extern "C" int func_00103F28(char* fmt, ...);
extern "C" void func_001E6AC8(void* a, void* b);
extern int D_0038FC78;
extern char D_00374EF8[];
extern char D_00374F08[];
extern char D_00374F58[];

struct Trick_00253110 {
    void* m_0;
};

struct Obj_00253110 {
    char pad0[0x248];
    Trick_00253110* m_tricks[1];
};

bool Cmd_00253110(void* params)
{
    Obj_00253110* o = (Obj_00253110*)func_0022DD38(D_0038FC78);
    if (o) {
        int idx;
        void* p;
        func_001E7E58(params, D_00374EF8, &idx, 1);
        if (func_001E81F0(params, D_00374F08, &p, 1)) {
            func_00103F28(D_00374F58, idx);
            func_001E6AC8(o->m_tricks[idx]->m_0, p);
        }
        return true;
    }
    return false;
}
