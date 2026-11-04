extern char D_003783C8[];
extern char D_00378318[];
extern char D_00366B58[];

struct Msg_002A3600 {
    unsigned char type;
    char pad1;
    short len;
    void* data;
    int m8;
    int mC;
    char pad10[0x10];
};

struct Req_002A3600 {
    int m0;
    unsigned char m4;
    unsigned char m5;
    char m6[0x10 - 6];
    int m10;
    int m14;
    unsigned char m18;
    char pad19[7];
    char m20[0x10];
    char m30[0x1000];
};

struct Iter_002A3600 {
    int m0;
    int m4;
    void* m8;
    Iter_002A3600() { m8 = D_00366B58; m4 = 0; }
    ~Iter_002A3600() { m8 = D_00366B58; }
};

struct Mgr_002A3600 {
    char pad[8];
    char m8[4];
};

extern void* D_0038EB78;
extern Mgr_002A3600* D_0038C308;
extern void* D_0038FC78;
extern "C" void func_001FA800(Msg_002A3600* m);
extern "C" void* func_002A6070(void* m);
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, int crc);
extern "C" bool func_001E8890(void* s, char* name, char** out, int a);
extern "C" int func_002D8158(void* p);
extern "C" void* func_002DA188(void* p);
extern "C" int func_002DA2A8(void* p);
extern "C" int func_002A18E0(void* m);
extern "C" int func_001FA648(void* p);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" void* func_0022E3C8(void* p, int v);
extern "C" void* func_00200EC0(void* l, Iter_002A3600* it);
extern "C" int func_00202B30(void* p);
extern "C" int func_002616E0(void* x, char* buf, int size, int f);
extern "C" void func_00200C00(void* w, Msg_002A3600* m);
extern "C" unsigned int func_0010FC30();
extern "C" void func_00105260(void* p, void* q);
extern "C" void func_002A8250(void* s, int v);

struct Obj_002A3600 {
    char pad[0xC];
    void* mC;
    void* m10;
    char pad14[4];
    void* m18;
    char pad1C[0x94 - 0x1C];
    void* m94;
    char pad98[0x184 - 0x98];
    unsigned int m184;
    void Join(char* name);
};

void Obj_002A3600::Join(char* name)
{
    Req_002A3600 req;
    Msg_002A3600 msg;
    char* str;
    void* net = D_0038EB78;
    Mgr_002A3600* mgr = D_0038C308;
    func_001FA800(&msg);
    func_001E8890(func_00202EF8(func_002A6070(this), func_001F0D78(D_003783C8)), D_00378318, &str, 1);
    req.m10 = func_002D8158(mC);
    req.m14 = func_002DA2A8(func_002DA188(m10));
    req.m4 = func_002A18E0(this) == 1;
    req.m0 = 0x30036;
    req.m5 = 1;
    int flag;
    if (func_001FA648(net) == 1) {
        req.m18 = 0;
        flag = 1;
    } else {
        req.m18 = 1;
        flag = 0;
    }
    func_00331A9C(req.m20, str);
    func_00331A9C(req.m6, name);
    int len = 0;
    if (!req.m4) {
        void* x = func_0022E3C8(D_0038FC78, 0);
        Iter_002A3600 it;
        int f = func_00202B30(func_00200EC0(m18, &it)) != 1 ? flag : 1;
        len = func_002616E0(x, req.m30, 0x1000, f);
    }
    msg.len = len + 0x30;
    msg.type = 0x50;
    msg.mC = 1;
    msg.data = &req;
    func_00200C00(m18, &msg);
    m184 = func_0010FC30();
    func_00105260(mgr->m8, m94);
    func_002A8250(this, 3);
}
