extern "C" void func_0026E208(void* p, void* a);
extern "C" void func_0026E4B8(void* p, void* a);

struct Obj_0026E9C0 {
    int m0;
    void* m4;
    void* m8;
    void* mC;
    void* m10;
    void* m14;
    void* m18;
    void Run(void* a);
};

void Obj_0026E9C0::Run(void* a)
{
    func_0026E208(m10, a);
    func_0026E208(m14, a);
    func_0026E208(mC, a);
    func_0026E208(m18, a);
    func_0026E4B8(m8, a);
    func_0026E4B8(m4, a);
}
