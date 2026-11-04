struct Node_00106D10 {
    int m0;
    unsigned int m4;
    int m8;
    Node_00106D10* m_next;
    Node_00106D10* m_prev;
    void* m_vt;
    void Init(void* vt)
    {
        m4 = 0xFFFFFFFF;
        m_vt = vt;
        m_next = this;
        m_prev = this;
        m8 = 0;
    }
    void AddTail(Node_00106D10* node)
    {
        node->m_prev = m_prev;
        node->m_next = this;
        m_prev->m_next = node;
        m_prev = node;
    }
};

struct Item_00106D10 {
    int m0;
    Node_00106D10* m_node;
};

struct Task_00106D10 {
    char pad[0x18];
    void* m_vt;
    void* m_func;
    void* m_data;
    void Init(void* f, void* d);
};

struct Obj_00106D10 {
    int m0;
    Node_00106D10 m_list;
    Task_00106D10* m_task;
    void* m_vt;
};

extern char D_0035AE50[];
extern char D_0035AE68[];
extern char D_0035AE98[];
extern char D_0035AE28[];
extern char D_00388958[];
extern char D_00388960[];
extern char D_00388968[];
extern char D_00388970[];
extern char D_00388978[];
extern char D_00388980[];
extern char D_00388988[];
extern char D_00388990[];
extern char D_00388998[];
extern char D_003889A0[];
extern char D_003889A8[];
extern char D_0034D680[];
extern int D_0038881C;

extern "C" void func_0031D560(int);
extern "C" void func_00106B98(const char* name, int n, const char* arg, int flag);
extern "C" int func_001DC418();
extern "C" int func_001DED20();
extern "C" int func_001DED40();
extern "C" void func_0010EC28();
extern "C" void func_00113D48();
extern "C" void func_0031F678();
extern "C" void func_00319F08(int);
extern "C" Task_00106D10* func_001046B0(int size);
extern "C" Task_00106D10* func_001047F8(Task_00106D10* t, int);
extern "C" void func_00106A90();
extern "C" int func_0031ACF8(int port);
extern "C" Item_00106D10* func_00106B40(Obj_00106D10* self, int index, int port, int slot);
extern "C" void func_00107BF0(Item_00106D10* item);
extern "C" void func_001E2150();
extern "C" void func_001DFC38();
extern "C" void func_00110D48();

inline void Task_00106D10::Init(void* f, void* d)
{
    func_001047F8(this, 0);
    m_func = f;
    m_data = d;
    m_vt = D_0035AE98;
}

extern "C" Obj_00106D10* func_00106D10(Obj_00106D10* self)
{
    self->m_vt = D_0035AE50;
    self->m_list.Init(D_0035AE68);
    func_0031D560(0);
    func_00106B98(D_00388958, 0, 0, 1);
    func_00106B98(D_00388960, 0, 0, 1);
    func_00106B98(D_00388968, 0, 0, 1);
    func_00106B98(D_00388970, 0, 0, 1);
    func_00106B98(D_00388978, 0, 0, 1);
    func_00106B98(D_0035AE28, 0, 0, 1);
    if (!func_001DC418() || !func_001DED20() || !func_001DED40()) {
        func_00106B98(D_00388980, 0, 0, 1);
        func_00106B98(D_00388988, 0, 0, 1);
    }
    func_00106B98(D_00388990, 0, 0, 1);
    func_0010EC28();
    if (!func_001DC418() || !func_001DED20() || !func_001DED40()) {
        func_00106B98(D_00388998, 0, 0, 1);
    }
    Node_00106D10* head = &self->m_list;
    func_00106B98(D_003889A0, 0, 0, 1);
    func_00106B98(D_003889A8, 0x15, D_0034D680, 1);
    int count = 0;
    func_00113D48();
    func_0031F678();
    func_00319F08(0);
    Task_00106D10* task = func_001046B0(0x24);
    task->Init((void*)func_00106A90, head);
    self->m_task = task;
    for (int port = 0; port < 2; port++) {
        for (int slot = 0; slot < func_0031ACF8(port); slot++) {
            Item_00106D10* item = func_00106B40(self, count, port, slot);
            if (item) {
                Node_00106D10* node = item->m_node;
                count++;
                self->m_list.AddTail(node);
                func_00107BF0(item);
            }
        }
    }
    if (!func_001DC418()) {
        func_001E2150();
    }
    if (!func_001DED20() || !func_001DED40()) {
        func_001DFC38();
    }
    if (D_0038881C) {
        func_00110D48();
    }
    return self;
}
