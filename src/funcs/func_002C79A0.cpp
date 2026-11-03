struct Box_002C79A0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Board_002C79A0 {
    void* m0;
};

struct Piece_002C79A0 {
    char pad0[0x34];
    int m34;
};

extern char D_0037AB58[];
extern "C" bool func_002C0458(Board_002C79A0* b, Box_002C79A0* box, int a);
extern "C" void* func_002C3270(Board_002C79A0* b, int id);
extern "C" int func_002BA7C0(void* p, void* q);
extern "C" int func_00103F28(char* fmt);
extern "C" void* func_002BE5F0(Board_002C79A0* b, int key, int* out);
extern "C" void* func_002BE6E0(Board_002C79A0* b, void* p, int a);
extern "C" void func_002BACC0(void* p, int v);
extern "C" void func_002BF008(Board_002C79A0* b, Box_002C79A0* box, void* r);
extern "C" void func_002BD7D8(Board_002C79A0* b, int v);

struct Sub_002C79A0 {
    int m0;
    Board_002C79A0* m4;
    Board_002C79A0* Get() { return m4; }
};

struct Obj_002C79A0 {
    char pad0[0x4];
    Sub_002C79A0 m4;
    char padC[0x4];
    Box_002C79A0 m10;
    char pad16[0x44 - 0x16];
    int m44;
    char pad48[0x8];
    Piece_002C79A0* m50;
    int Place();
};

int Obj_002C79A0::Place()
{
    Box_002C79A0 b = m10;
    bool bad = !func_002C0458(m4.Get(), &b, 0);
    if (bad) return 0;
    void* p = func_002C3270(m4.Get(), m50->m34);
    if (p && !func_002BA7C0(m4.Get()->m0, p)) {
        func_00103F28(D_0037AB58);
        return 0;
    }
    void* q = func_002BE5F0(m4.Get(), m50->m34, 0);
    void* r = func_002BE6E0(m4.Get(), q, 0);
    func_002BACC0(r, m44);
    b = m10;
    func_002BF008(m4.Get(), &b, r);
    func_002BD7D8(m4.Get(), 0);
    return 1;
}
