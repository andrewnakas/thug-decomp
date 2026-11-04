extern "C" void func_0024A860(void* self);

struct Obj_0024A688 {
    int m_pad[51];
    int m_cc;
    int m_d0;
    bool Reset();
};

bool Obj_0024A688::Reset()
{
    func_0024A860(this);
    m_d0 = 0;
    m_cc = 0;
    return true;
}
