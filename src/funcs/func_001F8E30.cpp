struct Req_001F8E30 {
    int m0;
    int m4;
    char m8[0x50];
    char m58[0x50];
    unsigned short mA8;
    char padAA[0x148 - 0xAA];
};

extern void* D_00394130;
extern char D_0038EB88[];
extern unsigned short D_0038EBA0[];

extern "C" void func_003267F8();
extern "C" void func_00326938();
extern "C" int func_0031BCE0(void* sema);
extern "C" void func_0031BCC0(void* sema);
extern "C" void func_00327468(char* name);
extern "C" void* func_003315B8(void* p, int c, int n);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_00327BE0(int a, int b, void* data, int size);
extern "C" int func_00327A90(int a, int b, int* x, int* y);
extern "C" void func_00324540(int a, int b, int c);
extern "C" void func_001F9E08();

class Conn_001F8E30 {
public:
    char pad0[0x1A0];
    char m1A0[0x20];
    char m1C0[0x50];
    char m210[0x98];
    int m2A8;
    char pad2AC[0x2B8 - 0x2AC];
    int m2B8;
    int m2BC;
    void Connect();
};

extern "C" int func_001FA5D0(Conn_001F8E30* self);
extern "C" int func_001FA648(Conn_001F8E30* self);
extern "C" void func_001FA6A0(Conn_001F8E30* self, int state);
extern "C" int func_001F8C10(char* a, int b, char* c, char* d, int e, void (*cb)());

void Conn_001F8E30::Connect()
{
    char* user = m1C0;
    char* pass = m210;
    func_003267F8();
    func_0031BCE0(D_00394130);
    func_00327468(D_0038EB88);

    Req_001F8E30 a;
    func_003315B8(&a, 0, sizeof(a));
    int id = func_001FA5D0(this);
    a.m0 = id;
    a.m4 = 0;
    func_00331A9C(a.m8, user);
    func_00331A9C(a.m58, pass);
    a.mA8 = D_0038EBA0[0];
    func_00327BE0(0, 2, &a, sizeof(a));

    Req_001F8E30 b;
    func_003315B8(&b, 0, sizeof(b));
    b.m0 = func_001FA5D0(this);
    b.m4 = 0;
    func_00331A9C(b.m8, user);
    func_00331A9C(b.m58, pass);
    int r = func_00327BE0(0, 1, &b, sizeof(b));

    m2B8 = 0;
    if (func_001FA648(this) == 1) {
        r = func_001F8C10(m1A0, 0, user, pass, 0x3C, func_001F9E08);
    } else if (func_001FA648(this) == 3) {
        r = func_001F8C10(D_0038EB88, 0, D_0038EB88, D_0038EB88, 0x3C, func_001F9E08);
    }
    if (0 == r) {
        int x = 0x4D2;
        int y = 4;
        func_00327A90(0, 0, &x, &y);
        m2A8 = 1;
        m2BC = x;
    } else {
        func_00324540(10, 0, 0);
        func_001FA6A0(this, 7);
        m2B8 = r;
        m2A8 = 0;
    }
    func_00326938();
    func_0031BCC0(D_00394130);
}
