struct Slots_001E9350 {
    int m0;
    union {
        int m_one;
        int* m_many;
    };
    int m8;
    int m_count;
    void Set(int index, int value);
    int Get(int index);
};

int Slots_001E9350::Get(int index)
{
    if (m_count == 1)
        return m_one;
    return m_many[index];
}
