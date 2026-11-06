class Obj_0017EBF8 {
public:
    int m_0;
    int m_flags;
    char pad[0x48];
    int m_count;
    void Bump();
};

void Obj_0017EBF8::Bump()
{
    m_count++;
    m_flags |= 2;
}
