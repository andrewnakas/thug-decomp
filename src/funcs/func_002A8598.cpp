struct Msg_002A8598 {
    unsigned char type;
    char pad1;
    short len;
    void* data;
    int m8;
    int mC;
    char pad[0x10];
};

struct Conn_002A8598;
extern "C" void* func_001FA800(Msg_002A8598* m);
extern "C" void func_00200C00(Conn_002A8598* c, Msg_002A8598* m);

struct Obj_002A8598 {
    char pad[0x18];
    Conn_002A8598* m18[2];
    char pad20[0x15C - 0x20];
    int m15C;
    void SendState();
};

void Obj_002A8598::SendState()
{
    Msg_002A8598 msg;
    func_001FA800(&msg);
    int v = m15C;
    msg.data = &v;
    msg.len = 4;
    msg.type = 0x26;
    msg.mC = 1;
    for (int i = 0; i < 2; i++) {
        if (m18[i]) func_00200C00(m18[i], &msg);
    }
}
