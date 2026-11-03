struct Item_00108708 {
    int m_packed;
    char* m_data;
    char* m_unpacked;
    int m_pos;
    int m_size;
};

struct Archive_00108708 {
    int m0;
    void* m_header;
    int m_count;
    void* m_table;
    Item_00108708* m_cur;
    int Seek(long offset, int whence);
};

int Archive_00108708::Seek(long offset, int whence)
{
    Item_00108708* cur = m_cur;
    int old = cur->m_pos;
    switch (whence) {
    case 1:
        cur->m_pos = old + offset;
        break;
    case 2:
        cur->m_pos = cur->m_size - offset;
        break;
    case 0:
        cur->m_pos = offset;
        break;
    default:
        return -1;
    }
    if (m_cur->m_pos < 0 || m_cur->m_pos > m_cur->m_size) {
        m_cur->m_pos = old;
        return -1;
    }
    return 0;
}
