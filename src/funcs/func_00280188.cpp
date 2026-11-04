struct Vec_00280188 {
    float x, y, z, w;
};
struct Node_00280188 { char pad[0xB0]; Vec_00280188 pos; };
struct Ref_00280188 { Node_00280188* node; };
struct Tgt_00280188 { char pad[0x1C]; Ref_00280188* ref; };
struct Sub_00280188 { char pad[0xC4]; int busy; };
extern "C" int func_001CE768(Tgt_00280188* t, void* p);

struct Obj_00280188 {
    char pad0[0xC];
    Node_00280188* m_node;
    char pad1[0xB0 - 0x10];
    char m_b0[0x5B0 - 0xB0];
    Sub_00280188* m_sub;
    Tgt_00280188* m_tgt;
    void Update();
};

void Obj_00280188::Update()
{
    if (m_sub->busy) return;
    if (!func_001CE768(m_tgt, m_b0)) return;
    Node_00280188* n = m_tgt->ref->node;
    Vec_00280188& d = m_node->pos;
    d.x -= n->pos.x; d.y -= n->pos.y; d.z -= n->pos.z; d.w -= n->pos.w;
}
