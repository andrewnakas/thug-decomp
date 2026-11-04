struct Obj_00107580 {
    int m_pad[7];
    void (*m_callback)(Obj_00107580* self);
    void Run();
};

void Obj_00107580::Run()
{
    m_callback(this);
}
