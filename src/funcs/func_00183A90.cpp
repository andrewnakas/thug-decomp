struct Pad_00183A90 {
    char pad0[3];
    unsigned char m_x;
    unsigned char m_y;
    unsigned char m_right;
    unsigned char m_left;
    unsigned char m_up;
    unsigned char m_down;
    char pad9[0x13];
    unsigned int m_flags;
};

static inline int Abs(int v)
{
    return v < 0 ? -v : v;
}

extern "C" void func_00183A90(Pad_00183A90* pad)
{
    if (pad->m_flags & 0xF000) {
        return;
    }
    if (pad->m_x > 0x80) {
        pad->m_right = pad->m_x + 0x80;
        pad->m_flags |= 0x2000;
    } else if (pad->m_x < 0x80) {
        pad->m_flags |= 0x8000;
        pad->m_left = Abs(0x80 - pad->m_x);
    }
    if (pad->m_y < 0x80) {
        pad->m_up = pad->m_y + 0x80;
        pad->m_flags |= 0x1000;
    } else if (pad->m_y > 0x80) {
        pad->m_down = Abs(0x80 - pad->m_y);
        pad->m_flags |= 0x4000;
    }
}
