struct Vec_00258098 {
    float x, y, z, w;
    Vec_00258098() {}
    Vec_00258098(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Obj_00258098 {
    char m_pad[0x50];
    Vec_00258098 m_pos;
    char m_pad60[0x70 - 0x60];
    char m_matrix[0x40];
};

extern "C" float fabsf(float);
extern "C" int func_00256C08(Obj_00258098* self, void* params, void* script);
extern "C" Obj_00258098* func_002582E0(Obj_00258098* self, int a);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" float func_00101A10(void* matrix, Vec_00258098* v, int a, int b);
extern "C" int func_00257E68(Obj_00258098* self, void* params, void* script, int a);
extern "C" bool func_00257B00(Obj_00258098* self, void* params, void* script);
extern "C" bool func_001E89F0(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_00256BD8(Obj_00258098* self);
extern "C" void* func_00256BA0(Obj_00258098* self);
extern "C" void func_0011DE78(void* model, unsigned int name);
extern "C" bool func_00131288(Vec_00258098* color, unsigned int name);
extern "C" void func_0013EDD0(void* model, Vec_00258098* color);
extern "C" int func_001855A8(Obj_00258098* self, unsigned int msg, void* params, void* script);

int func_00258098(Obj_00258098* self, unsigned int msg, void* params, void* script)
{
    switch (msg) {
    case 0x33E04032:
        return func_00256C08(self, params, script);
    case 0x37185D8A: {
        Obj_00258098* other = func_002582E0(self, 1);
        if (other) {
            float angle;
            func_001E7EB0(params, 0, &angle, 1);
            angle *= 0.01745329425f;
            Vec_00258098 d(other->m_pos.x - self->m_pos.x, other->m_pos.y - self->m_pos.y,
                           other->m_pos.z - self->m_pos.z, other->m_pos.w - self->m_pos.w);
            if (angle < fabsf(func_00101A10(self->m_matrix, &d, 2, 1))) {
                return 1;
            }
        }
        return 0;
    }
    case 0x67660FE5:
        return func_00257E68(self, params, script, 0);
    case 0x6520B902:
        return func_00257B00(self, params, script);
    case 0x3B6B66C3:
        return !func_00257B00(self, params, script);
    case 0x802A7600: {
        unsigned int name;
        func_001E89F0(params, 0x812684EF, &name, 1);
        if (func_00256BD8(self)) {
            func_0011DE78(func_00256BA0(self), name);
            Vec_00258098 color(1.0f, 1.0f, 1.0f, 1.0f);
            if (func_00131288(&color, name)) {
                func_0013EDD0(func_00256BD8(self), &color);
            }
        }
        break;
    }
    default:
        return func_001855A8(self, msg, params, script);
    }
    return 1;
}
