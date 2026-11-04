struct Obj_00252160 {
    int m_0;
    int m_4;
    int m_count;
    bool IsNext(int n);
};

bool Obj_00252160::IsNext(int n)
{
    return n == m_count + 1;
}
