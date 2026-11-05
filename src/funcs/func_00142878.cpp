class Obj_00142878 {
public:
    char pad[0x190];
    virtual ~Obj_00142878();
};

extern "C" void func_00142CF0(void* table);
extern "C" Obj_00142878* func_00142D00(void* table, int a);
extern "C" void func_00142328(Obj_00142878* o);
extern "C" void func_001429F8(void* table);

class Mgr_00142878 {
public:
    void* m0;
    void DestroyAll();
};

void Mgr_00142878::DestroyAll()
{
    func_00142CF0(m0);
    Obj_00142878* o = func_00142D00(m0, 0);
    while (o) {
        Obj_00142878* next = func_00142D00(m0, 0);
        func_00142328(o);
        delete o;
        o = next;
    }
    func_001429F8(m0);
}
