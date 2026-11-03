struct Obj_00255078 {
    int m_pad[7];
    void (*m_callback)(Obj_00255078* self);
    void Run();
};

void Obj_00255078::Run()
{
    m_callback(this);
}
