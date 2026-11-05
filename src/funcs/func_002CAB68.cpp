struct Data_002CAB68 {
    char pad0[0x28];
    int m28;
};

struct Holder_002CAB68 {
    Data_002CAB68* m0;
};

struct Obj_002CAB68 {
    char pad0[0x18];
    void* m18;
};

extern Holder_002CAB68* D_0039274C;
extern char D_0037AD28[];
extern "C" void func_001E7268(void* p, char* name, int v);

bool func_002CAB68(void* params, Obj_002CAB68* o)
{
    func_001E7268(o->m18, D_0037AD28, D_0039274C->m0->m28);
    return true;
}
