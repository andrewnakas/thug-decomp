extern char D_00371EE8[];
extern char D_00371F00[];
extern char D_00371F10[];
extern char D_00371F28[];
extern char D_00371E70[];
extern char D_00371E80[];
extern char D_00371E90[];
extern int D_0038F9D4;
extern int D_0038F9D8;
extern void* D_00392068;
extern void* D_0038FC78;
extern void* D_0039274C;
extern void* D_0038C7B0;

struct Info_002259B0 {
    void* m_other;
    void* m_rotation;
    void* m_animation;
};

struct Skater_002259B0 {
    char pad[0x248];
    Info_002259B0* m_info;
};

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" bool func_001E8180(void* params, unsigned int key, void** out, int required);
extern "C" bool func_001E81F0(void* params, char* name, void** out, int required);
extern "C" bool func_001E82B8(void* params, char* name, void** out, int required);
extern "C" void func_00225320(void* params, void* script);
extern "C" void func_00225838(void* params);
extern "C" void func_00225948(void* params);
extern "C" void func_002258B0(void* a, void* b);
extern "C" char* func_002A6070(void* a);
extern "C" void func_00202F58(char* a, void* params);
extern "C" Skater_002259B0* func_0022DD38(void* mgr);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E66C0(void* dst, void* src);
extern "C" void func_002BD080(void* a, void* params, int b);
extern "C" void* func_001895B0(void* a, unsigned int key);
extern "C" void* func_00185578(void* a, unsigned int key);
extern "C" void func_002957A0(void* a, void* params, int b);

void func_002259B0(unsigned int type, void* params, void* script)
{
    D_0038F9D8 = 0;
    switch (type) {
    case 0xB010F357:
        if (D_0038F9D4 & 1) {
            func_00103F28(D_00371EE8);
            void* p = 0;
            func_001E8180(params, 0xF55CBD13, &p, 1);
            func_00225320(p, script);
        }
        if (D_0038F9D4 & 2) {
            func_00103F28(D_00371F00);
            void* p = 0;
            func_001E8180(params, 0x14A9FBC7, &p, 1);
            func_00225838(p);
        }
        if (D_0038F9D4 & 8) {
            func_00103F28(D_00371F10);
            void* p = 0;
            func_001E8180(params, 0x12BFAC82, &p, 1);
            func_00225948(p);
            D_0038F9D8 = 1;
        }
        if (D_0038F9D4 & 4) {
            func_00103F28(D_00371F28);
            void* p = 0;
            func_001E8180(params, 0x0DF2F448, &p, 1);
            void* q = 0;
            func_001E8180(params, 0x12BFAC82, &q, 1);
            func_002258B0(p, q);
        }
        D_0038F9D4 = 0;
        break;
    case 0xCA41692D:
        func_00202F58(func_002A6070(D_00392068), params);
        break;
    case 0x61A1BC57: {
        Skater_002259B0* s = func_0022DD38(D_0038FC78);
        if (s) {
            void* other;
            func_001E81F0(params, D_00371E70, &other, 1);
            func_001E6AC8(s->m_info->m_other, other);
            void* rot;
            func_001E82B8(params, D_00371E80, &rot, 1);
            func_001E66C0(s->m_info->m_rotation, rot);
            void* anim;
            func_001E82B8(params, D_00371E90, &anim, 1);
            func_001E66C0(s->m_info->m_animation, anim);
        }
        break;
    }
    case 0x3BF882CC:
        func_002BD080(D_0039274C, params, 1);
        break;
    case 0x62896EDF:
        func_002957A0(func_00185578(func_001895B0(D_0038C7B0, 0x81F01058), 0x81F01058), params, 0);
        break;
    case 0x26C80B0D:
    case 0xFFFFFFFF:
        break;
    }
}
