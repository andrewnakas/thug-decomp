struct Obj_0019FB18 {
    char pad0[0x44];
    int m44;
    void Fn(int v);
};

extern "C" void func_001A0F78(Obj_0019FB18* self, int a, int b, int c, float d, float e, float f, float g);

void Obj_0019FB18::Fn(int v)
{
    m44 = v;
    func_001A0F78(this, 0, 0, 0, 0.0f, 1000.0f, 0.3f, 1.0f);
}
