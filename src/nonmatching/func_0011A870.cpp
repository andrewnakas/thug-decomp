/* fuzzy: 54.8 */
class Node_0011A870 {
public:
    int m_0;
    int m_pri;
    int m_8;
    Node_0011A870* m_next;
    Node_0011A870* m_prev;
    virtual void V0();
    virtual int V1(int flag, float a, float b);

    Node_0011A870* Next()
    {
        Node_0011A870* n = m_next;
        if (n->m_pri == -1) {
            return 0;
        }
        return n;
    }
};

class Head_0011A870 : public Node_0011A870 {
public:
    Node_0011A870* First()
    {
        Node_0011A870* n = m_next;
        if (n->m_pri == -1) {
            return 0;
        }
        return n;
    }
    int Count()
    {
        int c = 0;
        Node_0011A870* n = First();
        while (n) {
            n = n->Next();
            c++;
        }
        return c;
    }
    Node_0011A870* GetItem(int index)
    {
        Node_0011A870* n = First();
        while (n) {
            if (index-- == 0) {
                return n;
            }
            n = n->Next();
        }
        return 0;
    }
};

struct Ctrl_0011A870 {
    char pad0[0x18];
    float m_18;
    char pad1C[0x28 - 0x1C];
    int m_28;
    char pad2C[0x64 - 0x2C];
    Head_0011A870 m_list;
};

extern "C" int func_0011A210(Ctrl_0011A870* self);
extern "C" void func_0011A7A0(Ctrl_0011A870* self);
extern "C" void* func_0011AB18(Ctrl_0011A870* self);
extern "C" void func_00118350(Node_0011A870* n, void* obj);

extern "C" void func_0011A870(Ctrl_0011A870* self, float a, float b)
{
    if (func_0011A210(self) != 2) {
        return;
    }
    a *= 60.0f;
    b *= 60.0f;
    bool reset;
    if (!self->m_28) {
        reset = b < a;
    } else {
        reset = a < b;
    }
    if (reset) {
        func_0011A7A0(self);
        a = self->m_18;
    }
    Head_0011A870* head = &self->m_list;
    int count = head->Count();
    for (int i = 0; i < count; i++) {
        Node_0011A870* n = head->GetItem(i);
        if (n->V1(0, a, b)) {
            func_00118350(n, func_0011AB18(self));
        }
    }
}
