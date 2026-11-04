struct Obj_002AB8A0 {
    char m_pad[0x28];
    void (*m_callback)(Obj_002AB8A0* self);
    void Call();
};

void Obj_002AB8A0::Call()
{
    m_callback(this);
}
