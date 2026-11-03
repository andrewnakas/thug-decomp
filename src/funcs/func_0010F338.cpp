struct Obj_0010F338 {
    int m_pad[7];
    void (*m_callback)(Obj_0010F338* self);
    void Run();
};

void Obj_0010F338::Run()
{
    m_callback(this);
}
