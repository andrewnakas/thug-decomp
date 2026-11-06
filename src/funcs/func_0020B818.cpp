struct Script_0020B818 { char pad[0x18]; void* m18; };
struct Val_0020B818 {
    unsigned char m0;
    unsigned char m1;
    char pad[6];
    union { int i; float f; } m8;
};
struct Arr_0020B818 { char pad[8]; int m8; };
extern char D_0036FED0[];
extern char D_0038F360[];
extern "C" int func_001E84E8(void* params, char* name, int* out, int req);
extern "C" int func_001E8248(void* p, int id, Arr_0020B818** out, int req);
extern "C" int func_001E7E58(void* params, char* name, int* out, int req);
extern "C" void* func_001E6DD0(void* params, unsigned int name);
extern "C" void func_001EAFA8(void* p);
extern "C" void* func_001E8CD0(int size);
extern "C" Val_0020B818* func_001E4ED8(void* mem);
extern "C" void func_001E6360(Val_0020B818* v, void* p);
extern "C" void func_001E90A8(Arr_0020B818* a, int i, int v);
extern "C" void func_001E90D0(Arr_0020B818* a, int i, float v);
extern "C" void func_001E90F8(Arr_0020B818* a, int i, int v);
extern "C" void* func_001E91C0(Arr_0020B818* a, int i);
extern "C" void func_001E4E58(void* p);
extern "C" void* func_001E9350(Arr_0020B818* a, int i);
extern "C" void func_001E8AC0(void* p);
extern "C" void* func_001E9328(Arr_0020B818* a, int i);
extern "C" void func_001E8B70(void* p);
extern "C" void* func_001E9378(Arr_0020B818* a, int i);
extern "C" void func_001E6AE8(void* p, int n);
extern "C" void* func_001E93A0(Arr_0020B818* a, int i);
extern "C" void func_001E6518(void* p);
extern "C" void func_001E8DE8(void* p, int n);
extern "C" int* func_001E9038(Arr_0020B818* a);
extern "C" void func_001E8D20(Val_0020B818* v);

bool Cmd_0020B818(void* params, Script_0020B818* script)
{
    int id = 0;
    func_001E84E8(params, D_0036FED0, &id, 1);
    Arr_0020B818* arr = 0;
    func_001E8248(script->m18, id, &arr, 1);
    int index = 0;
    func_001E7E58(params, D_0038F360, &index, 1);
    void* src = func_001E6DD0(params, 0x4B40630D);
    func_001EAFA8(src);
    Val_0020B818* v = func_001E4ED8(func_001E8CD0(16));
    func_001E6360(v, src);
    switch (arr->m8) {
    case 1:
        func_001E90A8(arr, index, v->m8.i);
        break;
    case 2:
        if (v->m1 == 2) {
            func_001E90D0(arr, index, v->m8.f);
        } else {
            func_001E90D0(arr, index, (float)v->m8.i);
        }
        break;
    case 13:
        func_001E90F8(arr, index, v->m8.i);
        break;
    case 3:
    case 4:
        func_001E4E58(func_001E91C0(arr, index));
        goto store;
    case 5:
        func_001E8AC0(func_001E9350(arr, index));
        goto store;
    case 6:
        func_001E8B70(func_001E9328(arr, index));
        goto store;
    case 10: {
        void* p = func_001E9378(arr, index);
        if (p) func_001E6AE8(p, 3);
        goto store;
    }
    case 12: {
        void* p = func_001E93A0(arr, index);
        func_001E6518(p);
        if (p) func_001E8DE8(p, 3);
    }
    store:
        func_001E9038(arr)[index] = v->m8.i;
        break;
    }
    v->m8.i = 0;
    func_001E8D20(v);
    return true;
}
