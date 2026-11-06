struct Src_00111428 {
    char pad0[0x14];
    int m14;
    int m18;
    char pad1C[0x6C - 0x1C];
    int m_type;
};

struct Req_00111428 {
    int m_a;
    int m_b;
    int m_c;
    int m_d;
};

extern "C" int func_00320438();
extern "C" int func_00320490();

class Queue_00111428 {
public:
    int m0[16];
    Req_00111428 m_reqs[16];
    volatile int m_count;
    int Push(int a, int b, Src_00111428* s);
};

int Queue_00111428::Push(int a, int b, Src_00111428* s)
{
    if (m_count >= 16) {
        return 0;
    }
    func_00320438();
    if (s->m_type == 3) {
        m_reqs[m_count].m_c = s->m14;
        m_reqs[m_count].m_d = s->m18;
    } else {
        m_reqs[m_count].m_c = 0;
        m_reqs[m_count].m_d = 0;
    }
    m_reqs[m_count].m_a = a;
    m_reqs[m_count++].m_b = b;
    func_00320490();
    return 1;
}
