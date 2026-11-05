struct Entry_001ED9D8 {
    int m_key;
    int m_val;
    Entry_001ED9D8* m_next;
};

extern Entry_001ED9D8* D_0038E6F8;

extern "C" int func_001ED9D8(int key)
{
    Entry_001ED9D8* e = &D_0038E6F8[key & 0xFFF];
    while (e) {
        if (e->m_key == key)
            return e->m_val;
        e = e->m_next;
    }
    return 0;
}
