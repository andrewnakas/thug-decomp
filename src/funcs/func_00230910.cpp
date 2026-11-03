struct Obj_00230910 {
    int m_pad[7];
    void (*m_callback)(Obj_00230910* self);
    void Run();
};

void Obj_00230910::Run()
{
    m_callback(this);
}
