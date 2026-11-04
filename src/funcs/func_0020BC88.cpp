struct Vec3_0020BC88 {
    int m_0;
    float x;
    float y;
    float z;
};

struct Vec2_0020BC88 {
    int m_0;
    float x;
    float y;
};

struct Array_0020BC88 {
    char m_pad[0x8];
    int m_type;
};

struct Script_0020BC88 {
    char m_pad[0x18];
    void* m_params;
};

extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8248(void* params, unsigned int name, Array_0020BC88** out, int req);
extern "C" Array_0020BC88* func_001E55B8(unsigned int id, int v);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" Array_0020BC88* func_001E93A0(Array_0020BC88* a, int i);
extern "C" int func_001E9270(Array_0020BC88* a, int i);
extern "C" float func_001E9298(Array_0020BC88* a, int i);
extern "C" unsigned int func_001E9300(Array_0020BC88* a, int i);
extern "C" char* func_001E91C0(Array_0020BC88* a, int i);
extern "C" Vec2_0020BC88* func_001E9350(Array_0020BC88* a, int i);
extern "C" Vec3_0020BC88* func_001E9328(Array_0020BC88* a, int i);
extern "C" void* func_001E9378(Array_0020BC88* a, int i);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_001E72B0(void* params, unsigned int name, float v);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);
extern "C" void func_001E70C0(void* params, unsigned int name, char* s);
extern "C" void func_001E7558(void* params, unsigned int name, float x, float y);
extern "C" void func_001E7410(void* params, unsigned int name, float x, float y, float z);
extern "C" void func_001E77D0(void* params, unsigned int name, void* value);
extern "C" void func_001E7648(void* params, unsigned int name, Array_0020BC88* value);

bool ScriptCmd_0020BC88(void* params, Script_0020BC88* script)
{
    unsigned int name = 0;
    func_001E8398(params, 0x8F61D602, &name, 1);
    Array_0020BC88* arr = 0;
    if (!func_001E8248(script->m_params, name, &arr, 0)) {
        arr = func_001E55B8(name, 1);
    }
    int i0 = 0;
    func_001E7DE8(params, 0x0BA453B9, &i0, 1);
    int i1 = 0;
    func_001E7DE8(params, 0x92AD0203, &i1, 1);
    int i2 = 0;
    func_001E7DE8(params, 0xE5AA3295, &i2, 1);
    Array_0020BC88* a = func_001E93A0(func_001E93A0(arr, i0), i1);
    switch (a->m_type) {
    case 1: {
        void* p = script->m_params;
        func_001E7200(p, 0x6820459A, func_001E9270(a, i2));
        break;
    }
    case 2: {
        void* p = script->m_params;
        func_001E72B0(p, 0x6820459A, func_001E9298(a, i2));
        break;
    }
    case 13: {
        void* p = script->m_params;
        func_001E7360(p, 0x6820459A, func_001E9300(a, i2));
        break;
    }
    case 3:
    case 4: {
        void* p = script->m_params;
        func_001E70C0(p, 0x6820459A, func_001E91C0(a, i2));
        break;
    }
    case 5: {
        Vec2_0020BC88* v = func_001E9350(a, i2);
        func_001E7558(script->m_params, 0x6820459A, v->x, v->y);
        break;
    }
    case 6: {
        Vec3_0020BC88* v = func_001E9328(a, i2);
        func_001E7410(script->m_params, 0x6820459A, v->x, v->y, v->z);
        break;
    }
    case 10: {
        void* p = script->m_params;
        func_001E77D0(p, 0x6820459A, func_001E9378(a, i2));
        break;
    }
    case 12: {
        void* p = script->m_params;
        func_001E7648(p, 0x6820459A, func_001E93A0(a, i2));
        break;
    }
    case 7:
    case 8:
    case 9:
    case 11:
        break;
    }
    return true;
}
