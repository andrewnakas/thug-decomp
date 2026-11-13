struct Msg_001FB110 {
    unsigned char m0;
    unsigned char m1;
    unsigned short m2;
    void* m4;
    int m8;
    int mC;
    unsigned char m10;
    int m14;
    int m18;
    int m1C;
};

struct Conn_001FB110 {
    char pad0[0x48];
    int m48;
    int m4C;
    unsigned short m50;
    int m54;
    int m58;
    char pad5C[0x78 - 0x5C];
    unsigned int m78;
    char pad7C[0x20B4 - 0x7C];
    unsigned int m20B4;
    char pad20B8[0x20E4 - 0x20B8];
    unsigned int m20E4;
    unsigned int m20E8;
    char pad20EC[0x34FC - 0x20EC];
    char m34FC[0x4934 - 0x34FC];
    int m4934;
};

struct Obj_001FB110;
extern unsigned int D_0038EC64;
extern "C" void* func_001FA800(Msg_001FB110* m);
extern "C" int func_002011A0(Obj_001FB110* self, Conn_001FB110* c);
extern "C" int func_00202778(Conn_001FB110* c);
extern "C" int func_00202758(Conn_001FB110* c);
extern "C" int func_00202768(Conn_001FB110* c);
extern "C" void func_001FE388(unsigned int* p, unsigned int v);
extern "C" int func_0031BCE0(int sema);
extern "C" int func_0031BCC0(int sema);
extern "C" void func_001FF970(Obj_001FB110* self, int id, Msg_001FB110* m);
extern "C" int func_00202808(Conn_001FB110* c);
extern "C" int func_001FEC38(Obj_001FB110* self, Conn_001FB110* c, int a, int b);
extern "C" int func_00202BC0(Conn_001FB110* c);
extern "C" void func_00202BB8(Conn_001FB110* c, int v);
extern "C" int func_00200D18(Obj_001FB110* self, int a, unsigned short b, int c, int n, int z);
extern "C" void func_00202BC8(Conn_001FB110* c, int v);
extern "C" void func_001F9598(void* p, int n, unsigned int v);
extern "C" void func_002027F8(Conn_001FB110* c, int v);
extern "C" int func_001FF410(Obj_001FB110* self, Conn_001FB110* c);
extern "C" int func_00201488(Obj_001FB110* self, Conn_001FB110* c);

struct Obj_001FB110 {
    unsigned int m0;
    char pad4[0x17F0 - 4];
    int m17F0;
    char pad17F4[0x227C - 0x17F4];
    unsigned int m227C;
    char pad2280[0x429C - 0x2280];
    int m429C;
    void Run(Conn_001FB110* c);
};

void Obj_001FB110::Run(Conn_001FB110* c)
{
    Msg_001FB110 msg;
    func_001FA800(&msg);
    if (!func_002011A0(this, c)) return;
    unsigned int lim = D_0038EC64;
    int done = 0;
    while (!done && func_001FF410(this, c) && !func_00201488(this, c)) {
        if (func_00202778(c) && !func_00202758(c) && (m227C & 4)) {
            Msg_001FB110 ack;
            func_001FA800(&ack);
            unsigned int now = m0;
            unsigned int stamp = now;
            unsigned int t = c->m20E4;
            if (t == 0 || lim < now - t) {
                if (c->m20E8 < t) {
                    unsigned int v;
                    if (func_00202768(c)) v = 0; else v = c->m20B4;
                    v += 100;
                    if (lim < v) v = lim;
                    func_001FE388(&c->m20B4, v);
                }
                func_0031BCC0(m429C);
                c->m20E4 = now;
                ack.m4 = &stamp;
                ack.m2 = 4;
                ack.m0 = 1;
                func_001FF970(this, c->m48, &ack);
                func_0031BCE0(m429C);
            }
        }
        func_0031BCC0(m429C);
        unsigned short seq[1];
        seq[0] = c->m4934;
        msg.m4 = seq;
        msg.m2 = 2;
        msg.m0 = 9;
        msg.m8 = 0xFF;
        func_001FF970(this, c->m48, &msg);
        func_0031BCE0(m429C);
        int before = func_00202808(c);
        if (!func_001FEC38(this, c, 0, 0)) done = 1;
        if (!func_001FEC38(this, c, 2, 1)) done = 1;
        if (!func_001FEC38(this, c, 1, 1)) done = 1;
        if (!func_001FEC38(this, c, 2, 0)) done = 1;
        if (!func_001FEC38(this, c, 1, 0)) done = 1;
        if (before < func_00202808(c)) {
            func_001FE388(&c->m20B4, D_0038EC64);
            func_00202BB8(c, func_00202BC0(c) - 500);
            if (func_00202BC0(c) < 0x530) func_00202BB8(c, 0x530);
        }
        int n = c->m58 - c->m54;
        if (n > 0 && func_00202778(c)) {
            if (!func_00200D18(this, c->m4C, c->m50, c->m54, n, 0)) {
                func_00202BC8(c, c->m4934);
                c->m58 = c->m54;
                break;
            }
            m17F0 += n;
            func_001F9598(c->m34FC, n + 0x1C, m0);
            func_002027F8(c, 0);
            c->m78 = m0;
            c->m58 = c->m54;
        }
        c->m4934++;
    }
    if (func_00201488(this, c) && !func_00202808(c)) {
        func_00202BB8(c, func_00202BC0(c) + 1000);
    }
}
