struct Node_002C8CA0 {
    char pad[0x14];
    Node_002C8CA0* m14;
};

struct Obj_002C8CA0 {
    char pad[0x68];
    Node_002C8CA0* m68;
    Node_002C8CA0* Get(int idx);
};

Node_002C8CA0* Obj_002C8CA0::Get(int idx)
{
    Node_002C8CA0* n = m68;
    int i = 0;
    if (idx > 0) {
    next:
        if (n) {
            i++;
            n = n->m14;
            if (i < idx)
                goto next;
        }
    }
    return n;
}
