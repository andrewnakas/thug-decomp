/* fuzzy: 71.6 */
struct Msg_001FB948 {
    unsigned char m_type;
    char pad1;
    short m_len;
    void* m_data;
    int m8;
    char padC[0x14];
};

struct Mgr_001FB948 {
    unsigned int m0;
    char pad4[0x17F0 - 0x4];
    int m17F0;
    char pad17F4[0x1834 - 0x17F4];
    int m1834;
    char pad1838[0x227C - 0x1838];
    int m227C;
    char pad2280[0x429C - 0x2280];
    int m429C;
};

struct Conn_001FB948 {
    char pad0[0x48];
    int m48;
    int m4C;
    unsigned short m50;
    char pad52[2];
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

extern unsigned int D_0038EC64;

extern "C" int func_002011A0(Mgr_001FB948* m, Conn_001FB948* c);
extern "C" int func_001FF268(Mgr_001FB948* m, Conn_001FB948* c);
extern "C" void func_001FA800(Msg_001FB948* msg);
extern "C" void func_0031BCC0(int sema);
extern "C" void func_0031BCE0(int sema);
extern "C" void func_001FF970(Mgr_001FB948* m, int id, Msg_001FB948* msg);
extern "C" int func_00202778(Conn_001FB948* c);
extern "C" int func_00202758(Conn_001FB948* c);
extern "C" int func_00202768(Conn_001FB948* c);
extern "C" void func_001FE388(unsigned int* p, unsigned int v);
extern "C" int func_001FEC38(Mgr_001FB948* m, Conn_001FB948* c, int a, int b);
extern "C" int func_00200E28(Mgr_001FB948* m, int a, int n, int b);
extern "C" int func_00200D18(Mgr_001FB948* m, int a, unsigned short b, int c, int n, int d);
extern "C" void func_00202BC8(Conn_001FB948* c, int v);
extern "C" void func_001F9598(char* q, int n, unsigned int t);
extern "C" void func_002027F8(Conn_001FB948* c, int a);
extern "C" int func_001FF410(Mgr_001FB948* m, Conn_001FB948* c);
extern "C" int func_00201488(Mgr_001FB948* m, Conn_001FB948* c);

void Call_001FB948(Mgr_001FB948* mgr, Conn_001FB948* conn)
{
    if (!func_002011A0(mgr, conn))
        return;
    unsigned int interval = D_0038EC64;
    bool stop = false;
    while (!stop && func_001FF410(mgr, conn) && !func_00201488(mgr, conn)) {
        if (func_001FF268(mgr, conn)) {
            Msg_001FB948 msg;
            unsigned short seq;
            func_001FA800(&msg);
            func_0031BCC0(mgr->m429C);
            seq = conn->m4934;
            msg.m_data = &seq;
            msg.m_len = 2;
            msg.m_type = 9;
            msg.m8 = 0xFF;
            func_001FF970(mgr, conn->m48, &msg);
            func_0031BCE0(mgr->m429C);
        }
        if (func_00202778(conn) && !func_00202758(conn) && (mgr->m227C & 4)) {
            Msg_001FB948 msg;
            func_001FA800(&msg);
            unsigned int t = mgr->m0;
            unsigned int now = t;
            unsigned int last = conn->m20E4;
            if (!last || t - last > interval) {
                if (conn->m20E8 < last) {
                    unsigned int v;
                    if (func_00202768(conn))
                        v = 0;
                    else
                        v = conn->m20B4;
                    v += 100;
                    func_001FE388(&conn->m20B4, interval < v ? interval : v);
                }
                conn->m20E4 = t;
                func_0031BCC0(mgr->m429C);
                msg.m_data = &now;
                msg.m_type = 1;
                msg.m_len = 4;
                func_001FF970(mgr, conn->m48, &msg);
                func_0031BCE0(mgr->m429C);
            }
        }
        if (!func_001FEC38(mgr, conn, 0, 0))
            stop = true;
        if (!func_001FEC38(mgr, conn, 2, 1))
            stop = true;
        if (!func_001FEC38(mgr, conn, 1, 1))
            stop = true;
        if (!func_001FEC38(mgr, conn, 2, 0))
            stop = true;
        if (!func_001FEC38(mgr, conn, 1, 0))
            stop = true;
        int n = conn->m58 - conn->m54;
        if (n > 0 && func_00202778(conn)) {
            if (mgr->m1834) {
                if (!func_00200E28(mgr, conn->m54, n, 0)) {
                    func_00202BC8(conn, conn->m4934);
                    conn->m58 = conn->m54;
                    return;
                }
            } else {
                if (!func_00200D18(mgr, conn->m4C, conn->m50, conn->m54, n, 0)) {
                    func_00202BC8(conn, conn->m4934);
                    conn->m58 = conn->m54;
                    return;
                }
            }
            mgr->m17F0 += n;
            func_001F9598(conn->m34FC, n + 0x1C, mgr->m0);
            conn->m78 = mgr->m0;
            func_002027F8(conn, 0);
            conn->m58 = conn->m54;
        }
        conn->m4934++;
    }
}
