struct Obj_0022C070 {
    int m_pad[7];
    void (*m_callback)(Obj_0022C070* self);
    void Run();
};

void Obj_0022C070::Run()
{
    m_callback(this);
}
