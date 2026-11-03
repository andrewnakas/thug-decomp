struct Msg_002AC528 {
    unsigned char m_type;
    unsigned char m_1;
    unsigned short m_size;
    void* m_data;
    int m_8;
    int m_C;
    unsigned char m_10;
    int m_14;
    int m_18;
    int m_1C;
};

struct Pkt_002AC528 {
    int m0;
    int m4;
    int m8;
    char name[0x10];
    unsigned char m1C;
    unsigned char m1D;
    char pad[2];
};

struct Conn_002AC528 {
    char pad[0x48];
    int m48;
    int m4C;
    unsigned short m50;
};

extern void* D_0038EB78;
extern char D_00378E18[];
extern char D_00378E28[];
extern "C" void func_001FA800(Msg_002AC528* m);
extern "C" int func_00202778(Conn_002AC528* c);
extern "C" int func_002B0E70(void* m, int* out, int a, Conn_002AC528* c);
extern "C" void func_00200C68(int obj, int type, int size, void* data, int a, int b, int c);
extern "C" int func_002A1B30(void* m);
extern "C" int func_001FA648(void* g);
extern "C" int func_002A1A28(void* m);
extern "C" int func_002A39B8(void* m);
extern "C" int func_002A39B0(void* m);
extern "C" int func_002A39A8(void* m);
extern "C" void* func_002A6070(void* m);
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, int crc);
extern "C" bool func_001E8890(void* p, char* name, char** out, int v);
extern "C" char* func_00332088(char* dst, const char* src, int n);
extern "C" void func_001FF970(int q, int id, Msg_002AC528* m);

struct Obj_002AC528 {
    int m0;
    char pad4[0xC];
    int m10;
    Conn_002AC528* m14;
    char pad18[4];
    void* m1C;
    int Handle();
};

int Obj_002AC528::Handle()
{
    Pkt_002AC528 pkt;
    Msg_002AC528 msg;
    int reason;
    unsigned char r2[1];
    char* str;
    void* m = m1C;
    int a = m0;
    if (func_00202778(m14)) {
        void* g = D_0038EB78;
        if (!func_002B0E70(m, &reason, a, m14)) {
            r2[0] = reason;
            func_00200C68(m10, 0x47, 1, r2, m14->m4C, m14->m50, 0);
            return 2;
        }
        pkt.m1C = func_002A1B30(m);
        if (func_001FA648(g) == 1) {
            pkt.m1D = 0;
        } else {
            pkt.m1D = 1;
        }
        if (func_002A1A28(m)) {
            pkt.m8 = func_002A39B8(m);
            pkt.m4 = func_002A39B0(m);
            pkt.m0 = func_002A39A8(m);
        }
        func_001E8890(func_00202EF8(func_002A6070(m), func_001F0D78(D_00378E18)), D_00378E28, &str, 1);
        func_00332088(pkt.name, str, 0xF);
        pkt.name[0xF] = 0;
        func_00200C68(m10, 0x4F, 0x20, &pkt, m14->m4C, m14->m50, 0);
    } else {
    Msg_002AC528* pm = &msg;
    func_001FA800(pm);
    pkt.m1C = func_002A1B30(m);
    msg.m_type = 0x4F;
    msg.m_size = 0x20;
    msg.m_data = &pkt;
    func_001FF970(m10, m14->m48, pm);
    }
    return 1;
}
