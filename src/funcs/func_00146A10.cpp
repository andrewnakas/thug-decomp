struct Obj00146A10 {
    char pad[0x70];
    int m_val;
    int* Get();
};

int* Obj00146A10::Get()
{
    return &m_val;
}
