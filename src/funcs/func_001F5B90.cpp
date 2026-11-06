struct Sema_001F5B90 {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    unsigned int attr;
    unsigned int option;
};
extern "C" int func_0031BCA0(Sema_001F5B90* p);

struct Obj_001F5B90 {
    int m0;
    unsigned int m_buf;
    int m_size;
    char padC[0x18 - 0xC];
    int m_bytes;
    char pad1C[0x40 - 0x1C];
    int m_sema;
    int pad44;
    long m48;
    int m50;
    int m54;
    int Init(int a, unsigned int buf, int size, int c, int d);
};
extern "C" int func_001F5C08(Obj_001F5B90* self);

int Obj_001F5B90::Init(int a, unsigned int buf, int size, int c, int d)
{
    Sema_001F5B90 sp;
    m0 = a;
    m_buf = (buf & 0x0FFFFFFF) | 0x20000000;
    m_size = size;
    m_bytes = size << 11;
    m50 = c;
    m54 = d;
    sp.init_count = 1;
    sp.max_count = 1;
    m_sema = func_0031BCA0(&sp);
    func_001F5C08(this);
    m48 = 0;
    return 1;
}
