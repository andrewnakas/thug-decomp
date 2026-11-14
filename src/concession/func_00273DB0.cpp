/* force: {"kind": "spill", "order": [392, 393, 395, 388]} */
/* force: {"kind": "fr", "reg": 179, "hard": 4} */
/* blocked: stack-slot order of 4 spilled pseudos (&m_28, &b, flags&0x40, flags&0x100) and m_board in a0 not v1. Tried moving the m_28 store, swapping a/b, BoardId as a local / ternary: no gain. */
/* sym: _vt$11Cb_00200C00 = 0x00366B58 */
/* sym: __12Msg_00273DB0 = 0x001FA800 */
typedef int qword_00273DB0 __attribute__((mode(TI)));

struct Vec4_00273DB0 {
    union {
        qword_00273DB0 q;
        struct {
            float x, y, z, w;
        } f;
    };
    const float& operator[](int i) const { return (&f.x)[i]; }
    Vec4_00273DB0 operator-(const Vec4_00273DB0& o) const
    {
        float x = (*this)[0] - o[0];
        float y = (*this)[1] - o[1];
        float z = (*this)[2] - o[2];
        float w = (*this)[3] - o[3];
        Vec4_00273DB0 r;
        r.f.x = x;
        r.f.y = y;
        r.f.z = z;
        r.f.w = w;
        return r;
    }
};

struct Skater_00273DB0 {
    char pad[0x50];
    Vec4_00273DB0 m_pos;
    char pad60[0xC0 - 0x60];
    float m_matrix[16];
    char pad100[0x320 - 0x100];
    int m_id;
};

struct Slot_00273DB0 {
    int m_0;
    int m_on;
    int m_8;
    bool On() { return m_on; }
};


struct Board_00273DB0 {
    char pad[0x5C];
    unsigned short m_5C;
    unsigned short Id() { return m_5C; }
};

struct Owner_00273DB0 {
    char pad[0x29C];
    Board_00273DB0* m_board;
    short BoardId() { if (m_board) return m_board->Id(); return -1; }
};

struct Conn_00273DB0 {
    unsigned int m_time;
    char pad4[0x1804 - 4];
    unsigned int m_frame;
};

struct Msg_00273DB0 {
    unsigned char m_id;
    unsigned char m1;
    unsigned short m_len;
    char* m_data;
    int m_prio;
    int mC;
    unsigned char m10;
    int m_14;
    int m18;
    int m1C;
    Msg_00273DB0();
};

struct Bits_00273DB0 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
};

struct Item_00273DB0;

struct Cb_00200C00 {
    int m0;
    int m4;
    Cb_00200C00() : m4(0) {}
    virtual ~Cb_00200C00() {}
    virtual void Run();
};

struct Sync_00273DB0 {
    char pad[0xC];
    Skater_00273DB0* m_skater;
    char pad10[0xC];
    unsigned int m_lastTime;
    signed char m_20;
    char pad21;
    short m_22[3];
    short m_28[3];
    char pad2E[2];
    int m_30;
    int m_34;
    signed char m_38;
    signed char m_39;
    signed char m_3A;
    signed char m_3B;
    short m_3C;
    char pad3E[2];
    char* m_state;
    Owner_00273DB0* m_owner;
    void SendUpdate();
};

extern void* D_00392068;
extern int D_00394158;
extern Vec4_00273DB0 D_00452FB0;
extern "C" Conn_00273DB0* func_002A39E0(void* mgr, int id);
extern "C" void* func_00185578(Skater_00273DB0* s, unsigned int crc);
extern "C" bool func_002A1A38(void* mgr);
extern "C" Item_00273DB0* func_00200EC0(Conn_00273DB0* c, Cb_00200C00* cb);
extern "C" unsigned int func_002027F0(Item_00273DB0* it);
extern "C" Bits_00273DB0* func_001FAA08(Bits_00273DB0* b);
extern "C" void func_001FAA40(Bits_00273DB0* b, char* buf, int size);
extern "C" void func_001FAA70(Bits_00273DB0* b, int value, int bits);
extern "C" void func_001FAB48(Bits_00273DB0* b);
extern "C" int func_001FAA60(Bits_00273DB0* b);
extern "C" void func_00100498(const float* m, float* out);
extern "C" int func_00290888(void* comp);
extern "C" unsigned int func_00273A60(Sync_00273DB0* self);
extern "C" void func_00200C00(Conn_00273DB0* c, Msg_00273DB0* msg);

