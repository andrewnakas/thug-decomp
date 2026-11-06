extern "C" int func_001E8708(void* p);
struct Obj_001840C8 {
    char pad[0x24];
    void* m24;
    int Run();
};

int Obj_001840C8::Run()
{
    if (m24) {
        return func_001E8708(m24);
    }
    return 0;
}
