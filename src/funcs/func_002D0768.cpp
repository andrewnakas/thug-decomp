extern char D_0037BDC0[];
extern char D_0037B748[];
extern char D_0037B770[];

struct Data_002D0768 {
    char pad[0x60];
    int m60;
};

struct Node_002D0768 {
    int m0;
    Data_002D0768* data;
    int m8;
    Node_002D0768* next;
    Data_002D0768* GetData() { return data; }
    Node_002D0768* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002D0768 {
    int m0;
    Node_002D0768* cur;
    void* vt;
    It_002D0768() { vt = D_0037BDC0; cur = 0; }
    ~It_002D0768() { vt = D_0037BDC0; }
    Data_002D0768* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D0768* First(Node_002D0768* head) {
        cur = head;
        return Next();
    }
};

struct Obj_002D0768;
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" void func_002D0198(Obj_002D0768* o, Data_002D0768* d);

struct Obj_002D0768 {
    char pad[0x18];
    Node_002D0768 m18;
    void UpdateAll();
};

void Obj_002D0768::UpdateAll()
{
    It_002D0768 it;
    func_001F0370(D_0037B748, 0, 0, 0);
    for (Data_002D0768* d = it.First(&m18); d; d = it.Next()) {
        if (d->m60) func_002D0198(this, d);
    }
    func_001F0370(D_0037B770, 0, 0, 0);
}
