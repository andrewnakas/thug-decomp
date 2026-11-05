extern "C" void func_00271560(void* self, int* mode, int* mask);
extern "C" void func_002710B8(void* self, int mode, int mask);

struct Obj_00271070 {
    char pad[0x4C];
    int m4C;
    void Update();
};

void Obj_00271070::Update()
{
    int mode;
    int mask;
    m4C++;
    func_00271560(this, &mode, &mask);
    func_002710B8(this, mode, mask);
}
