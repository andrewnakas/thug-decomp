struct Obj_00187C50 {
    int m_pad[7];
    void (*m_callback)(Obj_00187C50* self);
    void Run();
};

void Obj_00187C50::Run()
{
    m_callback(this);
}
