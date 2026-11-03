extern char D_00371E70[];
extern char D_00371E80[];
extern char D_00371E90[];
extern void* D_00392068;
extern void* D_0038FC78;
extern void* D_0039274C;
extern void* D_0038C7B0;

struct Info_00224A50 {
    void* m_other;
    void* m_rotation;
    void* m_animation;
};

struct Skater_00224A50 {
    char pad[0x248];
    Info_00224A50* m_info;
};

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_00224630(void* params);
extern "C" void func_00224978(void* params);
extern "C" void func_002249B8(void* params);
extern "C" void func_00224A18(void* params);
extern "C" void func_001E78A8(void* params, unsigned int key, void* value);
extern "C" char* func_002A6070(void* a);
extern "C" void func_001E6AC8(void* params, char* s);
extern "C" Skater_00224A50* func_0022DE70(void* mgr, int i);
extern "C" void func_001E7860(void* params, char* name, void* value);
extern "C" void func_001E76D8(void* params, char* name, void* value);
extern "C" void func_002BCF50(void* a, void* params);
extern "C" void* func_001895B0(void* a, unsigned int key);
extern "C" void* func_00185578(void* a, unsigned int key);
extern "C" void func_00295358(void* a, void* params);

void func_00224A50(unsigned int type, void* params)
{
    void* mgr = D_0038FC78;
    switch (type) {
    case 0xB010F357: {
        void* p = func_001E6978(func_001190D0(8));
        func_00224630(p);
        func_001E78A8(params, 0xF55CBD13, p);
        p = func_001E6978(func_001190D0(8));
        func_00224978(p);
        func_001E78A8(params, 0x14A9FBC7, p);
        p = func_001E6978(func_001190D0(8));
        func_002249B8(p);
        func_001E78A8(params, 0x0DF2F448, p);
        p = func_001E6978(func_001190D0(8));
        func_00224A18(p);
        func_001E78A8(params, 0x12BFAC82, p);
        break;
    }
    case 0xCA41692D:
        func_001E6AC8(params, func_002A6070(D_00392068) + 4);
        break;
    case 0x61A1BC57: {
        Info_00224A50* info = func_0022DE70(mgr, 0)->m_info;
        func_001E7860(params, D_00371E70, info->m_other);
        func_001E76D8(params, D_00371E80, info->m_rotation);
        func_001E76D8(params, D_00371E90, info->m_animation);
        break;
    }
    case 0x3BF882CC:
        func_002BCF50(D_0039274C, params);
        break;
    case 0x62896EDF:
        func_00295358(func_00185578(func_001895B0(D_0038C7B0, 0x81F01058), 0x81F01058), params);
        break;
    case 0x26C80B0D:
    case 0xFFFFFFFF:
        break;
    }
}
