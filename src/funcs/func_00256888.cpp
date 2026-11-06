struct Obj_00256888 {
    char m_pad[0x28];
    void (*m_callback)(Obj_00256888* self);
    void Call();
};

void Obj_00256888::Call()
{
    m_callback(this);
}
