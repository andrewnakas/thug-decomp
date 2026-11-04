struct Pkt_001F5458 {
    unsigned char b[4];
};

struct Obj_001F5458 {
    char pad0[0x48];
    char m48[0x60];
    int mA8;
    int Send();
};

extern Pkt_001F5458 D_0038E9C8[];
extern int D_0038E320;
extern "C" void func_001F5340(Obj_001F5458* self, unsigned int* a, int* b, unsigned int* c, int* d);
extern "C" int func_001F5910(unsigned int a, int b, unsigned int c, int d, Pkt_001F5458* p, int n, int e, int f);
extern "C" void func_001F5360(int a, int v);
extern "C" void func_001F65A8(void* p);

int Obj_001F5458::Send()
{
    Pkt_001F5458 pkt = D_0038E9C8[0];
    unsigned int a;
    int b;
    unsigned int c;
    int d;
    func_001F5340(this, &a, &b, &c, &d);
    if (b + d < 4) return 0;
    int v = func_001F5910((a & 0x0FFFFFFF) | 0x20000000, b, (c & 0x0FFFFFFF) | 0x20000000, d, &pkt, 4, 0, 0);
    func_001F5360(D_0038E320 + 0x6735C0, v);
    func_001F65A8(m48);
    if (!mA8) mA8 = 2;
    return 1;
}
