extern char D_0037C690[];

struct Data_002D8160 {
    char pad[0x38];
    int m38;
};

struct Node_002D8160 {
    int m0;
    Data_002D8160* data;
    int m8;
    Node_002D8160* next;
    Data_002D8160* GetData() { return data; }
    Node_002D8160* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002D8160 {
    int m0;
    Node_002D8160* cur;
    void* vt;
    It_002D8160() { vt = D_0037C690; cur = 0; }
    ~It_002D8160() { vt = D_0037C690; }
    Data_002D8160* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D8160* First(Node_002D8160* h) {
        cur = h;
        return Next();
    }
};

struct Obj_002D8160 {
    char pad[0x14];
    Node_002D8160 m14;
    bool Has(int id);
};

bool Obj_002D8160::Has(int id)
{
    It_002D8160 it;
    for (Data_002D8160* d = it.First(&m14); d; d = it.Next()) {
        if (d->m38 == id) return true;
    }
    return false;
}
