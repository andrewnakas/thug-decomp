struct Comp_00255968;

extern float D_00387DA8;

extern "C" Comp_00255968* func_00185578(void* obj, unsigned int type);
extern "C" bool func_001A0AD0(Comp_00255968* c, int anim);
extern "C" float func_001A0AB0(Comp_00255968* c, int anim);
extern "C" void func_001A0F78(Comp_00255968* c, int anim, int a, int b, float start, float end, float blend,
                              float speed);

void func_00255968(void* obj, int anim)
{
    if (!func_00185578(obj, 0x72AD7B23))
        return;
    if (!func_001A0AD0(func_00185578(obj, 0x72AD7B23), anim))
        return;
    Comp_00255968* c = func_00185578(obj, 0x72AD7B23);
    func_001A0F78(c, anim, 0, 1, 0.0f, func_001A0AB0(func_00185578(obj, 0x72AD7B23), anim), D_00387DA8, 1.0f);
}
