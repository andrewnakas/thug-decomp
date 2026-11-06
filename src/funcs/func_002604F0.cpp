struct Obj_002604F0 {
    char m_pad[0x28];
    void (*m_callback)(Obj_002604F0* self);
    void Call();
};

void Obj_002604F0::Call()
{
    m_callback(this);
}
