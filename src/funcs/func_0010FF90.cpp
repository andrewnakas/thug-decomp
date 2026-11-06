struct Handle_0010FF90 {
    int m_start;
    int m_size;
};

struct Stream_0010FF90 {
    int m_pos;
    int m_4;
    int m_size;
    char pad[0xC80C - 0xC];
    int m_bufSize;
    int padC810[2];
    int m_start;
    const char* m_name;
};

extern "C" Handle_0010FF90* func_00112618(const char*, int);
extern "C" Stream_0010FF90* func_0010FC90();
extern "C" int func_0010FD88(const char*);
extern "C" void func_0010FD30(Stream_0010FF90*);
extern int D_00388E24;
extern int D_00388E20;

extern "C" Stream_0010FF90* func_0010FF90(const char* name, const char* mode)
{
    Handle_0010FF90* h = func_00112618(name, D_00388E24);
    if (!h)
        return 0;
    Stream_0010FF90* s = func_0010FC90();
    if (!s)
        return 0;
    if (!func_0010FD88(mode)) {
        func_0010FD30(s);
        return 0;
    }
    s->m_name = name;
    s->m_start = h->m_start;
    s->m_size = h->m_size;
    s->m_4 = 0;
    s->m_pos = 0;
    s->m_bufSize = 0xC800;
    D_00388E20++;
    return s;
}
