extern char D_003783C8[];
extern char D_00378318[];

struct Msg_002A2CA0 {
    unsigned char type;
    char pad1;
    short len;
    void* data;
    char pad[0x18];
};

struct Hdr_002A2CA0 {
    int m0;
    unsigned char m4;
    unsigned char m5;
    unsigned char m6;
};

struct Conn_002A2CA0 {
    int m0;
    char m4[4];
};

struct Mgr_002A2CA0 {
    char pad[8];
    char m8[4];
};

extern Mgr_002A2CA0* D_0038C308;
extern "C" void func_001FA800(Msg_002A2CA0* m);
extern "C" void* func_002A6070(void* m);
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, int crc);
extern "C" bool func_001E8890(void* s, char* name, int* out, int a);
extern "C" int func_00201288(void* p);
extern "C" int func_001FEAE8(void* p, int ip, unsigned short port, int a);
extern "C" void func_00201278(void* p, int a, int b);
extern "C" void func_001FB860(void* p, int ip, unsigned short port);
extern "C" unsigned int func_0010FC30();
extern "C" void func_00105260(void* p, void* q);
extern "C" void func_002A8250(void* s, int v);
extern "C" void func_002A39C0(void* s, int ip);
extern "C" void func_002A39D0(void* s, unsigned short port);
extern "C" void func_00200C00(void* w, Msg_002A2CA0* m);
extern "C" void func_002010D0(void* w, int a);
extern "C" int func_001FBF60(void* d, int id, void (*f)(), int a, void* o, int b);
extern "C" void func_002A8260(void* p, int v);
extern "C" void func_002AB918();
extern "C" void func_002ABA30();
extern "C" void func_002ABA68();
extern "C" void func_002AC140();
extern "C" void func_002AC158();
extern "C" void func_002ACC98();
extern "C" void func_002ACD00();
extern "C" void func_002ACD38();
extern "C" void func_002ACDD8();
extern "C" void func_002ACF00();
extern "C" void func_002AD200();
extern "C" void func_002AD240();
extern "C" void func_002AD388();
extern "C" void func_002AD3D8();
extern "C" void func_002AD428();
extern "C" void func_002AD478();
extern "C" void func_002AD890();
extern "C" void func_002AD8C0();
extern "C" void func_002AE538();
extern "C" void func_002AE790();
extern "C" void func_002AEB38();
extern "C" void func_002AEB90();
extern "C" void func_002AECD0();
extern "C" void func_002AEE48();
extern "C" void func_002AEE50();
extern "C" void func_002AF020();
extern "C" void func_002AF050();
extern "C" void func_002AF600();
extern "C" void func_002AF728();
extern "C" void func_002AF910();
extern "C" void func_002AF990();
extern "C" void func_002AF9D8();
extern "C" void func_002AFCC8();
extern "C" void func_002B0228();
extern "C" void func_002B06C8();
extern "C" void func_002B07D0();
extern "C" void func_002B08B0();
extern "C" void func_002B0950();
extern "C" void func_002B0A30();
extern "C" void func_002B0AB0();

struct Obj_002A2CA0 {
    char pad[0x14];
    void* m14;
    Conn_002A2CA0* m18[0x94 - 0x18 >> 2];
    void* m94;
    char pad98[4];
    void* m9C;
    char padA0[0x184 - 0xA0];
    unsigned int m184;
    void Connect(int kind, long ip, unsigned short port, int idx);
};

void Obj_002A2CA0::Connect(int kind, long ip, unsigned short port, int idx)
{
    Hdr_002A2CA0 hdr;
    Msg_002A2CA0 msg;
    int val;
    func_001FA800(&msg);
    Mgr_002A2CA0* mgr = D_0038C308;
    func_001E8890(func_00202EF8(func_002A6070(this), func_001F0D78(D_003783C8)), D_00378318, &val, 1);
    if (func_00201288(m18[idx])) {
        int a = func_001FEAE8(m14, ip, port, 1);
        func_00201278(m18[idx], a, func_001FEAE8(m18[idx], ip, port, 1));
    } else {
        func_001FB860(m18[idx], ip, port);
        func_001FEAE8(m18[idx], ip, port, 2);
        m184 = func_0010FC30();
        func_00105260(mgr->m8, m94);
        func_002A8250(this, 1);
        func_00105260(mgr->m8, m9C);
        func_002A39C0(this, ip);
        func_002A39D0(this, port);
    }
    hdr.m6 = 0;
    hdr.m4 = kind;
    hdr.m0 = 0x30036;
    msg.len = 0x10;
    msg.type = 3;
    hdr.m5 = 0;
    msg.data = &hdr;
    func_00200C00(m18[idx], &msg);
    func_002010D0(m18[idx], 0);
    func_001FBF60(&m18[idx]->m4, 0x42, func_002ACC98, 0x2, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x4D, func_002ACD00, 0x2, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x4E, func_002ACD38, 0x2, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x47, func_002ACDD8, 0x2, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x4F, func_002ACF00, 0x2, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x25, func_002AC140, 0x2, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x26, func_002AC158, 0x2, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x53, func_002ABA68, 0x2, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x58, func_002AE538, 0, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x75, func_002AE790, 0, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x3F, func_002AF728, 0x2, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x5E, func_002AD890, 0x2, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x5F, func_002AD8C0, 0x2, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x68, func_002AFCC8, 0x2, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x69, func_002B0950, 0x2, this, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x4C, func_002B08B0, 0x2, 0, 0x80);
    func_001FBF60(&m18[idx]->m4, 0x7C, func_002B0AB0, 0x2, this, 0x80);
    if (idx == 0) {
        func_001FBF60(&m18[0]->m4, 0x6D, func_002AF600, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x34, func_002AF050, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x7A, func_002AF020, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x6E, func_002B0228, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x6F, func_002B06C8, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x70, func_002B07D0, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x46, func_002AEE50, 0, this, 0xFF);
        func_001FBF60(&m18[0]->m4, 0x46, func_002AEE48, 0, this, 0xFF);
        func_001FBF60(&m18[0]->m4, 0x6C, func_002AEB38, 0, this, 0xFF);
        func_001FBF60(&m18[0]->m4, 0x88, func_002AEB90, 0x4, this, 0xFF);
        func_001FBF60(&m18[0]->m4, 0x87, func_002AECD0, 0x4, this, 0xFF);
        func_001FBF60(&m18[0]->m4, 0x80, func_002B0A30, 0, this, 0x80);
        if (!func_00201288(m18[0])) {
            func_001FBF60(&m18[0]->m4, 0x22, func_002AB918, 0, this, 0x80);
            func_001FBF60(&m18[0]->m4, 0x79, func_002AD200, 0, this, 0x80);
        }
        func_001FBF60(&m18[0]->m4, 0x7B, func_002ABA30, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x55, func_002AD240, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x72, func_002AD428, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x74, func_002AD388, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x71, func_002AD3D8, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x73, func_002AD478, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x5A, func_002AF910, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x6A, func_002AF990, 0, this, 0x80);
        func_001FBF60(&m18[0]->m4, 0x23, func_002AF9D8, 0x3, this, 0xFF);
    }
    func_002A8260(this, 0);
}
