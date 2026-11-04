struct Obj123A00 {
    char pad[0x180];
    float m180;
    float m184;
    void Get(float* a, float* b);
};

void Obj123A00::Get(float* a, float* b)
{
    *a = m180;
    *b = m184;
}
