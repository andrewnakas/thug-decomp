struct P_002B0BC8 {
    char pad[0x48];
    int m48;
};

extern char D_00379300[];
extern char D_00378DE8[];
extern "C" void* func_0029C320();
extern "C" int func_0029A2C8(void* p);
extern "C" int func_002AB438(void* s);
extern "C" int func_002AB4C8(void* s);
extern "C" int func_002AB4C0(void* s);
extern "C" void func_00200998(void* q, int a, int type, int id, int v, char* name, int b, int c, int d);

struct Obj_002B0BC8 {
    int m0;
    unsigned char m4;
    char pad[0xB];
    void* m10;
    P_002B0BC8* m14;
    int m18;
    void* m1C;
    bool Handle();
};

bool Obj_002B0BC8::Handle()
{
    unsigned char t = m4;
    void* q = m10;
    void* s = m1C;
    if (t == 0x8B) {
        int a = m14->m48;
        func_0029C320();
        func_00200998(q, a, 0x88, 0x1132, func_0029A2C8(func_0029C320()), D_00379300, 8, 0, 1);
    } else if (t == 0x8A) {
        if (func_002AB438(s)) {
            int a = m14->m48;
            unsigned short id = func_002AB4C8(s);
            func_00200998(q, a, 0x87, id, func_002AB4C0(s), D_00378DE8, 8, 0, 1);
        }
    }
    return true;
}
