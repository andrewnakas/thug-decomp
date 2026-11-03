extern char D_0037A638[];
extern "C" int func_001E5648(char* name, int a);

struct Box_002C4108 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    void Set(unsigned char px, signed char py, unsigned char pz, unsigned char pw, unsigned char ph, unsigned char pd)
    {
        x = px; y = py; z = pz; w = pw; h = ph; d = pd;
    }
};

struct Obj_002C4108 {
    char pad0[0x352C];
    Box_002C4108 m352C;
    Box_002C4108 m3532;
    void Init();
};

void Obj_002C4108::Init()
{
    int n = func_001E5648(D_0037A638, 1);
    m3532.Set(1, -4, 1, 0x38, 8, 0x38);
    int c = (0x38 - n) / 2 + 1;
    m352C.Set(c, -4, c, n, 8, n);
}
