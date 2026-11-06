extern "C" int func_00170680(void* o);
extern "C" void func_0014C1E0(void* self, int v);

struct Obj_0014C3C8 {
    char pad[0x290];
    void* m_290;
    void Update();
};

void Obj_0014C3C8::Update()
{
    func_0014C1E0(this, func_00170680(m_290));
}
