struct Obj_00114130 {
    int m_pad[7];
    void (*m_callback)(Obj_00114130* self);
    void Run();
};

void Obj_00114130::Run()
{
    m_callback(this);
}
