struct Obj_001E17A0 {
    char pad[0x10];
    void* m10;
    float Get();
};
extern "C" int func_001E17D8(void* p);

float Obj_001E17A0::Get()
{
    return (float)(func_001E17D8(m10) * 100) * 2.0833333e-05f;
}
