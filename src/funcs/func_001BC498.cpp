struct Obj_001BC498 {
    char m_pad[0x28];
    void (*m_callback)(Obj_001BC498* self);
    void Call();
};

void Obj_001BC498::Call()
{
    m_callback(this);
}
