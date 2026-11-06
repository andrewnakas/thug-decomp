/* fuzzy: 43.5 */
struct Node_0029A7C0 {
    char pad[0x10];
    float x, y, z;
    char pad2[0x2C - 0x1C];
    Node_0029A7C0* next;
};

struct Grp_0029A7C0 {
    char pad[0xC];
    Node_0029A7C0* head;
};

struct Obj_0029A7C0;
extern "C" int func_0029A770(Obj_0029A7C0* o, Grp_0029A7C0* g, Node_0029A7C0* n);

struct Obj_0029A7C0 {
    bool Clip(Grp_0029A7C0* g, float x0, float z0, float x1, float z1, bool flag);
};

bool Obj_0029A7C0::Clip(Grp_0029A7C0* g, float x0, float z0, float x1, float z1, bool flag)
{
    Node_0029A7C0* next;
    for (Node_0029A7C0* n = g->head; n; n = next) {
        next = n->next;
        bool hit = !flag;
        if (x0 < n->x && n->x < x1 && z0 < n->z && n->z < z1)
            hit = flag;
        if (hit && func_0029A770(this, g, n))
            return true;
    }
    return false;
}
