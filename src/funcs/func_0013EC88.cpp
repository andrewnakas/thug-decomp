extern "C" short func_0013E9D8(void* self);
extern "C" void* func_0013E9B8(void* self, int i);

struct S_0013EC88 {
    unsigned char r, g, b, a;
};

extern "C" void func_0013C438(void* p, const S_0013EC88& c);

class C_0013EC88 {
public:
    bool SetColour(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
};

bool C_0013EC88::SetColour(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    S_0013EC88 c;
    c.r = r;
    c.g = g;
    c.b = b;
    c.a = a;
    short n = func_0013E9D8(this);
    for (short i = 0; i < n; i++) {
        S_0013EC88 t = c;
        func_0013C438(func_0013E9B8(this, i), t);
    }
    return true;
}
