extern "C" int func_001E5548(unsigned int checksum, int create);
extern "C" void func_001E7EB0(int obj, int key, float* out, int count);

float func_001CF8E0(int unused, int key)
{
    float f;
    func_001E7EB0(func_001E5548(0x38EC37AC, 1), key, &f, 1);
    return f;
}
