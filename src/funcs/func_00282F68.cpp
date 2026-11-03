typedef int qword __attribute__((mode(TI)));
union Vec_00282F68 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Node_00282F68 { char pad[0x90]; Vec_00282F68 m90; };
extern "C" float sqrtf(float);

struct Obj_00282F68 {
    char pad[0xC];
    Node_00282F68* m_node;
    void Align(Vec_00282F68* v);
};

void Obj_00282F68::Align(Vec_00282F68* v)
{
    float len = sqrtf(v->f.x * v->f.x + v->f.y * v->f.y + v->f.z * v->f.z);
    if (len > 0.00001f) {
        float inv = 1.0f / len;
        float s = 1.0f;
        v->f.x *= inv;
        v->f.y *= inv;
        v->f.z *= inv;
        v->f.w *= inv;
        Node_00282F68* n = m_node;
        if (v->f.x * n->m90.f.x + v->f.y * n->m90.f.y + v->f.z * n->m90.f.z < 0.0f) {
            s = -1.0f;
        }
        *v = n->m90;
        float k = len * s;
        v->f.x *= k;
        v->f.y *= k;
        v->f.z *= k;
        v->f.w *= k;
    }
}
