struct Holder_002CABA0 {
    void* m0;
};

struct Obj_002CABA0 {
    char pad0[0x18];
    void* m18;
};

extern Holder_002CABA0* D_0039274C;
extern char D_0037AD38[];
extern "C" int func_002B76D0(void* p);
extern "C" void func_001E7268(void* p, char* name, int v);

bool func_002CABA0(void* params, Obj_002CABA0* o)
{
    void* p = o->m18;
    func_001E7268(p, D_0037AD38, func_002B76D0(D_0039274C->m0));
    return true;
}
