struct Obj_0022C048 {
    char m_pad[0x28];
    void (*m_callback)(Obj_0022C048* self);
    void Call();
};

void Obj_0022C048::Call()
{
    m_callback(this);
}
