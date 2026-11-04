struct Obj_00183420 {
    int m_pad[7];
    void (*m_callback)(Obj_00183420* self);
    void Run();
};

void Obj_00183420::Run()
{
    m_callback(this);
}
