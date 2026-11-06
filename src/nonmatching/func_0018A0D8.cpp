/* fuzzy: 86.1 */
struct Obj_0018A0D8 {
    char pad0[0x18];
    unsigned int m18;
};

struct Script_0018A0D8 {
    char pad0[0xBC];
    Obj_0018A0D8* mBC;
    char padC0[0x8];
    int mC8;
};

struct Array_0018A0D8 {
    char pad0[0xC];
    unsigned int mC;
};

struct Node_0018A0D8 {
    char pad0[0x8];
    unsigned int m8;
};

extern void* D_00389A30;
extern int D_0038C7B0;

extern "C" unsigned int func_0012E438(void* mgr, void* params, unsigned int name);
extern "C" bool func_001E8180(void* params, unsigned int name, void* out, int req);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" bool func_001E8248(void* params, unsigned int name, Array_0018A0D8** out, int req);
extern "C" unsigned int func_001E9300(Array_0018A0D8* a, int index);
extern "C" Node_0018A0D8* func_001E6E90(void* list, Node_0018A0D8* prev);
extern "C" void func_00189BB0(int h, int v);
extern "C" void func_00189750(int h, unsigned int name, unsigned int a, unsigned int b, int v, int flag);

static inline unsigned int Resolve_0018A0D8(unsigned int r, Script_0018A0D8* s)
{
    unsigned int id = r;
    if (id) {
        if (id == 0x36B2EE74) {
            id = 0x36B2EE74;
        }
    } else {
        id = 0x36B2EE74;
        if (s->mBC) {
            id = s->mBC->m18;
        }
    }
    return id;
}

bool Cmd_0018A0D8(void* params, Script_0018A0D8* script)
{
    void* mgr = D_00389A30;
    unsigned int a = Resolve_0018A0D8(func_0012E438(mgr, params, 0xB990D003), script);
    unsigned int b = Resolve_0018A0D8(func_0012E438(mgr, params, 0xA075808C), script);
    int v = 0;
    func_001E8180(params, 0x520C0C9C, &v, 0);
    int flag = func_001E8708(params, 0x640E830A);
    int h = D_0038C7B0;
    unsigned int name;
    Array_0018A0D8* arr;
    void* list;
    if (func_001E8398(params, 0x7321A8D6, &name, 0)) {
        func_00189BB0(h, script->mC8);
        func_00189750(h, name, a, b, v, flag);
    } else if (func_001E8248(params, 0x7321A8D6, &arr, 0)) {
        unsigned int n = arr->mC;
        for (unsigned int i = 0; i < n; i++) {
            func_00189BB0(h, script->mC8);
            func_00189750(h, func_001E9300(arr, i), a, b, v, flag);
        }
    } else if (func_001E8180(params, 0x7321A8D6, &list, 0)) {
        for (Node_0018A0D8* n = func_001E6E90(list, 0); n; n = func_001E6E90(list, n)) {
            func_00189BB0(h, script->mC8);
            func_00189750(h, n->m8, a, b, v, flag);
        }
    }
    return true;
}
