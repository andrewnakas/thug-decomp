extern "C" int func_002095C8(void* v);
extern "C" float func_00209608(void* v);
extern "C" void* func_0013D8A8(void* scene);
extern "C" void func_00137BE8(void* o, float f);
extern "C" void func_00136178(float f);

class Comp_0018DF70 {
public:
    char pad0[0x260];
    void* m_scene;

    void Apply(void* v);
};

void Comp_0018DF70::Apply(void* v)
{
    if (!func_002095C8(v)) {
        return;
    }
    void* o = func_0013D8A8(m_scene);
    if (o) {
        func_00137BE8(o, func_00209608(v));
    } else {
        func_00136178(func_00209608(v));
    }
}
