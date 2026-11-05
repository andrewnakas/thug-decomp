struct Obj_001EF078 {
    char pad[0x10];
    int m10;
    void* m14;
    int m18;
    void Update();
};
extern "C" void func_001E6B30(void* p);
extern "C" int func_001ED6B8(void* p, int a, int b);

void Obj_001EF078::Update()
{
    func_001E6B30(m14);
    m10 = func_001ED6B8(m14, m10, m18);
}
