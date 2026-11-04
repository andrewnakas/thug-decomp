struct Disp_002A2680;
struct Conn_002A2680 {
    int m0;
    char m4[4];
};

struct Obj_002A2680;
typedef int (*Handler_002A2680)(void*);
extern "C" int func_002ABB20(void*);
extern "C" int func_002AC158(void*);
extern "C" int func_002AC1A0(void*);
extern "C" int func_002AC528(void*);
extern "C" int func_002AC6D8(void*);
extern "C" int func_002AC9D8(void*);
extern "C" int func_002ACB58(void*);
extern "C" int func_002AD4C0(void*);
extern "C" int func_002AD950(void*);
extern "C" int func_002AE920(void*);
extern "C" int func_002AEB38(void*);
extern "C" int func_002AEB90(void*);
extern "C" int func_002AF770(void*);
extern "C" int func_002AFB68(void*);
extern "C" int func_002AFF30(void*);
extern "C" int func_002B0580(void*);
extern "C" int func_002B0B78(void*);
extern "C" int func_002B0BC8(void*);
extern "C" int func_002B0CD0(void*);
extern void* D_0038EB78;
extern char* D_0038C308;
extern char D_00392128[];
extern "C" void* func_001FA640(void* m);
extern "C" int func_00326E30(void* p);
extern "C" Conn_002A2680* func_001F9150(void* net, int a, char* name, int b, int port, int c, int flags);
extern "C" void func_002A18E8(Obj_002A2680* o, int v);
extern "C" void func_00105260(void* p, int v);
extern "C" void func_001FBF60(void* d, int id, Handler_002A2680 fn, int a, Obj_002A2680* ctx, int b);
extern "C" void func_002A6B98(Obj_002A2680* o);

struct Obj_002A2680 {
    char pad0[0x14];
    Conn_002A2680* m14;
    char pad18[0x84 - 0x18];
    int m84;
    char pad88[0xB4 - 0x88];
    int mB4;
    char padB8[0x164 - 0xB8];
    int m164;
    char pad168[0x190 - 0x168];
    int m190;
    Conn_002A2680* Start(int a, int b);
};

Conn_002A2680* Obj_002A2680::Start(int a, int b)
{
    int flags = a ? 0x1D : 0x15;
    if (b) flags |= 0x20;
    void* net = D_0038EB78;
    char* x = D_0038C308;
    m14 = func_001F9150(net, 0, D_00392128, 20, 0x141E, func_00326E30(func_001FA640(net)), flags);
    func_002A18E8(this, 0);
    if (m14) {
        func_00105260(x + 8, m84);
        func_001FBF60(m14->m4, 0x3, func_002AC528, 3, this, 0x0);
        func_001FBF60(m14->m4, 0x50, func_002AC6D8, 3, this, 0x80);
        func_001FBF60(m14->m4, 0x11, func_002AC1A0, 3, this, 0x80);
        func_001FBF60(m14->m4, 0xB, func_002ACB58, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x4A, func_002AC9D8, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x26, func_002AC158, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x54, func_002ABB20, 0, this, 0x80);
        func_001FBF60(m14->m4, 0x57, func_002AD4C0, 0, this, 0x80);
        func_001FBF60(m14->m4, 0x59, func_002AF770, 0, this, 0x80);
        func_001FBF60(m14->m4, 0x60, func_002AD950, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x61, func_002AD950, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x62, func_002AD950, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x63, func_002AD950, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x64, func_002AD950, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x65, func_002AD950, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x66, func_002AD950, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x67, func_002AFB68, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x6B, func_002AE920, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x6E, func_002AFF30, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x6F, func_002B0580, 2, this, 0x80);
        func_001FBF60(m14->m4, 0x6C, func_002AEB38, 0, this, 0xFF);
        func_001FBF60(m14->m4, 0x88, func_002AEB90, 0, this, 0xFF);
        func_001FBF60(m14->m4, 0x7D, func_002B0B78, 0, this, 0x80);
        func_001FBF60(m14->m4, 0x81, func_002B0CD0, 0, this, 0x80);
        func_001FBF60(m14->m4, 0x8B, func_002B0BC8, 0, this, 0x80);
        func_001FBF60(m14->m4, 0x8A, func_002B0BC8, 0, this, 0x80);
        m164 = 0;
        m190 = 0;
        func_002A6B98(this);
        mB4 = 0;
    }
    return m14;
}
