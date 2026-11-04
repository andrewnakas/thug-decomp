struct Obj_00183070 {
    int m_pad[7];
    void (*m_callback)(Obj_00183070* self);
    void Run();
};

void Obj_00183070::Run()
{
    m_callback(this);
}
