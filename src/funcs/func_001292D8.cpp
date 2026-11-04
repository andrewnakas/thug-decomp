typedef int qword_001292D8 __attribute__((mode(TI)));

union Vec_001292D8 {
    qword_001292D8 q;
    struct {
        float x, y, z, w;
    } f;
};

class Str104008 {
public:
    int m0;
    int m4;
    char* m8;
    Str104008();
    ~Str104008();
    Str104008& operator=(const Str104008& o);
    char* Get() const;
};

extern "C" int func_0013EC88(void* x, int r, int g, int b, int a);

struct Ent_001292D8 {
    void* m0;
    int m4;
    int pad8[2];
    Vec_001292D8 m10;
};

struct C_001292D8 {
    char pad[0x190];
    unsigned char m190;
    unsigned char m191;
    unsigned char m192;
    unsigned char m193;
    char pad194[0xC];
    Ent_001292D8 m1A0[0x19];
    int m4C0;
    void Push(void* x, Vec_001292D8* v)
    {
        func_0013EC88(x, m190, m191, m192, m193);
        m1A0[m4C0].m0 = x;
        m1A0[m4C0].m10 = *v;
        m4C0++;
    }
    void* AddText(char* text, void* a, Vec_001292D8* v, int t);
};

extern "C" void* func_00132100();
extern "C" int func_001291B0(C_001292D8* o, void* x, void* a);
extern "C" Str104008 func_00131688(char* text, void* tab);
extern "C" void func_0013D2F0(void* x, char* s, int a, int b, int c, int d, int e);
extern "C" void* func_0012ABA0(C_001292D8* o);
extern char D_00389890[];

void* C_001292D8::AddText(char* text, void* a, Vec_001292D8* v, int t)
{
    void* x = func_00132100();
    if (a)
        m1A0[m4C0].m4 = func_001291B0(this, x, a);
    if (text) {
        Str104008 s;
        s = func_00131688(text, D_00389890);
        func_0013D2F0(x, s.Get(), 0, 1, t, 0, 0);
    }
    Push(x, v);
    return func_0012ABA0(this);
}
