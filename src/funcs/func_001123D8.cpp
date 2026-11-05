struct Req_001123D8 {
    char pad[0x10];
    int m10;
    int m14;
    short m18;
    short m1A;
    char pad1C[0x6C - 0x1C];
    int m6C;
};

extern void* D_00464BF8[16];
extern void* D_00388A70;
extern volatile int D_0038881C;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00111200(void* p);
extern "C" void func_0010E3F8(void* job);
extern "C" void func_00111FB8();
extern "C" void func_001121A0();
extern "C" int func_00112238(Req_001123D8* req, void* job, int a, int b);
extern "C" void func_00112378(int id);

extern "C" void func_001123D8()
{
    for (int i = 0; i < 16; i++) {
        if (D_00464BF8[i]) {
            func_0010E3F8(D_00464BF8[i]);
        } else {
            D_00464BF8[i] = func_00111200(func_0010A638(D_00388A70, 0x150, 1, 0));
        }
    }
    func_00111FB8();
    func_001121A0();
    Req_001123D8 req;
    req.m14 = 0x10000;
    req.m10 = 100;
    req.m1A = D_0038881C;
    req.m6C = 0;
    req.m18 = 0;
    func_00112378(func_00112238(&req, 0, 1, -1));
}
