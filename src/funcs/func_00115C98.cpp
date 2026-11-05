struct Fmt_00115C98 {
    int m0;
    unsigned int m_flags;
    int GetY(void* data, int i);
};

int Fmt_00115C98::GetY(void* data, int i)
{
    if (m_flags & 0x400000) {
        char* p = (char*)data;
        p += i * 4;
        return *(short*)(p + 2);
    }
    unsigned char* q = (unsigned char*)data;
    q += i * 2;
    return *(q + 1);
}
