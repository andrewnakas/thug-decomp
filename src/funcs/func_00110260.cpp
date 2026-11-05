struct Buf_00110260 {
    int m0;
    int m_pos;
    int m_end;
};

int Write_00110260(void*, int size, int count, Buf_00110260* b)
{
    int p = b->m_pos + size * count;
    b->m_pos = p;
    b->m_end = p;
    return count;
}
