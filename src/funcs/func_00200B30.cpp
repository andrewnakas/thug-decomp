/* sym: _vt$11It_00200B30 = 0x00366B58 */

struct It_00200B30 {
    void* m_cur;
    int m_4;

    It_00200B30() { m_4 = 0; }
    virtual void Reset();
    virtual ~It_00200B30() {}
};

struct Conn_00200B30;
extern "C" Conn_00200B30* func_00200EC0(void* self, It_00200B30* it);
extern "C" void func_002006C8(void* self, Conn_00200B30* c, unsigned char a, unsigned short b, int c2, int d,
                              unsigned char e, int f, int g);

struct Mgr_00200B30 {
    int m_0;

    void SendFirst(unsigned char a, unsigned short b, int c, int d, unsigned char e, int f, int g);
};

void Mgr_00200B30::SendFirst(unsigned char a, unsigned short b, int c, int d, unsigned char e, int f, int g)
{
    It_00200B30 it;
    It_00200B30* p = &it;
    Conn_00200B30* conn = func_00200EC0(this, p);
    if (conn) {
        func_002006C8(this, conn, a, b, c, d, e, f, g);
    }
}
