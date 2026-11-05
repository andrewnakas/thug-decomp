extern void* D_0038FC78;
extern char D_00374EF8[];
extern char D_00374F28[];
extern char D_00374F90[];

struct Ent_00253260 {
    int m0;
    int m4;
    void* m8;
};

struct Skater_00253260 {
    char pad[0x248];
    Ent_00253260* m248[8];
};

extern "C" Skater_00253260* func_0022DD38(void* self);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" bool func_001E82B8(void* params, const char* name, void** out, int required);
extern "C" int func_00103F28(const char* fmt, int a);
extern "C" void func_001E66C0(void* p, void* v);

bool Cmd_00253260(void* params, void* script)
{
    Skater_00253260* s = func_0022DD38(D_0038FC78);
    if (s) {
        int i;
        void* v;
        func_001E7E58(params, D_00374EF8, &i, 1);
        if (func_001E82B8(params, D_00374F28, &v, 1)) {
            func_00103F28(D_00374F90, i);
            func_001E66C0(s->m248[i]->m8, v);
        }
        return true;
    }
    return false;
}
