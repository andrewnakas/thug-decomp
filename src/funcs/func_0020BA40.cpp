struct Arr_0020BA40 {
    char pad[0x8];
    int m_type;
    int m_size;
};

struct Pair_0020BA40 {
    int m0;
    float x, y;
};

struct Vec_0020BA40 {
    int m0;
    float x, y, z;
};

struct Script_0020BA40 {
    char pad[0x18];
    void* m_params;
};

extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8248(void* params, unsigned int name, Arr_0020BA40** out, int req);
extern "C" Arr_0020BA40* func_001E55B8(unsigned int name, int flags);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" void func_001E7200(void* s, unsigned int name, int v);
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" void func_001E70C0(void* s, unsigned int name, char* v);
extern "C" void func_001E7558(void* s, unsigned int name, float x, float y);
extern "C" void func_001E7410(void* s, unsigned int name, float x, float y, float z);
extern "C" void func_001E77D0(void* s, unsigned int name, void* v);
extern "C" void func_001E7648(void* s, unsigned int name, void* v);
extern "C" int func_001E9270(Arr_0020BA40* a, int i);
extern "C" float func_001E9298(Arr_0020BA40* a, int i);
extern "C" unsigned int func_001E9300(Arr_0020BA40* a, int i);
extern "C" char* func_001E91C0(Arr_0020BA40* a, int i);
extern "C" Pair_0020BA40* func_001E9350(Arr_0020BA40* a, int i);
extern "C" Vec_0020BA40* func_001E9328(Arr_0020BA40* a, int i);
extern "C" void* func_001E9378(Arr_0020BA40* a, int i);
extern "C" Arr_0020BA40* func_001E93A0(Arr_0020BA40* a, int i);

bool Cmd_0020BA40(void* params, Script_0020BA40* script)
{
    unsigned int name = 0;
    func_001E8398(params, 0x8F61D602, &name, 1);
    Arr_0020BA40* arr = 0;
    if (!func_001E8248(script->m_params, name, &arr, 0))
        arr = func_001E55B8(name, 1);
    int i = 0;
    func_001E7DE8(params, 0x0BA453B9, &i, 1);
    int j = 0;
    func_001E7DE8(params, 0x92AD0203, &j, 1);
    Arr_0020BA40* e = func_001E93A0(arr, i);
    switch (e->m_type) {
    case 1: {
        void* p = script->m_params;
        func_001E7200(p, 0x6820459A, func_001E9270(e, j));
        break;
    }
    case 2: {
        void* p = script->m_params;
        func_001E72B0(p, 0x6820459A, func_001E9298(e, j));
        break;
    }
    case 13: {
        void* p = script->m_params;
        func_001E7360(p, 0x6820459A, func_001E9300(e, j));
        break;
    }
    case 3:
    case 4: {
        void* p = script->m_params;
        func_001E70C0(p, 0x6820459A, func_001E91C0(e, j));
        break;
    }
    case 5: {
        Pair_0020BA40* v = func_001E9350(e, j);
        func_001E7558(script->m_params, 0x6820459A, v->x, v->y);
        break;
    }
    case 6: {
        Vec_0020BA40* v = func_001E9328(e, j);
        func_001E7410(script->m_params, 0x6820459A, v->x, v->y, v->z);
        break;
    }
    case 10: {
        void* p = script->m_params;
        func_001E77D0(p, 0x6820459A, func_001E9378(e, j));
        break;
    }
    case 12: {
        void* p = script->m_params;
        func_001E7648(p, 0x6820459A, func_001E93A0(e, j));
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
