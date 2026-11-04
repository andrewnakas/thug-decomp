struct Obj_001AA390 {
    int m_pad[7];
    void (*m_callback)(Obj_001AA390* self);
    void Run();
};

void Obj_001AA390::Run()
{
    m_callback(this);
}
