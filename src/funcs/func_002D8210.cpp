struct Node_002D8210 {
    int m0;
    void* data;
    int m8;
    Node_002D8210* next;
    Node_002D8210* Valid() { return (int)data != -1 ? this : 0; }
};

struct Obj_002D8210 {
    char pad[0x20];
    Node_002D8210* m20;
    int Count();
};

int Obj_002D8210::Count()
{
    int n = 0;
    for (Node_002D8210* p = m20->Valid(); p; p = p->next->Valid())
        n++;
    return n;
}
