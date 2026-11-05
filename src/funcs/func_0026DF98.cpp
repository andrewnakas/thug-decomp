extern char D_00391450[];
extern "C" void* func_001046B0(int size);
extern "C" void func_0026E068(void* self, char* a, int b, int c);

struct Obj_0026DF98 {
    int m0;
    void* m4;
    Obj_0026DF98* Init();
};

Obj_0026DF98* Obj_0026DF98::Init()
{
    m4 = func_001046B0(5);
    func_0026E068(this, D_00391450, 1000, 0);
    return this;
}
