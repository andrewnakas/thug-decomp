struct Node_002C8C38 {
    char pad0[0x14];
    Node_002C8C38* m14;
};

struct Obj_002C8C38 {
    char pad0[0x68];
    Node_002C8C38* m68;
    int Count();
};

int Obj_002C8C38::Count()
{
    int n = 0;
    for (Node_002C8C38* p = m68; p; p = p->m14)
        n++;
    return n;
}