/* Builds this skater's state update (position, rotation, flags) as a bit stream and sends it
   as message 0x23 when something changed or the periodic refresh is due. */
void Sync_00273DB0::SendUpdate()
{
    char buf[0x1000];
    float rot[3];
    short a[3];
    short b[3];
    Msg_00273DB0 msg;
    Bits_00273DB0 bits;
    Conn_00273DB0* conn;
    int v138;
    int v1C;
    int v13C;
    int v20;
    int v180;
    unsigned int mask;
    short boardId;
    int v1C_comp;
    unsigned int flags;
    mask = 0;
    func_001FAA08(&bits);
    conn = func_002A39E0(D_00392068, m_skater->m_id);
    void* comp = func_00185578(m_skater, 0xB1D5A3E1);
    bool online = func_002A1A38(D_00392068);
    bool force = false;
    if (online || conn->m_frame % 15 == 0)
        force = true;
    if (!online && !force) {
        Cb_00200C00 cb;
        Item_00273DB0* it = func_00200EC0(conn, &cb);
        if (conn->m_time - m_lastTime < func_002027F0(it))
            return;
    }
    m_lastTime = conn->m_time;
    func_001FAA40(&bits, buf, 0x400);
    func_00100498(m_skater->m_matrix, rot);
    v180 = *(int*)(m_state + 0x180);
    v1C = *(signed char*)(m_state + 0x1C);
    v13C = *(signed char*)(m_state + 0x13C);
    v138 = *(int*)(m_state + 0x138);
    v20 = *(int*)(m_state + 0x20) == 1;
    boardId = m_owner->BoardId();
    int i;
    Slot_00273DB0* slot = (Slot_00273DB0*)(m_state + 0x24);
    for (i = 0; i < 23; i++) {
        if (slot[i].On())
            mask |= 1 << i;
        else
            mask &= ~(1 << i);
    }
    v1C_comp = func_00290888(comp);
    func_001FAA70(&bits, conn->m_time, 32);
    flags = func_00273A60(this);
    func_001FAA70(&bits, flags, 9);
    if (online) {
        if (!D_00394158)
            D_00394158 = 1;
        Vec4_00273DB0 delta = m_skater->m_pos - D_00452FB0;
        D_00452FB0 = m_skater->m_pos;
    }
    for (i = 0; i < 3; i++) {
        if (i == 1) {
            a[1] = (int)(m_skater->m_pos.f.y * 4.0f);
        } else {
            a[i] = (int)(m_skater->m_pos[i] + m_skater->m_pos[i]);
        }
        if (i == 0) {
            if (flags & 1)
                func_001FAA70(&bits, a[0], 16);
        } else if (i == 1) {
            if (flags & 2)
                func_001FAA70(&bits, a[1], 16);
        } else if (i == 2) {
            if (flags & 4)
                func_001FAA70(&bits, a[2], 16);
        }
        m_22[i] = a[i];
    }
    for (i = 0; i < 3; i++) {
        b[i] = (int)(rot[i] * 4096.0f);
        if (i == 0) {
            if (flags & 8)
                func_001FAA70(&bits, b[0], 16);
        } else if (i == 1) {
            if (flags & 0x10)
                func_001FAA70(&bits, b[1], 16);
        } else if (i == 2) {
            if (flags & 0x20)
                func_001FAA70(&bits, b[2], 16);
        }
        m_28[i] = b[i];
    }
    if (flags & 0x40) {
        m_38 = v1C;
        m_39 = v138;
        m_20 = v13C;
        m_3A = v20;
        m_3B = v180;
        int v = v1C;
        if (v138)
            v |= -0x80;
        func_001FAA70(&bits, v, 4);
        func_001FAA70(&bits, v13C, 6);
        func_001FAA70(&bits, v20, 1);
        func_001FAA70(&bits, v180, 1);
    }
    if (flags & 0x80) {
        m_30 = mask;
        m_34 = v1C_comp;
        func_001FAA70(&bits, mask, 5);
        func_001FAA70(&bits, v1C_comp, 3);
    }
    if (flags & 0x100) {
        m_3C = boardId;
        func_001FAA70(&bits, boardId, 16);
    }
    func_001FAB48(&bits);
    int len = func_001FAA60(&bits);
    msg.m_id = 0x23;
    msg.m_len = len;
    msg.m_14 = 1;
    msg.m_prio = 0x81;
    msg.m_data = buf;
    func_00200C00(conn, &msg);
}
