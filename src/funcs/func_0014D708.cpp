struct Rgba_0014D708 {
    unsigned char r, g, b, a;
};

struct Geo_0014D708 {
    char pad[0x30];
    int m30;
};

struct Ins_0014D708 {
    char pad[0x60];
    int m60;
    char pad64[0xC];
    Geo_0014D708* m70;
    int Count() { return m70->m30; }
};

extern "C" void func_00170600(void* p, int a);
extern "C" void func_00170758(void* p, unsigned int c);
extern "C" void func_001727E0(Ins_0014D708* p, int i, unsigned int c);
extern "C" void func_00172770(Ins_0014D708* p, unsigned int c);

struct Ent_0014D708 {
    char pad[0x18];
    Ins_0014D708* m18;
    int m1C;
    void* m20;
    void SetColor(Rgba_0014D708* c);
};

void Ent_0014D708::SetColor(Rgba_0014D708* c)
{
    if (m20) {
        func_00170600(m20, 1);
        func_00170758(m20, *(unsigned int*)c);
    } else if (m18) {
        if ((m18->m60 >> 4) & 1) {
            for (int i = 0; i < m18->Count(); i++)
                func_001727E0(m18, i, *(unsigned int*)c);
        } else {
            func_00172770(m18, *(unsigned int*)c);
        }
    }
}
