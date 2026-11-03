struct Obj_001DC560 {
    char m_pad[0x14];
    int m_14;
    Obj_001DC560* Set(int v);
};

Obj_001DC560* Obj_001DC560::Set(int v)
{
    m_14 = v;
    return this;
}
