struct Color_002CBD30 {
    unsigned char m[6];
};

extern "C" void func_002BAA28(Color_002CBD30* c, int a, int b, int d, int e, int f, int g);

struct Obj_002CBD30 {
    char pad0[0xC];
    int mC;
    int m10;
    int m14;
    int m18;
    char pad1C[0x9C - 0x1C];
    Color_002CBD30 m9C[2];
    char padA8[0xEC - 0xA8];
    int mEC;
    Obj_002CBD30* Init();
};

Obj_002CBD30* Obj_002CBD30::Init()
{
    Color_002CBD30* c = m9C;
    for (int i = 1; i != -1; i--) {
        func_002BAA28(c, 0, 0, 0, 0, 0, 0);
        c++;
    }
    mC = 0;
    m10 = 0;
    m14 = 0;
    m18 = 0;
    mEC = 0;
    return this;
}
