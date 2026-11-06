extern char D_0037BD78[];

struct Data_002D2EB8;

struct Node_002D2EB8 {
    int m0;
    Data_002D2EB8* data;
    int m8;
    Node_002D2EB8* next;
    Data_002D2EB8* GetData() { return data; }
    Node_002D2EB8* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }
};

struct It_002D2EB8 {
    int m0;
    Node_002D2EB8* cur;
    void* vt;
    It_002D2EB8() { vt = D_0037BD78; cur = 0; }
    ~It_002D2EB8() { vt = D_0037BD78; }
    Data_002D2EB8* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D2EB8* Advance(Node_002D2EB8* c) {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D2EB8* First(Node_002D2EB8* h) {
        cur = h;
        return Next();
    }
};

extern char D_0037BBC8[];
extern char D_0037BCC0[];
struct List_002D2EB8;
extern "C" void func_001F0370(char* s, int a, int b, int c);
extern "C" int func_002CFF98(List_002D2EB8* l, Data_002D2EB8* d, int i);

struct List_002D2EB8 : Node_002D2EB8 {
    void Dump();
};

void List_002D2EB8::Dump()
{
    It_002D2EB8 it;
    int n = 0;
    func_001F0370(D_0037BBC8, 0, 0, 0);
    func_001F0370(D_0037BCC0, 0, 0, 0);
    Data_002D2EB8* d = it.First(this);
    if (d) {
        It_002D2EB8* p = &it;
        do {
            func_002CFF98(this, d, n);
            n++;
            d = p->Advance(it.cur);
        } while (d);
    }
}
