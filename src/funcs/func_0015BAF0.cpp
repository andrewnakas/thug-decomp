extern "C" void func_0015B780(void* self);

struct Obj_0015BAF0 {
    char pad[0xE0];
    int m_E0;
    void Update();
};

void Obj_0015BAF0::Update()
{
    if (m_E0)
        func_0015B780(this);
}
