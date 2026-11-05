/* sym: _vt$11It_001FE840 = 0x00366B58 */

struct It_001FE840 {
    void* m_cur;
    int m_4;

    It_001FE840() { m_4 = 0; }
    virtual void Reset();
    virtual ~It_001FE840() {}
};

struct Buf_001FE840 {
    char pad[0x54];
    char* m_start;
    char* m_end;
};

struct Conn_001FE840 {
    char pad0[0x60];
    char* m_write;
    char pad64[0x4928 - 0x64];
    Buf_001FE840* m_pending;
};

extern "C" Conn_001FE840* func_00200EC0(void* self, It_001FE840* it);
extern "C" Conn_001FE840* func_00200EF8(void* self, It_001FE840* it);
extern "C" int func_00202768(Conn_001FE840* c);
extern "C" void* func_00331404(void* dst, const void* src, int n);
extern "C" int func_001FC238(void* list, Conn_001FE840* c, int flags);
extern "C" void func_001FD9C8(void* self, Conn_001FE840* c);

struct Mgr_001FE840 {
    int m_0;
    char m_list[4];

    void Flush();
};

void Mgr_001FE840::Flush()
{
    It_001FE840 it;
    Conn_001FE840* c = func_00200EC0(this, &it);
    while (c) {
        Conn_001FE840* next = func_00200EF8(this, &it);
        if (func_00202768(c)) {
            Buf_001FE840* b = c->m_pending;
            if (b) {
                int n = b->m_end - b->m_start;
                func_00331404(c->m_write, b->m_start, n);
                c->m_pending->m_end = c->m_pending->m_start;
                c->m_write += n;
            }
        }
        int r = func_001FC238(m_list, c, 0);
        if (r != 0) {
            if (r == 2) {
                return;
            }
        }
        func_001FD9C8(this, c);
        c = next;
    }
}
