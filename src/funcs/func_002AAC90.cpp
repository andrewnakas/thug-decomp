struct Node_002AAC90 {
    int m0;
    void* data;
    int m8;
    Node_002AAC90* next;
    Node_002AAC90* Valid() { return (int)data != -1 ? this : 0; }
};

struct Sub_002AAC90 {
    char pad[0x24];
    Node_002AAC90* m24;
};

struct Net_002AAC90 {
    int m0;
    Sub_002AAC90* m4;
    char pad8[0x130 - 0x8];
    Node_002AAC90* m130;
};

struct Script_002AAC90 {
    char pad[0x18];
    void* m18;
};

extern Net_002AAC90* D_00392068;

extern "C" bool func_002AAC90()
{
    int n = 0;
    for (Node_002AAC90* p = D_00392068->m130->Valid(); p; p = p->next->Valid())
        n++;
    return n != 0;
}
