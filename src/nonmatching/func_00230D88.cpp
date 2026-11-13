/* cflags: -mvu0-use-vf0-vf2 */
/* fuzzy: 94.5 */
struct Vec3_00230D88 {
    float v[3];
};

struct Snap_00230D88 {
    char pad[0x50];
    float m_50[3];
    char pad5C[4];
    Vec3_00230D88 m_60;
    char pad6C[4];
    int m_70;
    int m_74;
    signed char m_78;
    char pad79[3];
    signed char m_7C;
    signed char m_7D;
    signed char m_7E;
    char pad7F;
    unsigned short m_80;
    char pad82[2];
    signed char m_84;
    char pad85[3];
    short m_88;
    char pad8A[6];
};

struct SnapRing_00230D88 {
    char pad[0x1C];
    int m_count;
    Snap_00230D88 m_snaps[20];
};

struct Player_00230D88 {
    char pad[0x18];
    unsigned char m_index;
    char pad19[0x2DC - 0x19];
    SnapRing_00230D88* m_ring;
};

struct Entry_00230D88 {
    char pad[0x18];
    Player_00230D88* m_player;
};

struct Server_00230D88 {
    char pad[0x4C];
    int m_4C[8];
    signed char m_6C[8];
    signed char m_74[8];
    signed char m_7C[8];
    short m_84[8][3];
    short m_B4[8][3];
    int m_E4[8];
    int m_104[8];
    signed char m_124[8];
    signed char m_12C[8];
    char pad134[8];
    short m_13C[8];
};

struct Packet_00230D88 {
    char pad[0x1C];
    Server_00230D88* m_server;
};

struct Client_00230D88 {
    char pad[0x18];
    unsigned short m_id;
    void WriteUpdate(Packet_00230D88* out);
};

extern void* D_00392068;
extern "C" Entry_00230D88* func_002A52F0(void* mgr, int id);
extern "C" int func_00279F48(Snap_00230D88* s);
extern "C" void func_001FAA70(Packet_00230D88* out, int value, int bits);
extern "C" unsigned int func_00230AD0(Server_00230D88* srv, Snap_00230D88* s, int player);

/* Writes the changed parts of this client's newest snapshot to the packet's bit stream and
   remembers what was sent in the server's per-player table. */
void Client_00230D88::WriteUpdate(Packet_00230D88* out)
{
    Player_00230D88* p = func_002A52F0(D_00392068, m_id)->m_player;
    Server_00230D88* srv = out->m_server;
    unsigned char idx = p->m_index;
    SnapRing_00230D88* ring = p->m_ring;
    Snap_00230D88* s = &ring->m_snaps[(ring->m_count - 1) % 20];
    srv->m_4C[idx] = func_00279F48(s);
    float pos[3];
    short a[3];
    short b[3];
    int i;
    for (i = 0; i < 3; i++) {
        pos[i] = s->m_60.v[i];
    }
    func_001FAA70(out, s->m_80, 16);
    unsigned int flags = func_00230AD0(srv, s, idx);
    func_001FAA70(out, flags, 9);
    for (i = 0; i < 3; i++) {
        if (i == 1) {
            a[1] = (int)(s->m_50[1] * 4.0f);
        } else {
            a[i] = (int)(s->m_50[i] + s->m_50[i]);
        }
        if (i == 0) {
            if (flags & 1)
                func_001FAA70(out, a[0], 16);
        } else if (i == 1) {
            if (flags & 2)
                func_001FAA70(out, a[1], 16);
        } else if (i == 2) {
            if (flags & 4)
                func_001FAA70(out, a[2], 16);
        }
        srv->m_84[idx][i] = a[i];
    }
    for (i = 0; i < 3; i++) {
        b[i] = (int)(pos[i] * 4096.0f);
        if (i == 0) {
            if (flags & 8)
                func_001FAA70(out, b[0], 16);
        } else if (i == 1) {
            if (flags & 0x10)
                func_001FAA70(out, b[1], 16);
        } else if (i == 2) {
            if (flags & 0x20)
                func_001FAA70(out, b[2], 16);
        }
        srv->m_B4[idx][i] = b[i];
    }
    int v78 = s->m_78;
    int v7C = s->m_7C;
    int v84 = s->m_84;
    int v7D = s->m_7D;
    int v7E = s->m_7E;
    if (flags & 0x40) {
        int v = v78;
        if (v7C)
            v = v78 | -0x80;
        func_001FAA70(out, v, 4);
        func_001FAA70(out, v84, 6);
        func_001FAA70(out, v7D, 1);
        func_001FAA70(out, v7E, 1);
        srv->m_124[idx] = v78;
        srv->m_12C[idx] = v7C;
        srv->m_6C[idx] = v84;
        srv->m_74[idx] = v7D;
        srv->m_7C[idx] = v7E;
    }
    int v70 = s->m_70;
    int v74 = s->m_74;
    if (flags & 0x80) {
        srv->m_E4[idx] = v70;
        srv->m_104[idx] = v74;
        func_001FAA70(out, v70, 5);
        func_001FAA70(out, v74, 3);
    }
    if (flags & 0x100) {
        srv->m_13C[idx] = s->m_88;
        func_001FAA70(out, s->m_88, 16);
    }
}
