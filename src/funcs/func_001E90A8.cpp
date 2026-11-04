struct Slots_001E90A8 {
    int m0;
    union {
        int m_one;
        int* m_many;
    };
    int m8;
    int m_count;
    void Set(int index, int value);
};

void Slots_001E90A8::Set(int index, int value)
{
    if (m_count == 1)
        m_one = value;
    else
        m_many[index] = value;
}
