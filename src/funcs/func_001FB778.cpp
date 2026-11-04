typedef void (*Handler_001FB778)();

extern "C" void func_001FD380();
extern "C" void func_001FD388();
extern "C" void func_001FD158();
extern "C" void func_001FBF60(void* dispatcher, int id, Handler_001FB778 fn, int a, int b, int c);

struct Conn_001FB778 {
    int m_0;
    char m_dispatcher[0x1830];
    int m_1834;
};

extern "C" bool func_001FD510(Conn_001FB778* self);

bool func_001FB778(Conn_001FB778* self)
{
    self->m_1834 = 0;
    self->m_0 = 0;
    if (!func_001FD510(self))
        return false;
    void* d = self->m_dispatcher;
    func_001FBF60(d, 4, func_001FD380, 3, 0, 0x80);
    func_001FBF60(d, 5, func_001FD388, 2, 0, 0x80);
    func_001FBF60(d, 6, func_001FD388, 2, 0, 0x80);
    func_001FBF60(d, 9, func_001FD158, 3, 0, 0x80);
    return true;
}
