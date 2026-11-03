struct Vec_002901A0 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};
struct Node_002901A0 { char pad[0x50]; Vec_002901A0 m50; };
extern void* D_0038FC78;
extern "C" Node_002901A0* func_0022DD38(void*);

struct Obj_002901A0 {
    char pad0[0xC];
    Node_002901A0* m_node;
    float DistSq();
};

float Obj_002901A0::DistSq()
{
    Node_002901A0* o = func_0022DD38(D_0038FC78);
    if (o && o != m_node) {
        Vec_002901A0 d;
        d.Set(o->m50.x - m_node->m50.x, o->m50.y - m_node->m50.y, o->m50.z - m_node->m50.z, o->m50.w - m_node->m50.w);
        return d.x * d.x + d.y * d.y + d.z * d.z;
    }
    return 28330837409792.0f;
}
