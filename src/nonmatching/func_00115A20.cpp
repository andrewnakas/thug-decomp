/* fuzzy: 92.8 */
struct Hdr_00115A20 {
    int m_count;
    unsigned short m_n4;
    short pad6;
    unsigned short m_n8;
    short padA;
    unsigned int m_numSub;
};

struct Geom_00115A20 {
    int m0;
    int m_flags;
    int m_count;
    int mC;
    int m10;
    int m14;
    char* m18;
    char* m1C;
    char* m20;
    char* m24;
    char* m28;
    int m2C;
    void** m_subs;
    int m34;
    int m38;
    short m3C;
    short m3E;
    unsigned short m_numSubs;
    int Parse(Hdr_00115A20* hdr);
};

extern "C" void func_00115C68(Geom_00115A20* g, char* p, int i);
extern "C" int  func_00115C98(Geom_00115A20* g, char* p, int i);
extern "C" int func_00115CC8(Geom_00115A20* g);
extern "C" void func_00115840(Geom_00115A20* g, int, int, int flags);
extern "C" void** func_0010BDE0(int size);
extern "C" void* func_00118DF0(char** p);

static inline void Align4(char** pp)
{
    if ((int)*pp & 3) {
        *pp = *pp + 4 - ((int)*pp & 3);
    }
}

int Geom_00115A20::Parse(Hdr_00115A20* hdr)
{
    char* p = (char*)(hdr + 1);
    int count = hdr->m_count;
    m_count = count;
    m3C = hdr->m_n4;
    m3E = hdr->m_n8;
    if (m_flags & 0x1000000) {
        m24 = p;
        p += count * 4;
    } else {
        m24 = 0;
    }
    if (m_flags & 0x80000) {
        m28 = p;
        int n = *(int*)p;
        p += 4;
        p += ((n - 1) / 32 + 1) * 4;
    }
    char* start = p;
    int size;
    if (m_flags & 0x400000) {
        size = m_count * 4;
    } else {
        size = m_count * 2;
    }
    m20 = start;
    p = start + size;
    Align4(&p);
    for (int i = 0; i < m_count; i++) {
        func_00115C68(this, m20, i);
        func_00115C98(this, m20, i);
    }
    if (func_00115CC8(this)) {
        m18 = p;
        m1C = p + m3C * 16;
        p = m1C + m3E * 16;
    } else {
        m18 = p;
        m1C = p + m3C * 8;
        p = m1C + m3E * 8;
    }
    func_00115840(this, 0, 0, m_flags);
    Align4(&p);
    if (hdr->m_numSub == 0) {
        m_subs = 0;
    } else {
        m_subs = func_0010BDE0(hdr->m_numSub * 4);
        for (unsigned int i = 0; i < hdr->m_numSub; i++) {
            void* s = func_00118DF0(&p);
            if (!s) {
                return 0;
            }
            m_subs[i] = s;
        }
    }
    m_numSubs = hdr->m_numSub;
    return 1;
}
