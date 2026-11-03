struct Obj_00114968 {
    int m_pad[7];
    void (*m_callback)(Obj_00114968* self);
    void Run();
};

void Obj_00114968::Run()
{
    m_callback(this);
}
