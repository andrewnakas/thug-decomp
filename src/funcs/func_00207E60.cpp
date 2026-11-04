struct Array_00207E60 {
    int m_pad[9];
    int m_count;
    int m_28;
    int* m_items;
    bool Remove(int v);
};

bool Array_00207E60::Remove(int v)
{
    for (int i = 0; i < m_count; i++) {
        if (m_items[i] == v) {
            for (int j = i + 1; j < m_count; j++)
                m_items[j - 1] = m_items[j];
            m_items[m_count - 1] = 0;
            return true;
        }
    }
    return false;
}
