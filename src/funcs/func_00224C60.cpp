extern char D_0038F9D0[];
extern char D_00371EA0[];
extern char D_00371EB0[];
extern void* D_00392068;
extern void* D_0038FC78;
extern void* D_0038C7B0;

struct Arr_00224C60 {
    char pad[0xC];
    int m_size;
};

struct Obj28_00224C60 {
    char pad[0x28];
    int m_28;
};

struct Mgr_00224C60 {
    Obj28_00224C60* m_0;
};

extern Mgr_00224C60* D_0039274C;

struct Skater_00224C60 {
    char pad[0x248];
    void** m_info;
};

extern "C" bool func_001E8180(void* params, unsigned int key, void** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int key, int* out, int required);
extern "C" bool func_001E7C80(void* params, unsigned int key, char** out, int required);
extern "C" bool func_001E8248(void* params, unsigned int key, Arr_00224C60** out, int required);
extern "C" bool func_001E81F0(void* params, char* name, void** out, int required);
extern "C" bool func_001E7D18(void* params, char* name, char** out, int required);
extern "C" void func_001E7200(void* params, unsigned int key, int value);
extern "C" void func_001E7360(void* params, unsigned int key, unsigned int value);
extern "C" void func_001E7138(void* params, char* name, char* value);
extern "C" void func_001E70C0(void* params, unsigned int key, char* value);
extern "C" int func_001E9038(Arr_00224C60* a);
extern "C" void func_002C0F48(Mgr_00224C60* m, int a, int* b, int* c, unsigned short* d, unsigned int* e, int* f, int* g);
extern "C" void* func_00240850();
extern "C" void* func_0023EFA0(void* a);
extern "C" char* func_002A6070(void* a);
extern "C" Skater_00224C60* func_0022DE70(void* mgr, int i);
extern "C" void* func_001895B0(void* a, unsigned int key);
extern "C" void* func_00185578(void* a, unsigned int key);
extern "C" int func_00295DF0(void* a);
extern "C" void func_002BCDF8(Mgr_00224C60* m);
extern "C" int func_002BCE20(Mgr_00224C60* m, int a);

void func_00224C60(void* out, unsigned int type, void* src)
{
    if (src) {
        switch (type) {
        case 0xB010F357: {
            void* a = 0;
            func_001E8180(src, 0x14A9FBC7, &a, 1);
            void* b = 0;
            func_001E8180(a, 0xAC7C2B62, &b, 1);
            void* c = 0;
            func_001E8180(b, 0x23D4170A, &c, 1);
            int v = 0;
            func_001E7DE8(c, 0xF884773C, &v, 0);
            func_001E7200(out, 0xF884773C, v);
            void* d = 0;
            func_001E8180(src, 0x12BFAC82, &d, 1);
            void* e = 0;
            func_001E8180(d, 0x0A7BE964, &e, 1);
            void* f = 0;
            func_001E8180(e, 0x3476CEA8, &f, 1);
            int w = 0;
            func_001E7DE8(f, 0x3F813177, &w, 0);
            func_001E7200(out, 0x3F813177, w);
            char* s = D_0038F9D0;
            func_001E7C80(f, 0x2AB66CB8, &s, 0);
            func_001E70C0(out, 0xA1DC81F9, s);
            break;
        }
        case 0xCA41692D:
            func_001E7138(out, D_00371EA0, D_0038F9D0);
            break;
        case 0x61A1BC57: {
            void* a = 0;
            func_001E8180(src, 0x4137CB14, &a, 1);
            char* s = D_0038F9D0;
            func_001E7C80(a, 0xA1DC81F9, &s, 1);
            func_001E70C0(out, 0xA1DC81F9, s);
            break;
        }
        case 0x3BF882CC: {
            void* a;
            Arr_00224C60* arr;
            arr = 0;
            a = 0;
            int n = 0;
            func_001E8180(src, 0xD8EB825E, &a, 0);
            if (a) {
                func_001E8248(a, 0x38DBE1D0, &arr, 0);
                if (arr)
                    n = arr->m_size;
            }
            func_001E7200(out, 0xE1EC606F, n);
            int v = 1;
            func_001E7DE8(src, 0xB7E39B53, &v, 0);
            func_001E7200(out, 0xB7E39B53, v);
            Arr_00224C60* list = 0;
            func_001E8248(src, 0x337C5289, &list, 1);
            int r0 = 0;
            int r1 = 0;
            unsigned short r2 = 0;
            unsigned int r3 = 0;
            int r4 = 0;
            int r5 = 0;
            Mgr_00224C60* m = D_0039274C;
            func_002C0F48(m, func_001E9038(list), &r0, &r1, &r2, &r3, &r4, &r5);
            func_001E7200(out, 0xE6121ED0, r0);
            func_001E7200(out, 0xFFF3DC35, r1);
            func_001E7200(out, 0x688A18F7, r2);
            func_001E7360(out, 0x4C72ED98, r3);
            func_001E7200(out, 0x73E5BAD0, r4);
            func_001E7200(out, 0xFE82614D, r5);
            break;
        }
        case 0x62896EDF: {
            int n = 0;
            Arr_00224C60* arr = 0;
            func_001E8248(src, 0x38DBE1D0, &arr, 0);
            if (arr)
                n = arr->m_size;
            func_001E7200(out, 0xE1EC606F, n);
            break;
        }
        case 0x26C80B0D:
        case 0xFFFFFFFF:
            break;
        }
    } else {
        switch (type) {
        case 0xB010F357: {
            void* p = func_0023EFA0(func_00240850());
            void* c = 0;
            func_001E8180(p, 0x23D4170A, &c, 0);
            int v = 0;
            func_001E7DE8(c, 0xF884773C, &v, 0);
            func_001E7200(out, 0xF884773C, v);
            break;
        }
        case 0xCA41692D: {
            char* p = func_002A6070(D_00392068) + 4;
            void* a = 0;
            func_001E81F0(p, D_00371EA0, &a, 0);
            char* s = D_0038F9D0;
            func_001E7D18(a, D_00371EB0, &s, 0);
            func_001E7138(out, D_00371EA0, s);
            break;
        }
        case 0x61A1BC57: {
            void* info = *func_0022DE70(D_0038FC78, 0)->m_info;
            char* s = D_0038F9D0;
            func_001E7C80(info, 0xA1DC81F9, &s, 1);
            func_001E70C0(out, 0xA1DC81F9, s);
            break;
        }
        case 0x62896EDF:
        case 0x3BF882CC:
            func_001E7200(out, 0xE1EC606F,
                          func_00295DF0(func_00185578(func_001895B0(D_0038C7B0, 0x81F01058), 0x81F01058)));
            if (type == 0x3BF882CC) {
                func_001E7200(out, 0xB7E39B53, D_0039274C->m_0->m_28);
                int r0 = 0;
                int r1 = 0;
                unsigned short r2 = 0;
                unsigned int r3 = 0;
                int r4 = 0;
                int r5 = 0;
                func_002BCDF8(D_0039274C);
                Mgr_00224C60* m = D_0039274C;
                func_002C0F48(m, func_002BCE20(m, 0), &r0, &r1, &r2, &r3, &r4, &r5);
                func_001E7200(out, 0xE6121ED0, r0);
                func_001E7200(out, 0xFFF3DC35, r1);
                func_001E7200(out, 0x688A18F7, r2);
                func_001E7360(out, 0x4C72ED98, r3);
                func_001E7200(out, 0x73E5BAD0, r4);
                func_001E7200(out, 0xFE82614D, r5);
            }
            break;
        case 0x26C80B0D:
        case 0xFFFFFFFF:
            break;
        }
    }
}
