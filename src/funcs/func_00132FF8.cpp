extern "C" unsigned int func_00134F08(void* o);
extern "C" void func_00134C20(void* table, unsigned int* id, void* o);

class Scene_00132FF8 {
public:
    char pad0[0xD0];
    void* m_table;
    void Add(void* o);
};

void Scene_00132FF8::Add(void* o)
{
    unsigned int id = func_00134F08(o);
    func_00134C20(m_table, &id, o);
}
