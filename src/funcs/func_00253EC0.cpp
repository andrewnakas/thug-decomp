extern "C" void func_00105260(void* p, void* q);

struct Mgr_00253EC0 {
    int m0;
    int m4;
    char m8[4];
};

extern Mgr_00253EC0* D_0038C308;

struct Obj_00253EC0 {
    char pad[0x1C];
    void* m1C;
    char pad20[0x28];
    int m48;
    void Fn(int v);
};

void Obj_00253EC0::Fn(int v)
{
    m48 = v;
    func_00105260(D_0038C308->m8, m1C);
}
