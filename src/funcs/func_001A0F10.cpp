struct Obj_001A0F10 {
    void Fn(unsigned int anim, float t);
};

extern "C" float func_001A0AB0(Obj_001A0F10* self, unsigned int anim);
extern "C" void func_001A0F78(Obj_001A0F10* self, unsigned int anim, int b, int c, float d, float e, float f, float g);

void Obj_001A0F10::Fn(unsigned int anim, float t)
{
    float len = func_001A0AB0(this, anim);
    func_001A0F78(this, anim, 0, 0, 0.0f, len, t, 1.0f);
}
