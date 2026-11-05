struct Obj00170830 {
    char pad[0x1f];
    unsigned char m_val;
    unsigned char Get() const;
};

unsigned char Obj00170830::Get() const
{
    return m_val;
}
