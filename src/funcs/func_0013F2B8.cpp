/* sym: Init__12Sec_0013F2B8iPcN42 = 0x001D76B0 */
extern char D_0038A2F8[];
extern char D_0038A300[];
extern "C" void* memcpy(void* d, const void* s, unsigned int n);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" char* func_003364D8(const char* s, const char* sub);
extern "C" char* func_00331678(char* dst, const char* src);
extern "C" char* func_00132580();
extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" void* func_0010DAB0(const char* name);

struct Vec_0013F2B8;
struct Box_0013F2B8;
extern "C" void func_00102358(Box_0013F2B8* b, const Vec_0013F2B8* p);

struct Box_0013F2B8 {
    char pad[0x20];
    void Add(const Vec_0013F2B8& v) { func_00102358(this, &v); }
};

struct Vec_0013F2B8 {
    float x, y, z, w;
};

struct Sec_0013F2B8 {
    char pad0[0x10];
    Vec_0013F2B8 m_min;
    Vec_0013F2B8 m_max;
    char pad30[0x10];
    void Init(int z, char* a, char* b, char* c, char* d, char* e);
};

extern "C" void func_001D7EE8(Sec_0013F2B8* s);

struct Hdr_0013F2B8 {
    int m0;
    int m_numSecs;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
};

struct Col_0013F2B8 {
    char pad0[8];
    char m_name[0x80];
    int m_numSecs;
    Sec_0013F2B8* m_secs;
    Box_0013F2B8 m_box;
    bool Load(const char* name);
};

bool Col_0013F2B8::Load(const char* name)
{
    func_00331A9C(m_name, name);
    char* dot = func_003364D8(m_name, D_0038A2F8);
    if (dot) {
        memcpy(dot, D_0038A300, 6);
    } else {
        func_00331678(m_name, D_0038A300);
    }
    func_00331678(m_name, func_00132580());
    func_0010BFC0(m_name);
    char* p = (char*)func_0010DAB0(m_name);
    if (p) {
        Hdr_0013F2B8* h = (Hdr_0013F2B8*)p;
        p += sizeof(Hdr_0013F2B8);
        int i = 0;
        m_numSecs = h->m_numSecs;
        m_secs = (Sec_0013F2B8*)p;
        char* verts = (char*)(m_secs + m_numSecs);
        verts = (char*)(((unsigned int)verts + 15) & 0xFFFFFFF0);
        char* b = verts + (h->m14 * 12 + h->m18 * 6);
        char* c = b + h->m8;
        c = (char*)(((unsigned int)c + 3) & 0xFFFFFFFC);
        char* q = c + (h->mC * 10 + h->m10 * 8);
        if (h->mC & 1) q += 2;
        char* d = q + 4;
        char* e = d + *(int*)q;
        for (; i < h->m_numSecs; i++) {
            m_secs[i].Init(0, verts, b, c, d, e);
            func_001D7EE8(m_secs + i);
            m_box.Add(m_secs[i].m_min);
            m_box.Add(m_secs[i].m_max);
        }
    } else {
        return false;
    }
    func_0010BFC8();
    return true;
}
