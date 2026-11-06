/* sym: __12Spr_0014A878i = 0x0014A628 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

class Base_0014A878 {
public:
    char pad[0x34];
    void* m34;
    virtual ~Base_0014A878();
};

class Spr_0014A878 : public Base_0014A878 {
public:
    void* m3C;
    Spr_0014A878(int a = 0);
    virtual void V1();
    virtual ~Spr_0014A878();
    static void* operator new[](unsigned int n) { return func_0010A638(D_00388A70, n, 1, 0); }
    static void InitPool();
};

extern Spr_0014A878* D_00389DB0;

void Spr_0014A878::InitPool()
{
    Spr_0014A878* p = new Spr_0014A878[512];
    for (int i = 0; i < 512; i++) {
        p[i].m34 = D_00389DB0;
        D_00389DB0 = &p[i];
    }
}
