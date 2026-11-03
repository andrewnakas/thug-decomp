extern void* D_0038FC78;
extern char D_00374EF8[];
extern char D_00374F08[];
extern char D_00374F18[];
extern char D_00374F28[];
extern char D_00374F38[];
extern char D_00374F58[];
extern char D_00374F70[];
extern char D_00374F90[];

struct CAT_00252FB8 {
    void* m_info;
    void* m_rotations;
    void* m_animations;
};

struct Skater_00252FB8 {
    char m_pad[0x248];
    CAT_00252FB8* m_tricks[2];
};

extern "C" Skater_00252FB8* func_0022DD38(void* mgr);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" bool func_001E81F0(void* params, const char* name, void** out, int required);
extern "C" bool func_001E82B8(void* params, const char* name, void** out, int required);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E66C0(void* dst, void* src);

bool Cmd_StoreCAT_00252FB8(void* params)
{
    Skater_00252FB8* skater = func_0022DD38(D_0038FC78);
    if (skater) {
        int index;
        func_001E7E58(params, D_00374EF8, &index, 1);
        if (!skater->m_tricks[1]) {
            func_00103F28(D_00374F38);
        } else {
            void* info;
            if (func_001E81F0(params, D_00374F08, &info, 1)) {
                func_00103F28(D_00374F58, index);
                func_001E6AC8(skater->m_tricks[index]->m_info, info);
            }
            void* rot;
            if (func_001E82B8(params, D_00374F18, &rot, 1)) {
                func_00103F28(D_00374F70, index);
                func_001E66C0(skater->m_tricks[index]->m_rotations, rot);
            }
            void* anim;
            if (func_001E82B8(params, D_00374F28, &anim, 1)) {
                func_00103F28(D_00374F90, index);
                func_001E66C0(skater->m_tricks[index]->m_animations, anim);
            }
            return true;
        }
    }
    return false;
}
