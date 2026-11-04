struct Heap_002B4AE0 {
    char pad0[0xF4];
    int mF4;
};

extern Heap_002B4AE0* D_00388A70;
extern char* D_0038C308;

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_00104968(void* p);
extern "C" void func_00105260(void* list, void* p);

struct Obj_002B4AE0 {
    char pad[0xA8];
    void* mA8;
    bool Load();
};

extern "C" int func_002A1A18(Obj_002B4AE0* o);
extern "C" void func_002A3950(Obj_002B4AE0* o);
extern "C" int func_002A2BD0(Obj_002B4AE0* o);

bool Obj_002B4AE0::Load()
{
    char* g = D_0038C308;
    if (func_002A1A18(this)) {
        func_002A3950(this);
        func_0010A950(D_00388A70, D_00388A70->mF4);
        int r = func_002A2BD0(this);
        func_0010A9B0(D_00388A70);
        if (!r)
            return false;
        if (!func_00104968(mA8))
            func_00105260(g + 8, mA8);
    }
    return true;
}
