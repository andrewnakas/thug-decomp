struct Stream_001107F8 {
    int m_fd;
    int m_pos;
    char pad[0xC80C - 8];
    int m_bufPos;
};

extern "C" void func_0010FE68();
extern "C" int func_0031EC88(int fd, int offset, int whence);

extern "C" int func_001107F8(Stream_001107F8* s, long offset, int whence)
{
    func_0010FE68();
    int pos = s->m_pos;
    int bufPos = s->m_bufPos;
    s->m_bufPos = 0xC800;
    int start = pos - bufPos;
    int restore = 0;
    if (bufPos == 0xC800) {
        restore = 1;
    }
    switch (whence) {
    case 1: {
        long target = pos + offset;
        if (target >= start && target < start + 0xC800) {
            s->m_bufPos = pos + (int)offset - start;
            s->m_pos += (int)offset;
            break;
        }
        s->m_pos = func_0031EC88(s->m_fd, pos + (int)offset, 0);
        break;
    }
    case 2:
        s->m_pos = func_0031EC88(s->m_fd, (int)offset, 2);
        break;
    case 0:
        s->m_pos = func_0031EC88(s->m_fd, (int)offset, 0);
        break;
    default:
        return -1;
    }
    if (restore) {
        s->m_bufPos = 0xC800;
    }
    if (s->m_pos == -1) {
        s->m_pos = pos;
        s->m_bufPos = 0xC800;
        return -1;
    }
    return 0;
}
