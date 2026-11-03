typedef int qword __attribute__((mode(TI)));
union Vec_00283050 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Node_00283050 { char pad[0x50]; Vec_00283050 m50; };
extern "C" float func_002032A0(unsigned int, int);

struct Obj_00283050;
extern "C" int func_00283100(Obj_00283050*, float, float);
struct Obj_00283050 {
    char pad[0xC];
    Node_00283050* m_node;
    void Update();
};

void Obj_00283050::Update()
{
    Vec_00283050 saved = m_node->m50;
    float f = func_002032A0(0x406B425F, 0);
    float a;
    if (func_00283100(this, -1.0f, f)) {
        a = 1.0f;
    } else {
        if (!func_00283100(this, 1.0f, f)) return;
        a = -1.0f;
    }
    if (func_00283100(this, a, f)) m_node->m50 = saved;
}
