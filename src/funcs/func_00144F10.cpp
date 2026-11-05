class Obj_00144F10 {
public:
    char pad[0x70];
    virtual ~Obj_00144F10();
};

extern "C" void func_00145308(void* table);
extern "C" Obj_00144F10* func_00145318(void* table, int a);
extern "C" void func_00145250(void* table);

class Mgr_00144F10 {
public:
    void* m0;
    void DestroyAll();
};

void Mgr_00144F10::DestroyAll()
{
    func_00145308(m0);
    Obj_00144F10* o = func_00145318(m0, 0);
    while (o) {
        Obj_00144F10* next = func_00145318(m0, 0);
        delete o;
        o = next;
    }
    func_00145250(m0);
}
