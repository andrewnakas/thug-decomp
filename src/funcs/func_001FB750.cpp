struct Obj_001FB750 {
    int m_pad[7];
    void (*m_callback)(Obj_001FB750* self);
    void Run();
};

void Obj_001FB750::Run()
{
    m_callback(this);
}
