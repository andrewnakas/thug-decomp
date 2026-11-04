struct Obj_001A4E90 {
    int m_pad[7];
    void (*m_callback)(Obj_001A4E90* self);
    void Run();
};

void Obj_001A4E90::Run()
{
    m_callback(this);
}
