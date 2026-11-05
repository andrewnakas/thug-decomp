struct Req_001E2468 {
    char pad0[0x10];
    unsigned short m10;
    unsigned short m12;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    char pad2C[4];
};

struct Pkt_001E2468 {
    int m0;
    int m4;
    short m8;
    short mA;
    int mC;
    int m10;
};

extern volatile int D_00394334;
extern int D_0038E210;
extern Req_001E2468 D_004686F0[];
extern char D_003644C0[];
extern "C" void func_001E2600(unsigned short arg, Pkt_001E2468* data);
extern "C" int func_0031C040(int id);
extern "C" int func_0031CD60(const char* fmt);
extern "C" int func_0031D2E8(int a, void* p, int size, int b, int c, int d);

int Send_001E2468(unsigned short cmd, unsigned short arg, Pkt_001E2468* data, int p3, int p4, int p5)
{
    if (cmd == 0x8030) {
        func_001E2600(arg, data);
    }
    int next = (D_00394334 + 1) % 28;
    Req_001E2468* r = &D_004686F0[D_00394334];
    if (r->m24) {
        int i = 0;
        while (func_0031C040(r->m24) >= 0) {
            if (i++ % 1000 == 0) {
                func_0031CD60(D_003644C0);
            }
        }
    }
    r->m10 = cmd;
    if (cmd == 0x8130) {
        r->m12 = arg;
        r->m14 = data->m4;
        r->m18 = (data->m8 << 16) | data->mA;
        r->m1C = data->mC;
        r->m20 = data->m10;
    } else {
        r->m12 = arg;
        r->m14 = (int)data;
        r->m18 = p3;
        r->m1C = p4;
        r->m20 = p5;
    }
    r->m28 = ++D_0038E210;
    r->m24 = func_0031D2E8(3, r, 0x30, 0, 0, 0);
    D_00394334 = next;
    return 1;
}
