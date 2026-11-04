struct Node_00299A18 {
    char pad[0x10];
    float x, y, z;
    char pad2[0x2C - 0x1C];
    Node_00299A18* next;
};

struct Grp_00299A18 {
    int m0;
    Grp_00299A18* next;
};

extern "C" void* func_0029C530(int size);
extern "C" Grp_00299A18* func_00299540(void* mem);
extern "C" void func_002999D8(Grp_00299A18* g, Node_00299A18* n);

struct Obj_00299A18 {
    char pad[0xC];
    Node_00299A18* head;
    Grp_00299A18* Collect(Grp_00299A18* list, float maxX, float maxZ, float minX, float minZ);
};

Grp_00299A18* Obj_00299A18::Collect(Grp_00299A18* list, float maxX, float maxZ, float minX, float minZ)
{
    bool prev = false;
    Node_00299A18* pending = 0;
    for (Node_00299A18* n = head; n; n = n->next) {
        if (maxX < n->x && n->x < minX && maxZ < n->z && n->z < minZ) {
            if (prev) {
                if (pending) {
                    Grp_00299A18* g = func_00299540(func_0029C530(0x14));
                    g->next = list;
                    list = g;
                    func_002999D8(list, pending);
                    pending = 0;
                }
                func_002999D8(list, n);
            } else {
                pending = n;
            }
            prev = true;
        } else {
            pending = 0;
            prev = false;
        }
    }
    return list;
}
