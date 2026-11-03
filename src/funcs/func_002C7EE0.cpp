struct Box_002C7EE0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Board_002C7EE0;

extern "C" void func_002C0BE0(Board_002C7EE0* b, void* p);
extern "C" void func_002BD7D8(Board_002C7EE0* b, int v);
extern "C" void* func_002C0640(Board_002C7EE0* b, Box_002C7EE0* box, void* out);
extern "C" void func_002C0E60(Board_002C7EE0* b, int a, int c);

struct Sub_002C7EE0 {
    int m0;
    Board_002C7EE0* m4;
    Board_002C7EE0* Get() { return m4; }
};

struct Obj_002C7EE0 {
    char pad0[0x4];
    Sub_002C7EE0 m4;
    char padC[0x4];
    Box_002C7EE0 m10;
    char pad16[0x80 - 0x16];
    char m80[0x48];
    int mC8;
    int Apply();
};

int Obj_002C7EE0::Apply()
{
    if (mC8 == 1) {
        func_002C0BE0(m4.Get(), m80);
        mC8 = 0;
        func_002BD7D8(m4.Get(), 0);
        return 1;
    }
    int out[2];
    void* p = func_002C0640(m4.Get(), &m10, out);
    if (p) {
        func_002C0BE0(m4.Get(), p);
        func_002BD7D8(m4.Get(), 0);
        func_002C0E60(m4.Get(), 1, 0);
        return 1;
    }
    return 0;
}
