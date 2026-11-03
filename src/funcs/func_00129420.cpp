typedef int qword_00129420 __attribute__((mode(TI)));

union Vec_00129420 {
    qword_00129420 q;
    struct {
        float x, y, z, w;
    } f;
};

extern "C" int func_0013EC88(void* x, int r, int g, int b, int a);

struct Ent_00129420 {
    void* m0;
    int m4;
    int pad8[2];
    Vec_00129420 m10;
};

struct C_00129420 {
    char pad[0x190];
    unsigned char m190;
    unsigned char m191;
    unsigned char m192;
    unsigned char m193;
    char pad194[0xC];
    Ent_00129420 m1A0[0x19];
    int m4C0;
    void Push(void* x, Vec_00129420* v)
    {
        func_0013EC88(x, m190, m191, m192, m193);
        m1A0[m4C0].m0 = x;
        m1A0[m4C0].m10 = *v;
        m4C0++;
    }
    void* AddRef(void* key, Vec_00129420* v);
};

extern "C" void* func_00132100();
extern "C" void* func_001317D0(void* key);
extern "C" void* func_00134F18(void* p);
extern "C" void* func_0013C2E0(void* q, int a, int b);
extern "C" void func_0013C568(void* r, int a);
extern "C" void func_0013D518(void* x, void* r, int a);
extern "C" void* func_0012ABA0(C_00129420* o);

void* C_00129420::AddRef(void* key, Vec_00129420* v)
{
    void* x = func_00132100();
    void* p = func_001317D0(key);
    if (p) {
        void* q = func_00134F18(p);
        if (q) {
            void* r = func_0013C2E0(q, 1, 0);
            func_0013C568(r, 1);
            func_0013D518(x, r, 0);
        }
    }
    Push(x, v);
    return func_0012ABA0(this);
}
