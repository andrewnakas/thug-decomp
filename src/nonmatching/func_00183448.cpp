/* fuzzy: 83.2 */
struct Blk_00183448 {
    unsigned char b[25];
};

struct Rec_00183448 {
    unsigned char m0;
    signed char m_valid;
    unsigned char m_data[25];
    char pad1B[0x1C - 0x1B];
    unsigned int m_buttons;
};

struct Dev_00183448 {
    char pad0[0x18];
    int m_ready;
    char pad1C[0x20 - 0x1C];
    unsigned char m_buf[0x20];
    char pad40[0xD0 - 0x40];
    int m_mode;
    char padD4[0xE4 - 0xD4];
    int m_port;
};

struct Sub_00183448 {
    union {
        unsigned int m_word;
        unsigned char m_b[0x1C];
        struct {
            unsigned char m_pad;
            Blk_00183448 m_blk;
        } m_s;
    };
    unsigned int m_cur;
    unsigned int m_press;
    unsigned int m_release;
    unsigned int m_change;
    unsigned int m_raw;
    unsigned int m_prev;
};

struct Pad_00183448 {
    Dev_00183448* m_dev;
    char m_list[0x4C];
    Sub_00183448 m_sub;
    Rec_00183448* m_play;
    int m88;
    Rec_00183448* m_rec;
    void Update();
};

extern int D_0038C3C0;
extern int D_00388820;
extern int D_0038ED78;
extern int D_0038ED7C;
extern int D_0038ED80;
extern int D_0038ED84;
extern unsigned int D_003940C8[];
extern unsigned int D_003940D0[];
extern unsigned int D_003940D8[];
extern char D_00361880[];
extern char D_003618A0[];
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_00105200(void* list, int arg);
extern "C" void func_00106378();
extern "C" void func_00182580(unsigned int a, unsigned int b, unsigned int c);
extern "C" int func_001833F8(int p);
extern "C" void func_00183878(Sub_00183448* s);
extern "C" void func_00183A90(Sub_00183448* s);
extern "C" void func_00183B48(Sub_00183448* s);

static inline void Latch(Sub_00183448* s, unsigned int cur)
{
    unsigned int chg = s->m_prev ^ cur;
    s->m_raw = cur;
    s->m_change = chg;
    s->m_press = chg & cur;
    s->m_cur = cur;
    s->m_release = chg & ~cur;
}

void Pad_00183448::Update()
{
    Rec_00183448* r = m_play;
    if (r && r->m_valid) {
        m_sub.m_prev = m_sub.m_raw;
        unsigned int cur = r->m_buttons;
        unsigned int chg = m_sub.m_prev ^ cur;
        m_sub.m_raw = cur;
        m_sub.m_change = chg;
        m_sub.m_press = chg & cur;
        m_sub.m_cur = cur;
        m_sub.m_release = chg & ~cur;
        for (int i = 0; i < 25; i++) {
            m_sub.m_s.m_blk.b[i] = m_play->m_data[i];
        }
        func_00105200(m_list, 0);
        m_play++;
        return;
    }
    Dev_00183448* dev = m_dev;
    if (!dev) {
        return;
    }
    if (!dev->m_ready) {
        return;
    }
    unsigned char* buf = dev->m_buf;
    int port = D_0038C3C0;
    Sub_00183448* s = &m_sub;
    if (m_rec) {
        m_rec->m_valid = 0;
    }
    if (buf[0] != 0) {
        return;
    }
    int type = buf[1] >> 4;
    s->m_prev = s->m_raw;
    s->m_raw = ((buf[2] << 8) | buf[3]) ^ 0xFFFF;
    Latch(s, s->m_raw | buf[0x14] << 16);
    switch (type) {
    case 2:
    case 3:
    case 4:
        if (type >= 4) {
            func_00183B48(&m_sub);
        }
        break;
    case 5:
        s->m_b[1] = buf[4];
        s->m_b[2] = buf[5];
        s->m_b[3] = buf[6];
        s->m_b[4] = buf[7];
        func_00183B48(&m_sub);
        if (func_001833F8(port)) {
            func_00183A90(&m_sub);
        }
        break;
    case 7:
        if (m_dev->m_mode == 1) {
            s->m_s.m_blk = *(Blk_00183448*)(dev->m_buf + 4);
        } else {
            s->m_b[1] = buf[4];
            s->m_b[2] = buf[5];
            s->m_b[3] = buf[6];
            s->m_b[4] = buf[7];
            func_00183B48(&m_sub);
            func_00183878(&m_sub);
            if (func_001833F8(port)) {
                func_00183A90(&m_sub);
            }
        }
        break;
    }
    if (m_rec) {
        m_rec->m_buttons = s->m_raw;
        m_rec->m_valid = 1;
        for (int i = 0; i < 25; i++) {
            m_rec->m_data[i] = s->m_s.m_blk.b[i];
        }
        m_rec++;
    }
    if (m_dev) {
        D_003940C8[m_dev->m_port] = m_sub.m_cur;
        D_003940D8[m_dev->m_port] = m_sub.m_press;
        D_003940D0[m_dev->m_port] = m_sub.m_release;
        func_00182580(m_sub.m_cur, m_sub.m_press, m_sub.m_release);
        if (D_00388820) {
            int quit = 0;
            if (m_sub.m_cur != 0 || (m_sub.m_word & 0xFFFFFF00) != 0x80808000 || m_sub.m_b[4] != 0x80) {
                D_0038ED80 = D_0038ED7C;
            }
            if (m_dev->m_port == 0) {
                if (D_0038ED80 && --D_0038ED80 == 0) {
                    func_00103F28(D_00361880);
                    D_0038ED78 = 2;
                    quit = 1;
                }
                if (D_0038ED84 && --D_0038ED84 == 0) {
                    func_00103F28(D_003618A0);
                    D_0038ED78 = 3;
                    quit = 1;
                }
            }
            if ((m_sub.m_cur & 0x900) == 0x900) {
                quit = 1;
                D_0038ED78 = 5;
            }
            if (quit) {
                func_00106378();
            }
        }
    }
    func_00105200(m_list, 0);
}
