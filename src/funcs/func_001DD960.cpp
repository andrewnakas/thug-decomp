struct Vec_001DD960 {
    float x, y, z;
};

extern "C" float func_003414F0(float y, float x);
extern "C" void func_001DD9B0(void* self, int a, float deg);

extern "C" void func_001DD960(void* self, const Vec_001DD960* v, int a)
{
    func_001DD9B0(self, a, func_003414F0(v->x, -v->z) * 57.29577637f);
}
