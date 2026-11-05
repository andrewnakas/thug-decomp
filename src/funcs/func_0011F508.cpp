struct List_0011F508 {
    int m0;
    int m_count;
    int m_keys[64];
    int IndexOf(int key);
};

int List_0011F508::IndexOf(int key)
{
    for (int i = 0; i < m_count; i++) {
        if (key == m_keys[i])
            return i;
    }
    return 0;
}
