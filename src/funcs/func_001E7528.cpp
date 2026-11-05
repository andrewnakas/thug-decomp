struct Vec_001E7528 {
    float x;
    float y;
    float z;
};
extern "C" void func_001E7410(void* a, void* b, float x, float y, float z);

void Call_001E7528(void* a, void* b, Vec_001E7528* v)
{
    func_001E7410(a, b, v->x, v->y, v->z);
}
