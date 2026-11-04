struct Obj_00255050 {
    char m_pad[0x28];
    void (*m_callback)(Obj_00255050* self);
    void Call();
};

void Obj_00255050::Call()
{
    m_callback(this);
}
