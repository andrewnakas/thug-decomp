struct File_00110768 {
    int m_fd;
    int m_pos;
    int m_size;
};

extern "C" int func_0031F120(int fd, void* buf, int n);

extern "C" unsigned int func_00110768(void* buf, unsigned int size, unsigned int count, File_00110768* f)
{
    int n = func_0031F120(f->m_fd, buf, size * count);
    if (n == -1) {
        return 0;
    }
    f->m_pos += n;
    if (f->m_size < f->m_pos) {
        f->m_size = f->m_pos;
    }
    if (size == 0) {
        return 0;
    }
    return n / size;
}
