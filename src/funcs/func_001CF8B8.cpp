extern "C" void func_001E7EB0(int obj, int key, float* out, int count);

struct Comp_001CF8B8 {
    char pad[0x1C];
    int m1C;
    float GetFloat(int key);
};

float Comp_001CF8B8::GetFloat(int key)
{
    float f;
    func_001E7EB0(m1C, key, &f, 1);
    return f;
}
