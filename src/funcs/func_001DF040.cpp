extern "C" int func_001DED40(void* self);
extern "C" int func_001DEDE0(void* self, int a);
extern "C" void func_001E3548(int h, float x, float y);

extern "C" bool func_001DF040(void* self, float* pos)
{
    if (!func_001DED40(self)) {
        int h = func_001DEDE0(self, 1);
        if (h < 0)
            return false;
        func_001E3548(h, pos[0], pos[1]);
    }
    return true;
}
