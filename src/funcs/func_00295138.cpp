extern "C" void* func_00292090(void* list, int i);
extern "C" void func_00295030(void* self, int i, void* item);

struct Obj_00295138 {
    char pad[0x2A1];
    unsigned char m2A1;
    char pad2A2[6];
    void* m2A8;
    void InitAll();
};

void Obj_00295138::InitAll()
{
    for (int i = 0; i < m2A1; i++)
        func_00295030(this, i, func_00292090(m2A8, i));
}
