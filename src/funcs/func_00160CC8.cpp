extern int* D_0038B53C;
extern "C" void func_0010BEB8(void* p);

struct Tree_00160CC8 {
    void* m0;
    void* m4;
    void** m8;
    void Fn();
};

extern "C" void func_00160C40(Tree_00160CC8* self, void** n, int depth);

void Tree_00160CC8::Fn()
{
    func_00160C40(this, m8, 5);
    m8 = 0;
    func_0010BEB8(m4);
    func_0010BEB8(m0);
    func_0010BEB8(D_0038B53C);
    D_0038B53C = 0;
}
