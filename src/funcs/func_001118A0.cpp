struct Stream_001118A0 {
    char pad0[0x14];
    int m_14;
    char pad18[0x1C - 0x18];
    volatile int m_1C;
    char pad20[0x28 - 0x20];
    volatile int m_28;
    volatile int m_2C;
    char pad30[4];
    volatile int m_34;
    int Bump() { return ++m_34; }
    char pad38[0x3C - 0x38];
    volatile int m_3C;
    char pad40[0x144 - 0x40];
    int m_144;
    int m_148;
    int m_14C;
};

struct Request_001118A0 {
    char pad0[0x10];
    int m_10;
    int m_buf;
    int m_size;
    short m_head;
    short m_tail;
    char pad20[0x6C - 0x20];
    int m_6C;
};

extern volatile int D_00388C90;
extern "C" int func_00111EE8(int size);
extern "C" int func_0031BF20(int);
extern "C" int func_00112238(Request_001118A0* req, Stream_001118A0* s, int, int);
extern "C" int func_0010E4B0(Stream_001118A0* s);

extern "C" int func_001118A0(Stream_001118A0* s, int buf, int size, int count)
{
    Request_001118A0 req;
    int head = 0;
    int tail = 0;
    if (s->m_14 == 0) {
        bool misaligned = (buf & 0xF) != 0;
        int a = buf & 0x3F;
        int pad = a;
        if (a != 0) {
            pad = 0x40 - a;
        }
        if (misaligned || (pad != 0 && (unsigned int)(size * count) < 0x4000)) {
            s->m_144 = buf;
            int p = func_00111EE8((size * count + 0x7E) & 0xFFFFFFC0);
            s->m_14C = p;
            buf = s->m_148 = (p + 0x3F) & 0xFFFFFFC0;
        } else {
            head = a;
            if (head != 0) {
                head = 0x40 - head;
            }
            tail = (size * count - head) & 0x3F;
        }
    }
    req.m_6C = 3;
    req.m_10 = s->m_3C;
    req.m_buf = buf;
    req.m_size = size * count;
    req.m_head = head;
    req.m_tail = tail;
    D_00388C90++;
    s->Bump();
    func_0031BF20(0);
    func_00112238(&req, s, 1, -1);
    if (s->m_1C) {
        return func_0010E4B0(s);
    }
    return 0;
}
