struct Arr_0020D198 {
    char pad[0x8];
    int m_type;
    int m_size;
};

struct Script_0020D198 {
    char pad[0x18];
    void* m_params;
};

extern char D_0038F360[];
extern char D_003700E0[];
extern "C" int func_001E8248(void* params, unsigned int name, Arr_0020D198** out, int required);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void* func_001E9378(Arr_0020D198* arr, int i);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E7A68(void* params, unsigned int name, int type, void* value);
extern "C" void* func_001E93A0(Arr_0020D198* arr, int i);
extern "C" void func_001E7B38(void* params, unsigned int name, void* value);
extern "C" void* func_001E9270(Arr_0020D198* arr, int i);
extern "C" int func_00103F28(char* fmt, ...);

extern "C" bool func_0020D198(void* params, Script_0020D198* script)
{
    Arr_0020D198* arr = 0;
    func_001E8248(params, 0, &arr, 0);
    int index = 0;
    func_001E7E58(params, D_0038F360, &index, 0);
    func_001E6B90(script->m_params, 0xBEBFA1C6);
    if (!arr) return true;
    if (index < 0) return false;
    if (index >= arr->m_size) return false;
    switch (arr->m_type) {
    case 10: {
        void* s = func_001E6978(func_001190D0(8));
        func_001E6AC8(s, func_001E9378(arr, index));
        func_001E7A68(script->m_params, 0xBEBFA1C6, 11, s);
        break;
    }
    case 12: {
        void* p = script->m_params;
        func_001E7B38(p, 0xBEBFA1C6, func_001E93A0(arr, index));
        break;
    }
    case 1: {
        void* p = script->m_params;
        func_001E7A68(p, 0xBEBFA1C6, 1, func_001E9270(arr, index));
        break;
    }
    default:
        func_00103F28(D_003700E0, arr->m_type);
        break;
    }
    return true;
}
