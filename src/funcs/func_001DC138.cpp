struct Vec_001DC138 {
    float x;
    float y;
    float z;
};

struct Info_001DC138 {
    int m_0;
    int m_4;
    char m_pad[0x18];
};

struct Packet_001DC138 {
    short x;
    short y;
    short z;
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    unsigned char e;
    char m_pad[5];
};

struct Msg_001DC138 {
    unsigned char m_id;
    char m_pad;
    unsigned short m_size;
    Packet_001DC138* m_data;
    char m_pad2[0x18];
};

extern void* D_0038E0A0;
extern void* D_00392068;

extern "C" bool func_001DC418();
extern "C" int func_001DBFE8(Info_001DC138* out, int b, int a, float t);
extern "C" void func_001FA800(Msg_001DC138* m);
extern "C" void* func_002A39E0(void* m, int a);
extern "C" void func_00200C00(void* conn, Msg_001DC138* msg);
extern "C" void func_001DC540(Packet_001DC138* p);
extern "C" float func_001DD758(void* mgr, int id);
extern "C" void func_001DDB00(void* mgr, Packet_001DC138* p, Vec_001DC138* pos, int a, int b, int c, float f);
extern "C" float func_001DC330(Info_001DC138* info, float v, int a);
extern "C" void func_001DC5A8(Packet_001DC138* p, float f);
extern "C" bool func_001DC658(Packet_001DC138* p);
extern "C" void func_001DC578(Packet_001DC138* p, int flags);
extern "C" float func_001DC3A0(Info_001DC138* info, float v, int a);
extern "C" void func_001DD290(void* mgr, int id, Packet_001DC138* p, int a, int b, int c, float f);

void Play_001DC138(int a, int b, Vec_001DC138* pos, int send, float c, float d, float e)
{
    if (func_001DC418()) {
        return;
    }
    void* mgr = D_0038E0A0;
    void* net = D_00392068;
    Info_001DC138 info;
    if (!func_001DBFE8(&info, b, a, e)) {
        return;
    }
    Packet_001DC138 pkt;
    if (send) {
        Msg_001DC138 msg;
        func_001FA800(&msg);
        void* conn = func_002A39E0(net, 0);
        pkt.a = a;
        pkt.b = b;
        pkt.x = (int)pos->x;
        pkt.y = (int)pos->y;
        pkt.z = (int)pos->z;
        pkt.c = (int)c;
        pkt.d = (int)d;
        pkt.e = (int)e;
        msg.m_size = 12;
        msg.m_id = 0x35;
        msg.m_data = &pkt;
        func_00200C00(conn, &msg);
    }
    func_001DC540(&pkt);
    func_001DDB00(mgr, &pkt, pos, 0, 0, 0, func_001DD758(mgr, info.m_4));
    func_001DC5A8(&pkt, func_001DC330(&info, c, 0));
    if (func_001DC658(&pkt)) {
        func_001DC578(&pkt, 2);
        return;
    }
    func_001DD290(mgr, info.m_4, &pkt, 0, 0, info.m_0, func_001DC3A0(&info, d, 0));
    func_001DC578(&pkt, 2);
}
