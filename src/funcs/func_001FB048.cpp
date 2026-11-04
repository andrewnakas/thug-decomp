typedef void (*Handler_001FB048)();

extern "C" void func_001FD3B0();
extern "C" void func_001FD058();
extern "C" void func_001FD0D8();
extern "C" void func_001FBF60(void* dispatcher, int id, Handler_001FB048 fn, int a, int b, int c);

struct Conn_001FB048 {
    int m_0;
    char m_dispatcher[0x1830];
    int m_1834;
    char pad1838[0x18];
    int m_1850;
};

extern "C" bool func_001FD510(Conn_001FB048* self);

bool func_001FB048(Conn_001FB048* self)
{
    self->m_0 = 0;
    self->m_1834 = 0;
    self->m_1850 = 0;
    if (!func_001FD510(self))
        return false;
    void* d = self->m_dispatcher;
    func_001FBF60(d, 3, func_001FD3B0, 3, 0, 0xFF);
    func_001FBF60(d, 9, func_001FD058, 3, 0, 0x80);
    func_001FBF60(d, 0xB, func_001FD0D8, 2, 0, 0xFF);
    return true;
}
