/* fuzzy: 84.4 */
/* near miss: size 0x25c vs 0x254; inner-loop shape right (if (p && check) form gives the game's rotated loop); ours gets loop-align nops and hoists &bits out of the outer loop (game: no nops, &bits recomputed, only &msg hoisted); regs n/i/start differ */
extern char D_00371C78[];
extern void* D_00392068;

struct Iter_00231188 {
    int m_0;
    int m_4;
    void* m_vtbl;
};

struct Bits_00231188 {
    char pad[0x18];
    int m_18;
    void* m_1C;
};

struct Msg_00231188 {
    unsigned char m_id;
    char pad1;
    unsigned short m_len;
    void* m_data;
    char pad8[0x18];
};

struct Conn_00231188 {
    char pad[0x48];
    int m_48;
};

struct Node_00231188 {
    char pad[0x1C];
    Conn_00231188* m_1C;
};

struct Player_00231188 {
    char pad[0x18];
    void* m_18;
};

extern "C" void* func_002A39D8(void* net);
extern "C" Node_00231188* func_002A53F8(void* net, Iter_00231188* it, int a);
extern "C" Node_00231188* func_002A5490(void* net, Iter_00231188* it, int a);
extern "C" void func_001FAA08(Bits_00231188* b);
extern "C" int func_00202778(Conn_00231188* c);
extern "C" void func_001FAA40(Bits_00231188* b, char* buf, int size);
extern "C" int func_002B30B0(Node_00231188* n);
extern "C" void func_002B30B8(Node_00231188* n, int v);
extern "C" int func_002B30C0(Node_00231188* n);
extern "C" Player_00231188* func_002A52F0(void* net, unsigned short id);
extern "C" bool func_00230A38(void* self, Node_00231188* n, void* msg);
extern "C" void func_001FAA70(Bits_00231188* b, unsigned int v, int bits);
extern "C" void func_00230D88(void* p, Bits_00231188* b);
extern "C" void func_001FAB48(Bits_00231188* b);
extern "C" int func_001FAA60(Bits_00231188* b);
extern "C" unsigned int func_001FA800(Msg_00231188* m);
extern "C" int func_002B3080(Node_00231188* n);
extern "C" void func_001FF970(void* server, int conn, Msg_00231188* m);

struct Srv_00231188 {
    char pad[0x20];
    void* m_20;
    void Send();
};

void Srv_00231188::Send()
{
    Iter_00231188 it;
    it.m_4 = 0;
    it.m_vtbl = D_00371C78;
    void* net = D_00392068;
    void* server;
    void* ctx = m_20;
    server = func_002A39D8(net);
    char buf[0x1000];
    for (Node_00231188* n = func_002A53F8(net, &it, 1); n; n = func_002A5490(net, &it, 1)) {
        Bits_00231188 bits;
        func_001FAA08(&bits);
        if (!func_00202778(n->m_1C)) {
            continue;
        }
        func_001FAA40(&bits, buf, 0x1000);
        int mask = 0;
        int cnt = 0;
        bits.m_18 = n->m_1C->m_48;
        bits.m_1C = n;
        int start = (func_002B30B0(n) + 1) % 8;
        int slot;
        Player_00231188* p;
        for (int i = 0; i < 8; i++) {
            slot = (start + i) % 8;
            p = func_002A52F0(net, slot);
            if (p && func_00230A38(ctx, n, p->m_18)) {
                cnt++;
                mask |= 1 << slot;
                if (cnt >= func_002B30C0(n)) {
                    break;
                }
            }
        }
        if (!cnt) {
            continue;
        }
        func_001FAA70(&bits, mask, 8);
        for (int i = 0; i < 8; i++) {
            if ((mask >> i) & 1) {
                func_00230D88(func_002A52F0(net, i)->m_18, &bits);
                func_002B30B8(n, i);
            }
        }
        func_001FAB48(&bits);
        int len = func_001FAA60(&bits);
        if (len) {
            Msg_00231188 msg;
            func_001FA800(&msg);
            msg.m_data = buf;
            msg.m_len = len;
            msg.m_id = 0x23;
            func_001FF970(server, func_002B3080(n), &msg);
        }
    }
    it.m_vtbl = D_00371C78;
}
