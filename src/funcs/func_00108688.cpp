struct Obj108688 {
    char pad[0x14];
    int m_count;
    void CountIf(int cond);
};

void Obj108688::CountIf(int cond)
{
    if (cond) {
        m_count++;
    }
}
