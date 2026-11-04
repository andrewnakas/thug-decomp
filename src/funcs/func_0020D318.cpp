struct Array_0020D318 {
    char m_pad[0x8];
    int m_type;
    int m_size;
};

struct Script_0020D318 {
    char m_pad[0x18];
    void* m_params;
};

extern char D_00370148[];

extern "C" int func_001E8248(void* params, unsigned int name, Array_0020D318** out, int req);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_001E72B0(void* params, unsigned int name, float v);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E70C0(void* params, unsigned int name, char* s);
extern "C" void func_001E7180(void* params, unsigned int name, char* s);
extern "C" void func_001E77D0(void* params, unsigned int name, void* value);
extern "C" void func_001E7648(void* params, unsigned int name, Array_0020D318* value);
extern "C" int func_001E9270(Array_0020D318* a, int i);
extern "C" float func_001E9298(Array_0020D318* a, int i);
extern "C" unsigned int func_001E9300(Array_0020D318* a, int i);
extern "C" char* func_001E91C0(Array_0020D318* a, int i);
extern "C" char* func_001E9218(Array_0020D318* a, int i);
extern "C" void* func_001E9378(Array_0020D318* a, int i);
extern "C" Array_0020D318* func_001E93A0(Array_0020D318* a, int i);
extern "C" char* func_001E4C58(unsigned char type);
extern "C" int func_00103F28(char* fmt, ...);

bool ScriptCmd_0020D318(void* params, Script_0020D318* script)
{
    Array_0020D318* arr = 0;
    func_001E8248(params, 0, &arr, 0);
    int idx = -1;
    func_001E7DE8(script->m_params, 0x7F8C98FE, &idx, 0);
    func_001E6B90(script->m_params, 0x7F8C98FE);
    func_001E6B90(script->m_params, 0xBEBFA1C6);
    if (!arr) {
        return false;
    }
    int size = arr->m_size;
    if (idx < 0) {
        idx = 0;
        if (size == 0) {
            return false;
        }
    } else {
        idx++;
        if (idx >= size) {
            return false;
        }
    }
    func_001E7200(script->m_params, 0x7F8C98FE, idx);
    switch (arr->m_type) {
    case 10: {
        void* p = script->m_params;
        func_001E77D0(p, 0xBEBFA1C6, func_001E9378(arr, idx));
        break;
    }
    case 12: {
        void* p = script->m_params;
        func_001E7648(p, 0xBEBFA1C6, func_001E93A0(arr, idx));
        break;
    }
    case 1: {
        void* p = script->m_params;
        func_001E7200(p, 0xBEBFA1C6, func_001E9270(arr, idx));
        break;
    }
    case 2: {
        void* p = script->m_params;
        func_001E72B0(p, 0xBEBFA1C6, func_001E9298(arr, idx));
        break;
    }
    case 13: {
        void* p = script->m_params;
        func_001E7360(p, 0xBEBFA1C6, func_001E9300(arr, idx));
        break;
    }
    case 3: {
        void* p = script->m_params;
        func_001E70C0(p, 0xBEBFA1C6, func_001E91C0(arr, idx));
        break;
    }
    case 4: {
        void* p = script->m_params;
        func_001E7180(p, 0xBEBFA1C6, func_001E9218(arr, idx));
        break;
    }
    default:
        func_00103F28(D_00370148, func_001E4C58(arr->m_type));
        break;
    }
    return true;
}
