struct Arr_0020BEF8 {
    char pad[0x8];
    int m_type;
    unsigned int m_size;
    unsigned int GetSize() { return m_size; }
};

struct Pair_0020BEF8 {
    int m0;
    float x, y;
};

struct Vec_0020BEF8 {
    int m0;
    float x, y, z;
};

struct Script_0020BEF8 {
    char pad[0x18];
    void* m_params;
};

extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8248(void* params, unsigned int name, Arr_0020BEF8** out, int req);
extern "C" Arr_0020BEF8* func_001E55B8(unsigned int name, int flags);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" void func_001E7200(void* s, unsigned int name, int v);
extern "C" void func_001E72B0(void* s, unsigned int name, float v);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" void func_001E70C0(void* s, unsigned int name, char* v);
extern "C" void func_001E7558(void* s, unsigned int name, float x, float y);
extern "C" void func_001E7410(void* s, unsigned int name, float x, float y, float z);
extern "C" void func_001E77D0(void* s, unsigned int name, void* v);
extern "C" void func_001E7648(void* s, unsigned int name, void* v);
extern "C" int func_001E9270(Arr_0020BEF8* a, int i);
extern "C" float func_001E9298(Arr_0020BEF8* a, int i);
extern "C" unsigned int func_001E9300(Arr_0020BEF8* a, int i);
extern "C" char* func_001E91C0(Arr_0020BEF8* a, int i);
extern "C" Pair_0020BEF8* func_001E9350(Arr_0020BEF8* a, int i);
extern "C" Vec_0020BEF8* func_001E9328(Arr_0020BEF8* a, int i);
extern "C" void* func_001E9378(Arr_0020BEF8* a, int i);
extern "C" Arr_0020BEF8* func_001E93A0(Arr_0020BEF8* a, int i);

bool Cmd_0020BEF8(void* params, Script_0020BEF8* script)
{
    unsigned int name = 0;
    func_001E8398(params, 0x8F61D602, &name, 1);
    Arr_0020BEF8* arr = 0;
    if (!func_001E8248(script->m_params, name, &arr, 0))
        arr = func_001E55B8(name, 1);
    Arr_0020BEF8* path = 0;
    func_001E8248(script->m_params, 0xFFC8E484, &path, 1);
    unsigned int i;
    for (i = 0; i < path->GetSize() - 1; i++) {
        int k = func_001E9270(path, i);
        arr = func_001E93A0(arr, k);
    }
    int j = func_001E9270(path, i);
    switch (arr->m_type) {
    case 1: {
        void* p = script->m_params;
        func_001E7200(p, 0x6820459A, func_001E9270(arr, j));
        break;
    }
    case 2: {
        void* p = script->m_params;
        func_001E72B0(p, 0x6820459A, func_001E9298(arr, j));
        break;
    }
    case 13: {
        void* p = script->m_params;
        func_001E7360(p, 0x6820459A, func_001E9300(arr, j));
        break;
    }
    case 3:
    case 4: {
        void* p = script->m_params;
        func_001E70C0(p, 0x6820459A, func_001E91C0(arr, j));
        break;
    }
    case 5: {
        Pair_0020BEF8* v = func_001E9350(arr, j);
        func_001E7558(script->m_params, 0x6820459A, v->x, v->y);
        break;
    }
    case 6: {
        Vec_0020BEF8* v = func_001E9328(arr, j);
        func_001E7410(script->m_params, 0x6820459A, v->x, v->y, v->z);
        break;
    }
    case 10: {
        void* p = script->m_params;
        func_001E77D0(p, 0x6820459A, func_001E9378(arr, j));
        break;
    }
    case 12: {
        void* p = script->m_params;
        func_001E7648(p, 0x6820459A, func_001E93A0(arr, j));
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
