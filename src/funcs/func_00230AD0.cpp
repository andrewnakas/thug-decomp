struct Player_00230AD0 {
    char pad[0x1804];
    unsigned int m_1804;
};

struct Vec3_00230AD0 {
    float v[3];
};

struct Snap_00230AD0 {
    char pad[0x50];
    float m_50[3];
    char pad5C[4];
    Vec3_00230AD0 m_60;
    char pad6C[4];
    int m_70;
    int m_74;
    signed char m_78;
    char pad79[3];
    signed char m_7C;
    signed char m_7D;
    signed char m_7E;
    char pad7F[5];
    signed char m_84;
    char pad85[3];
    short m_88;
};

struct Server_00230AD0 {
    char pad[0x6C];
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
    unsigned int GetDirty(Snap_00230AD0* s, int player);
};

extern void* D_00392068;
extern "C" Player_00230AD0* func_002A39D8(void* mgr);

unsigned int Server_00230AD0::GetDirty(Snap_00230AD0* s, int player)
{
    unsigned int flags = 0;
    bool force = func_002A39D8(D_00392068)->m_1804 % 60 == 0;
    unsigned char idx = player;
    short a[3];
    short b[3];
    float pos[3];
    int i;
    for (i = 0; i < 3; i++) {
        pos[i] = s->m_60.v[i];
    }
    for (i = 0; i < 3; i++) {
        if (i == 1) {
            a[1] = (int)(s->m_50[1] * 4.0f);
        } else {
            a[i] = (int)(s->m_50[i] + s->m_50[i]);
        }
        if (a[i] != m_84[idx][i] || force) {
            if (i == 0) {
                flags |= 1;
            } else if (i == 1) {
                flags |= 2;
            } else if (i == 2) {
                flags |= 4;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        b[i] = (int)(pos[i] * 4096.0f);
        if (b[i] != m_B4[idx][i] || force) {
            if (i == 0) {
                flags |= 8;
            } else if (i == 1) {
                flags |= 0x10;
            } else if (i == 2) {
                flags |= 0x20;
            }
        }
    }
    int v78 = s->m_78;
    int v7C = s->m_7C;
    int v84 = s->m_84;
    int v7D = s->m_7D;
    int v7E = s->m_7E;
    if (v78 != m_124[idx] || v7C != m_12C[idx] || v84 != m_6C[idx] || v7D != m_74[idx] || v7E != m_7C[idx] || force == true) {
        flags |= 0x40;
    }
    int v70 = s->m_70;
    int v74 = s->m_74;
    int* e = &m_E4[idx];
    if (v70 != *e || v74 != *(m_104 + idx) || force == true) {
        flags |= 0x80;
    }
    int v88 = s->m_88;
    if (v88 != m_13C[idx] || force == true) {
        flags |= 0x100;
    }
    return flags;
}
