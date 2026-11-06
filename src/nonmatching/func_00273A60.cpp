/* fuzzy: 99.3 */
/* near miss: 3 words: the inlined GetId's net pointer lands in $v1 (game $a0, reusing m_44's reg); everything else matches (spilled int locals declared 30..44 then assigned 40,34,38,30,3C; shared loop index i; walking Bit pointer) */
struct Player_00273A60 {
    char pad[0x1804];
    unsigned int m_1804;
};

struct Skater_00273A60 {
    char pad[0x50];
    float m_50[3];
    char pad5C[0xC0 - 0x5C];
    float m_C0[16];
    char pad100[0x320 - 0x100];
    int m_320;
};

struct Bit_00273A60 {
    int m_0;
    int m_on;
    int m_8;
};

struct State_00273A60 {
    char pad[0x1C];
    signed char m_1C;
    char pad1D[3];
    int m_20;
    Bit_00273A60 m_bits[23];
    char padB0[0x138 - 0x24 - 23 * 12];
    int m_138;
    signed char m_13C;
    char pad13D[0x180 - 0x13D];
    int m_180;
};

struct Net_00273A60 {
    char pad[0x5C];
    unsigned short m_5C;
};

struct Owner_00273A60 {
    char pad[0x29C];
    Net_00273A60* m_29C;
    short GetId()
    {
        if (m_29C) {
            return m_29C->m_5C;
        }
        return -1;
    }
};

struct Snap_00273A60 {
    short m_a[3];
    char pad6[0xA];
    short m_b[3];
    char pad16[0xA];
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
};

extern void* D_00392068;
extern "C" Player_00273A60* func_002A39E0(void* mgr, int id);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" bool func_002A1A38(void* mgr);
extern "C" void func_00100498(const float* m, float* out);
extern "C" int func_00290888(void* comp);

struct Sync_00273A60 {
    char pad[0xC];
    Skater_00273A60* m_C;
    char pad10[0x20 - 0x10];
    signed char m_20;
    char pad21;
    short m_22[3];
    short m_28[3];
    char pad2E[2];
    unsigned int m_30;
    int m_34;
    signed char m_38;
    signed char m_39;
    signed char m_3A;
    signed char m_3B;
    short m_3C;
    char pad3E[2];
    State_00273A60* m_40;
    Owner_00273A60* m_44;
    unsigned int GetDirty();
};

unsigned int Sync_00273A60::GetDirty()
{
    unsigned int flags = 0;
    unsigned int mask = 0;
    bool force = false;
    Player_00273A60* player = func_002A39E0(D_00392068, m_C->m_320);
    void* comp = func_00185578(m_C, 0xB1D5A3E1);
    if (func_002A1A38(D_00392068) || player->m_1804 % 15 == 0) {
        force = true;
    }
    float pos[4];
    int i;
    short a[3];
    short b[3];
    func_00100498(m_C->m_C0, pos);
    int v30;
    int v34;
    int v38;
    int v3C;
    int v40;
    int v44;
    v40 = m_40->m_180;
    v34 = m_40->m_1C;
    v38 = m_40->m_13C;
    v30 = m_40->m_138;
    v3C = m_40->m_20 == 1;
    v44 = m_44->GetId();
    Bit_00273A60* bit = m_40->m_bits;
    for (i = 0; i < 23; i++, bit++) {
        if (bit->m_on) {
            mask |= 1 << i;
        } else {
            mask &= ~(1 << i);
        }
    }
    int anim = func_00290888(comp);
    for (i = 0; i < 3; i++) {
        if (i == 1) {
            a[1] = (int)(m_C->m_50[1] * 4.0f);
        } else {
            a[i] = (int)(m_C->m_50[i] + m_C->m_50[i]);
        }
        if (a[i] != m_22[i] || force) {
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
        if (b[i] != m_28[i] || force) {
            m_28[i] = b[i];
            if (i == 0) {
                flags |= 8;
            } else if (i == 1) {
                flags |= 0x10;
            } else if (i == 2) {
                flags |= 0x20;
            }
        }
    }
    if (v34 != m_38 || v30 != m_39 || v38 != m_20 || v3C != m_3A || v40 != m_3B || force) {
        flags |= 0x40;
    }
    if (mask != m_30 || anim != m_34 || force) {
        flags |= 0x80;
    }
    if (v44 != m_3C) {
        flags |= 0x100;
    }
    return flags;
}
