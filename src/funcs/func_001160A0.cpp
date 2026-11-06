extern "C" void func_0010ECF8(void* p);

struct Hdr_001160A0 {
    int m0;
    unsigned int m_flags;
    float m_scale;
};

class Node_001160A0;
extern "C" int func_00115A20(Node_001160A0* self, char* body, int arg);
extern "C" int func_00115848(Node_001160A0* self, char* body, int arg);

class Node_001160A0 {
public:
    float m_scale;
    unsigned int m_flags;
    int m8;
    Hdr_001160A0* m_data;
    void* m_file;
    char pad14[0x40 - 0x14];
    int m_count : 16;
    unsigned int m_b16 : 1;
    unsigned int m_ok : 1;
    unsigned int m_ext : 1;
    int Parse(int a, int b, int arg);
};

int Node_001160A0::Parse(int a, int b, int arg)
{
    int r = 0;
    if (m_file) {
        func_0010ECF8(m_file);
        m_file = 0;
    }
    char* p = (char*)m_data;
    Hdr_001160A0* h = (Hdr_001160A0*)p;
    p += sizeof(Hdr_001160A0);
    m_scale = h->m_scale;
    m_flags = h->m_flags;
    if (h->m_flags & 0x10000000) {
        r = func_00115A20(this, p, arg);
    } else if (h->m_flags & 0x800000) {
        r = func_00115848(this, p, arg);
    }
    m_ok = r;
    return r;
}
