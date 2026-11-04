struct Node_0028DF70 {
    char pad0[0x54];
    Node_0028DF70* next;
    int pad58;
    short idx;
};

struct Holder_0028DF70 {
    char pad0[0x58];
    void* arr;
};

struct Timer_0028DF70 {
    int pad0;
    int state;
    unsigned int time;
};

struct Ref_0028DF70 {
    int count;
};

extern "C" void* func_001E9378(void* a, int i);
extern "C" int func_001E8398(void* params, unsigned int name, int* out, int req);
extern "C" void* func_001E55B8(unsigned int id, int v);
extern "C" unsigned int func_0010FC30();
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_001BB2E8(void* a, int b, int c, void* d, int e);
extern void* D_00388A70;

struct Slot_0028DF70 {
    char pad0[0x1C];
    Ref_0028DF70* ref;
    unsigned int time;
    bool Valid()
    {
        if (ref == 0) return false;
        if (ref->count != 0) return true;
        func_0010A8D8(D_00388A70, ref);
        ref = 0;
        time = func_0010FC30();
        return false;
    }
};

struct Obj_0028DF70 {
    char pad0[0x29C];
    Node_0028DF70* first;
    Holder_0028DF70* holder;
    char pad2A4[0x2B0 - 0x2A4];
    int cur;
    int last;
    char pad2B8[0x598 - 0x2B8];
    void* target;
    char pad59C[0x5B0 - 0x59C];
    char* timers;
    Slot_0028DF70* slot;
    void Update(int a);
};

static inline void SetState_0028DF70(Timer_0028DF70* t, int s)
{
    if (t->state != s) {
        t->state = s;
        t->time = func_0010FC30();
    }
}

void Obj_0028DF70::Update(int a)
{
    Node_0028DF70* p = first;
    if (!p) return;
    void* arr = holder->arr;
    Node_0028DF70* node = p;
    Node_0028DF70* start = p;
    if (!arr) return;
    void* params = func_001E9378(arr, node->idx);
    int found = 0;
    if (!func_001E8398(params, 0x2CA8A299, &found, 0)) {
        Node_0028DF70* slow = node;
        int odd = 0;
        node = node->next;
        while (node && node != start && node != slow) {
            params = func_001E9378(arr, node->idx);
            if (func_001E8398(params, 0x2CA8A299, &found, 0)) break;
            node = node->next;
            if (odd) slow = slow->next;
            odd ^= 1;
        }
    }
    if (!found) return;
    int v;
    func_001E8398(params, 0xA1DC81F9, &v, 1);
    if (v != last) {
        SetState_0028DF70((Timer_0028DF70*)(timers + 0x120), 1);
    } else {
        SetState_0028DF70((Timer_0028DF70*)(timers + 0x120), 0);
    }
    cur = v;
    last = v;
    if (arr == func_001E55B8(0xC472ECC5, 0)) arr = 0;
    func_001BB2E8(target, a, cur, arr, slot->Valid() ? slot->ref->count : 0);
}
