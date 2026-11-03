struct Obj_00187418 {
    int m_pad[7];
    void (*m_callback)(Obj_00187418* self);
    void Run();
};

void Obj_00187418::Run()
{
    m_callback(this);
}
