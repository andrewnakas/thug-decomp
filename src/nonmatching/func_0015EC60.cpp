/* fuzzy: 93.1 */
typedef int qword __attribute__((mode(TI)));

struct Row_0015EC60 {
    qword q;
};

struct Mat_0015EC60 {
    Row_0015EC60 r[4];
    Mat_0015EC60() {}
    const Row_0015EC60& operator[](int i) const { return r[i]; }
    Mat_0015EC60(const Mat_0015EC60& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_0015EC60& operator=(const Mat_0015EC60& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

/* One emission burst in the ring buffer (0x20 bytes). */
struct Burst_0015EC60 {
    int m_count;
    float m_rate;
    float m_invRate;
    float m_age;
    unsigned int m_seed[4];
};

struct Src_0015EC60 {
    char pad[0x28];
    long m28;
    long m30;
};

extern Mat_0015EC60 D_003E1180;
extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern int D_0039427C;
extern unsigned int D_00394280;
extern int D_00394290;
extern int D_00394294;
extern int D_00394298;
extern int D_0039429C;
extern int D_003942A0;
extern int D_003940A4;

extern "C" unsigned int func_00335048();
extern "C" void func_0015F870(Burst_0015EC60* b, int n);
extern "C" void func_00323318(Mat_0015EC60* d, Mat_0015EC60* a, Mat_0015EC60* b);
extern "C" void func_001617A0(int mode);

static inline void Put_0015EC60(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void Tag_0015EC60(unsigned int v, unsigned int a)
{
    unsigned int* p = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)p;
    p[0] = v;
    p[1] = a;
    D_00394274 = (unsigned char*)(p + 2);
}

static inline void Cycle_0015EC60(int n)
{
    Put_0015EC60(0x01000000 | (n << 8) | n);
    D_0039429C = n;
}

static inline Mat_0015EC60 ToScreen(const Mat_0015EC60& a)
{
    Mat_0015EC60 m = a;
    func_00323318(&m, &D_003E1180, &m);
    return m;
}

class Emitter_0015EC60 {
public:
    char pad0[0x160];
    float m_rate;
    char pad164[0x20C - 0x164];
    Src_0015EC60* m_src;
    char pad210[0x218 - 0x210];
    int m_capacity;
    int m_count;
    char pad220[0x228 - 0x220];
    Burst_0015EC60* m_ring;
    Burst_0015EC60* m_head;
    Burst_0015EC60* m_tail;
    float m_life;
    int m_emitting;
    char pad23C[4];
    Mat_0015EC60 m_240;
    char pad280[0x2A0 - 0x280];
    long m_2A0;
    char pad2A8[8];
    long m_2B0;
    char pad2B8[0x380 - 0x2B8];
    Mat_0015EC60 m_380;

    Burst_0015EC60* End() { return m_ring + m_capacity; }
    void Update();
};

void Emitter_0015EC60::Update()
{
    float rate = m_rate;
    if (rate != 0.0f && !(m_emitting && rate == m_head->m_rate)) {
        if (m_count < m_capacity) {
            m_count = m_count + 1;
            m_head = m_head + 1;
            if (m_head == End())
                m_head = m_ring;
            m_head->m_rate = m_rate;
            m_head->m_invRate = 1.0f / m_rate;
            m_head->m_age = 0.0f;
            m_head->m_count = 0;
            m_head->m_seed[0] = func_00335048();
            m_head->m_seed[1] = func_00335048();
            m_head->m_seed[2] = func_00335048();
            m_head->m_seed[3] = func_00335048();
            m_emitting = 1;
        } else {
            m_emitting = 0;
        }
    } else {
        m_emitting = rate != 0.0f;
    }

    if (m_count == 0)
        return;

    Burst_0015EC60* b = m_tail;
    for (int i = 0; i < m_count; i++) {
        b->m_age += 1.0f / 60.0f;
        b++;
        if (b == End())
            b = m_ring;
    }
    if (m_emitting)
        m_head->m_count = (int)(m_head->m_age * m_head->m_rate + 1.0f);

    if (m_tail->m_age > m_life) {
        Burst_0015EC60* t = m_tail;
        int n = (int)((t->m_age - m_life) * t->m_rate + 1.0f);
        t->m_count -= n;
        if (m_tail->m_count > 0 || (m_count == 1 && m_emitting)) {
            m_tail->m_age -= (float)n * m_tail->m_invRate;
            func_0015F870(m_tail, n);
        } else {
            m_count = m_count - 1;
            m_tail = m_tail + 1;
            if (m_tail == End())
                m_tail = m_ring;
            if (m_count == 0)
                return;
        }
    }

    if (m_src) {
        m_2A0 = m_src->m28;
        m_2B0 = m_src->m30;
    }
    m_380 = ToScreen(m_240);

    int prev = D_00394298;
    if (D_0039427C != prev)
        func_001617A0(prev);
    unsigned int ad = (unsigned int)((char*)this + 0x280);
    Tag_0015EC60(0x30000014, ad);
    Cycle_0015EC60(1);
    unsigned int num = (m_count * 2 + 0x14) & 0xFF;
    unsigned int hi = (num << 16) | 0x6C000000;
    unsigned int addr = ((unsigned short)D_00394280 & 0x3FF) | 0x8000;
    Put_0015EC60(hi | addr);
    unsigned int* t = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)t;
    D_00394290 = num;
    t[0] = 0x10000000;
    t[1] = 0;
    D_00394274 = (unsigned char*)(t + 2);

    b = m_tail;
    for (int i = 0; i < m_count; i++) {
        if (b == End())
            b = m_ring;
        ((float*)D_00394274)[0] = b->m_age;
        ((float*)D_00394274)[1] = b->m_invRate;
        ((int*)D_00394274)[2] = b->m_count;
        ((int*)D_00394274)[3] = b == m_head ? 0x8000 : 0;
        ((int*)D_00394274)[4] = b->m_seed[0];
        ((int*)D_00394274)[5] = b->m_seed[1];
        ((int*)D_00394274)[6] = b->m_seed[2];
        ((int*)D_00394274)[7] = b->m_seed[3];
        D_00394274 += 0x20;
        D_003940A4 += b->m_count;
        b++;
    }

    Put_0015EC60(0x1400000A);
    D_00394294 = D_00394280;
    int kind = (*(unsigned int*)D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *(unsigned int*)D_00394274 = 0;
        D_00394274 += 4;
    }
    if (kind != 3 && kind != 0 && kind != 4) {
        *(unsigned short*)D_00394278 = ((D_00394274 - D_00394278) - 8) >> 4;
    }
    int next = D_003942A0;
    if (D_0039427C != next)
        func_001617A0(next);
}
