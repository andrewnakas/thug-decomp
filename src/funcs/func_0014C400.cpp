extern "C" int func_00170680(void* o);
extern "C" void func_0014C2D8(void* self, int v);

struct Obj_0014C400 {
    char pad[0x298];
    void* m_298;
    void Update();
};

void Obj_0014C400::Update()
{
    func_0014C2D8(this, func_00170680(m_298));
}
