struct Obj_002CBCB8 {
    char m_pad[0x28];
    void (*m_callback)(Obj_002CBCB8* self);
    void Call();
};

void Obj_002CBCB8::Call()
{
    m_callback(this);
}
