struct Node_001EC688 {
    int m0;
    int m_owner;
    int m_name;
    unsigned short m_type;
    short m_pad;
    int m_id;
    char m_pad14[0x48];
    Node_001EC688* m_next;
};

extern Node_001EC688* D_0038E6DC;
extern "C" int func_001EE408();

extern "C" Node_001EC688* func_001EC688(int name, int id, int type)
{
    int owner = func_001EE408();
    for (Node_001EC688* p = D_0038E6DC; p; p = p->m_next) {
        if (p->m_name == name && p->m_id == id && p->m_type == type) {
            if (p->m_owner == owner || p->m_owner == 0)
                return p;
        }
    }
    return 0;
}
