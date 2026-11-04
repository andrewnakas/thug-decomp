struct Obj_00265238 {
    char m_pad[0x1C];
    int m_1c;
    int m_20;
    int m_24;
    bool Reset();
};

bool Obj_00265238::Reset()
{
    m_1c = 0;
    m_20 = 0;
    m_24 = 0;
    return true;
}
