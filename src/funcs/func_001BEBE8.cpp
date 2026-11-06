extern "C" void* func_00185578(void* p, unsigned int id);
struct Obj_001BEBE8 {
    char pad[0xA14];
    void* mA14;
    void* mA18;
    void Init(void* p);
};

void Obj_001BEBE8::Init(void* p)
{
    mA14 = p;
    mA18 = func_00185578(p, 0xC7D37EC2);
}
