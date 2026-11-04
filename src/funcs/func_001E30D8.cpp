struct Card_001E30D8 {
    int m_port;
    int m_state;
    int m_status;
    void* m_buffer;
};

extern int D_0038E280;

extern "C" int func_001E3C08();
extern "C" int func_001E3C58(int port);
extern "C" int func_001E28F8(int cmd, int port, int a, int b);
extern "C" void func_0010ECF8(void* p);
extern "C" void func_001E3308();

bool Card_001E30D8_Reset(Card_001E30D8* self)
{
    int r;
    if (self->m_port == 0) {
        r = func_001E3C08();
    } else {
        r = func_001E3C58(self->m_port - 1);
    }
    if (r == 2) {
        if (self->m_port == 0) {
            func_001E28F8(0x30, 0, 0, 0);
        } else {
            func_001E28F8(0x70, self->m_port - 1, 0, 0);
        }
    }
    if (self->m_buffer) {
        self->m_state = 3;
        func_0010ECF8(self->m_buffer);
        self->m_buffer = 0;
    }
    func_001E3308();
    int s = self->m_port;
    self->m_status = 6;
    D_0038E280 &= ~((1 << s) | (0x10 << s) | (0x10000 << s) | (0x100 << s) | (0x1000 << s));
    return true;
}
