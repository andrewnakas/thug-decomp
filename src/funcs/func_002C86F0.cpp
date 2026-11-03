struct Color_002C86F0 {
    char m0;
    char m1;
    char m2;
    char m3;
    char m4;
    char m5;
};

struct Obj_002C86F0 {
    char pad0[0x8];
    void* m8;
    char padC[0x54 - 0xC];
    char m54;
    char pad55[0x64 - 0x55];
    int m64;
    void Reset();
};

extern "C" void func_002BAA28(Color_002C86F0* c, int a, int b, int d, int e, int f, int g);
extern "C" void func_002C88F0(Obj_002C86F0* p, Color_002C86F0* c);
extern "C" void func_002BEB70(void* p, Color_002C86F0* c, int v);

void Obj_002C86F0::Reset()
{
    Color_002C86F0 c;
    func_002BAA28(&c, 0, 0, 0, 0, 0, 0);
    func_002C88F0(this, &c);
    Color_002C86F0 c2 = c;
    func_002BEB70(m8, &c2, 0);
    m54 = 0;
    m64 = 0;
}
