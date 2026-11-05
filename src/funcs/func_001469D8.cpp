struct Src_001469D8 {
    int m0[2];
    char* m_8;
};

struct Obj_001469D8 {
    int m0[9];
    Src_001469D8* m_24;
    char* Get();
};

char* Obj_001469D8::Get()
{
    return m_24->m_8 + 0x10;
}
