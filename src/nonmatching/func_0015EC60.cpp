/* fuzzy: 82.6 */
typedef int qword __attribute__((mode(TI)));

struct Mat_0015EC60 {
    qword r[4];
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

extern float D_00387664;
extern Mat_0015EC60 D_003E1180;
extern unsigned int* D_00394274;
extern unsigned int* D_00394278;
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
        b->m_age += D_00387664;
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

    if (D_0039427C != D_00394298)
        func_001617A0(D_00394298);

    unsigned int* p = D_00394274;
    D_00394278 = p;
    p[0] = 0x30000014;
    p[1] = (unsigned int)((char*)this + 0x280);
    D_00394274 = p + 2;
    p[2] = 0x01000101;
    D_0039429C = 1;
    D_00394274 = p + 3;
    int qwc = (m_count * 2 + 0x14) & 0xFF;
    p[3] = 0x6C000000 | (qwc << 16) | ((D_00394280 & 0x3FF) | 0x8000);
    D_00394274 = p + 4;
    D_00394278 = p + 4;
    D_00394290 = qwc;
    p[4] = 0x10000000;
    p[5] = 0;
    D_00394274 = p + 6;

    b = m_tail;
    for (int i = 0; i < m_count; i++) {
        if (b == End())
            b = m_ring;
        *(float*)&D_00394274[0] = b->m_age;
        *(float*)&D_00394274[1] = b->m_invRate;
        D_00394274[2] = b->m_count;
        D_00394274[3] = b == m_head ? 0x8000 : 0;
        D_00394274[4] = b->m_seed[0];
        D_00394274[5] = b->m_seed[1];
        D_00394274[6] = b->m_seed[2];
        D_00394274[7] = b->m_seed[3];
        int c = b->m_count;
        b++;
        D_00394274 += 8;
        D_003940A4 += c;
    }

    *D_00394274 = 0x1400000A;
    D_00394274++;
    D_00394294 = D_00394280;
    int type = (*D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *D_00394274 = 0;
        D_00394274++;
    }
    if (type != 3 && type != 0 && type != 4) {
        *(unsigned short*)D_00394278 = ((int)D_00394274 - (int)D_00394278 - 8) >> 4;
    }
    if (D_0039427C != D_003942A0)
        func_001617A0(D_003942A0);
}
