struct Arr_0020D560 {
    char pad[0x8];
    int m_type;
    int m_size;
};

struct Script_0020D560 {
    char pad[0x18];
    void* m_params;
};

extern char D_003701C8[];

extern "C" void func_001E6B90(void* s, unsigned int name);
extern "C" int func_001E8248(void* params, unsigned int name, Arr_0020D560** out, int req);
extern "C" int func_00100030(int n);
extern "C" void func_001E7200(void* s, unsigned int name, int v);
extern "C" void func_001E77D0(void* s, unsigned int name, void* v);
extern "C" void func_001E7648(void* s, unsigned int name, void* v);
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" void* func_001E9378(Arr_0020D560* a, int i);
extern "C" void* func_001E93A0(Arr_0020D560* a, int i);
extern "C" int func_001E9270(Arr_0020D560* a, int i);
extern "C" float func_001E9298(Arr_0020D560* a, int i);
extern "C" unsigned int func_001E9300(Arr_0020D560* a, int i);
extern "C" char* func_001E4C58(unsigned char type);
extern "C" void func_00103F28(const char* fmt, ...);

bool Cmd_0020D560(void* params, Script_0020D560* script)
{
    func_001E6B90(script->m_params, 0xBEBFA1C6);
    func_001E6B90(script->m_params, 0x7F8C98FE);
    Arr_0020D560* arr = 0;
    func_001E8248(params, 0, &arr, 0);
    if (!arr)
        return false;
    if (!arr->m_size)
        return false;
    int i = func_00100030(arr->m_size);
    func_001E7200(script->m_params, 0x7F8C98FE, i);
    switch (arr->m_type) {
    case 10:
        {
            void* p = script->m_params;
            func_001E77D0(p, 0xBEBFA1C6, func_001E9378(arr, i));
        }
        break;
    case 12:
        {
            void* p = script->m_params;
            func_001E7648(p, 0xBEBFA1C6, func_001E93A0(arr, i));
        }
        break;
    case 1:
        {
            void* p = script->m_params;
            func_001E7200(p, 0xBEBFA1C6, func_001E9270(arr, i));
        }
        break;
    case 2:
        {
            void* p = script->m_params;
            func_001E72B0(p, 0xBEBFA1C6, func_001E9298(arr, i));
        }
        break;
    case 13:
        {
            void* p = script->m_params;
            func_001E7360(p, 0xBEBFA1C6, func_001E9300(arr, i));
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
    default:
        func_00103F28(D_003701C8, func_001E4C58(arr->m_type));
        break;
    }
    return true;
}
